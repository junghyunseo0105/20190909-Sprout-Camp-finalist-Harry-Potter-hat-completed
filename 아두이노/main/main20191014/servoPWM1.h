struct Servo1 {
  int pin = -1;
  int angle;
  int duration;
  int systime;
  boolean flag = false;
  int a = 0;
};

Servo1 servo[7];

void reset_servo(int i, int angle, int pin) {
  servo_angle[pin] = angle;
  //Serial.println(servo[i].pin);
  //Serial.println(servo_angle[servo[i].pin]);
  servo[i].pin = -1;
  servo[i].flag = false;

}

int set_smoothServo(int args, ...) {
  int count = 0;

  va_list ap;
  va_start(ap, args * 3);
  for (int i = 0; i < args; i++)
  {
    /*
      Serial.print(i);
      Serial.print(" ");
      Serial.print(servo[i].pin);
      Serial.print(" ");
      Serial.print(servo[i].flag);
      Serial.println(" ");
    */
    if (servo[i].pin < 0 && servo[i].flag == false) {

      for (int l = 0; l < 3; l++) {
        int num = va_arg(ap, int);

        if (l == 0) {
          servo[i].pin = num;
          servo[i].a = servo_angle[num];
        }
        else if (l == 1) {
          servo[i].angle = num;
        }
        else if (l == 2) {
          servo[i].duration = num;
        }

        //Serial.print(num);
        //Serial.print(" ");
      }
      servo[i].systime = millis();
      servo[i].flag = true;
    }

    if (servo[i].flag == true) {
      int now = millis() - servo[i].systime;

      //int flag = 0;

      int pin = servo[i].pin;
      int current_angle = servo_angle[pin];
      float angle = servo[i].angle;
      int duration = servo[i].duration;

      float increase_angle = (float)( angle - current_angle ) / duration;

      int save_angle = current_angle + increase_angle * now;
      //-----------------------------------------------------------------
      if (increase_angle > 0) {
        if ((int)angle <= (int)(save_angle)) {
          current_angle = angle;
          int num = map(current_angle, 0, 180, 150, 600);
          pwm.setPWM(pin, 0, num);
          reset_servo(i, current_angle, pin);
          count++;
          continue;

        }
      } else {
        if ((int)angle >= (int)(save_angle)) {
          current_angle = angle;
          int num = map(current_angle, 0, 180, 150, 600);
          pwm.setPWM(pin, 0, num);
          reset_servo(i, current_angle, pin);
          count++;
          continue;

        }
      }
      //-----------------------------------------------------------
      if (increase_angle > 0) {
        int num = save_angle;
        num = map(num, 0, 180, 150, 600);
        //Serial.print(servo[i].a);
        //Serial.print(" ");
        //Serial.println(save_angle);
        if ((servo[i].a)  < save_angle) {
          servo[i].a = save_angle;
          pwm.setPWM(pin, 0, num);
          //Serial.print(pin);
          //Serial.print(" ");
          //Serial.println(save_angle);
        }
      } else {
        int num = save_angle;
        num = map(num, 0, 180, 150, 600);
        //Serial.print(servo[i].a);
        //Serial.print(" ");
        //Serial.println(save_angle);
        if ((servo[i].a) > save_angle) {
          servo[i].a = save_angle;
          pwm.setPWM(pin, 0, num);
          //Serial.print(pin);
          //Serial.print(" ");
          //Serial.println(save_angle);
        }
      }

    }


  }
  va_end(ap);

  //Serial.println(count);

  if (count >= args) {
    return true;
  }
  return false;

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
