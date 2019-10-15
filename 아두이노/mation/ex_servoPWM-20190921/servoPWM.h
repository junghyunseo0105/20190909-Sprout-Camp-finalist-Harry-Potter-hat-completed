#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

static float servo_angle[7] = { 180, 180, 0, 180, 180, 180, 0 };
                               //0    1    2  3    4    5   6
int min_angle[7] = { 0, 150, 0, 150, 0, 150, 0};
int max_angle[7] = {180, 180, 180, 180, 180, 180, 180,};

int getservo_angle(int pin) {
  return servo_angle[pin];
}

int getmin_angle(int pin) {
  return min_angle[pin];
}

int getmax_angle(int pin) {
  return max_angle[pin];
}

void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000000;  // convert to us
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void setAngle(int pin, float angle) {
  //Serial.print("angle "); Serial.println(angle);
  servo_angle[pin] = angle;
  angle = map(servo_angle[pin], 0, 180, 150, 600);
  pwm.setPWM(pin, 0, angle);

  //Serial.print("setAngle ");Serial.print(pin);Serial.print(" ");Serial.print(servo_angle[pin]);Serial.println();
}

void setAngle_delay(int pin, int angle, int timer) {
  int end_angle = abs( angle - servo_angle[pin] );
  timer /= end_angle;
  //Serial.print("servo_angle ");
  //Serial.println(servo_angle[pin]);
  //Serial.print("end_angle ");
  //Serial.println(end_angle);
  //Serial.print("timer ");
  //Serial.println(timer);
  
  int num = angle - servo_angle[pin];
  int flag = -1;

  if(num > 0)
    flag = 1;
  
  for(int i = 0; i < end_angle; i++) {
    servo_angle[pin] += flag;
    //Serial.println(servo_angle[pin]);
    setAngle(pin, servo_angle[pin]);
    delay(timer);
  }
}

void addAngle(int pin, int angle) {
  
  angle += servo_angle[pin];
  Serial.println(servo_angle[pin]);

  if(angle >= 0 && angle <= 180)
    setAngle(pin, angle);
}

void addAngle_delay(int pin, int angle, int timer) {
  
  angle += servo_angle[pin];
  Serial.println(servo_angle[pin]);

  if(angle >= min_angle[pin] && angle <= max_angle[pin])
    setAngle_delay(pin, angle, timer);
}

void servoSetting() {
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);
  
  for(int i = 0; i < 7; i++) {
    setAngle(i, servo_angle[i]);  
  }
}
