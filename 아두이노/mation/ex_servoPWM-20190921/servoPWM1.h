#include "servoPWM.h"

struct Servo {
  int pin;
  int angle;
  int duration;
};

void set_smoothServo(int args, ...) {
  Servo servo[args];
  
  va_list ap;
  va_start(ap, args * 3);
  for (int i = 0; i < args; i++)
  {
    for(int l = 0; l < 3; l++) {
      int num = va_arg(ap, int);

      if(l == 0)
        servo[i].pin = num;
      else if(l == 1)
        servo[i].angle = num;
      else if(l == 2)
        servo[i].duration = num;

      //Serial.print(num);
      //Serial.print(" ");
    }
    //Serial.print(servo[i].pin);Serial.print(" "); Serial.print(servo[i].angle);Serial.print(" ");Serial.print(servo[i].duration);Serial.println();
  }
  va_end(ap);
  
  int systime = millis();
  
  while(true) {
    int now = millis() - systime;
    
    int flag = 0;
    for(int i = 0; i < args; i++) {
      int pin = servo[i].pin;
      float angle = servo[i].angle;
      int duration = servo[i].duration;
      
      float increase_angle = (float)( servo[i].angle - servo_angle[pin] ) / duration;

      if(increase_angle > 0) {
        if((int)angle <= (int)(servo_angle[pin] + increase_angle * now)) {
          servo_angle[pin] = angle;
          int num = map(servo_angle[pin], 0, 180, 150, 600);
          pwm.setPWM(pin, 0, num);
          flag++;
          continue;
        }
      } else {
        if((int)angle >= (int)(servo_angle[pin] + increase_angle * now)) {
          servo_angle[pin] = angle;
          int num = map(servo_angle[pin], 0, 180, 150, 600);
          pwm.setPWM(pin, 0, num);
          flag++;
          continue;
        }
      }
      int num = servo_angle[pin] + increase_angle * now;
      num = map(num, 0, 180, 150, 600);
      pwm.setPWM(pin, 0, num);
    }

    if(flag >= args) {
      for(int i = 0; i < args; i++) {
        int pin = servo[i].pin;
        float angle = servo[i].angle;
        servo_angle[pin] = angle;
        int num = map(servo_angle[pin], 0, 180, 150, 600);
        pwm.setPWM(pin, 0, num);
      }
      break;
    }
  }
}

void ex_printNumbers(int args, ...) {
  va_list ap;    // 가변 인자 목록 포인터

  va_start(ap, args);    // 가변 인자 목록 포인터 설정
  for (int i = 0; i < args; i++)    // 가변 인자 개수만큼 반복
  {
      int num = va_arg(ap, int);    // int 크기만큼 가변 인자 목록 포인터에서 값을 가져옴
                                      // ap를 int 크기만큼 순방향으로 이동
      Serial.print(num);           // 가변 인자 값 출력
  }
  va_end(ap);    // 가변 인자 목록 포인터를 NULL로 초기화

  Serial.println("\n");    // 줄바꿈
}
