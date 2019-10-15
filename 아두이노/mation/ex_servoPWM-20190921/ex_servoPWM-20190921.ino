#include "servoPWM1.h"

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
  
  servoSetting();
  
  delay(1000);
}

void loop() {
  set_smoothServo(3, 1, 145, 1500, 3, 145, 1500, 5, 145, 1500);
  set_smoothServo(3, 1, 160, 1500, 3, 160, 1500, 5, 160, 1500);
  

  /* 화들짝
  set_smoothServo(3, 1, 180, 0, 
                    3, 180, 0, 
                    5, 180, 0);
                    */
/*
  set_smoothServo(2, 0, 160, 1000, 
                    2, 20, 1000);
         */           
}
