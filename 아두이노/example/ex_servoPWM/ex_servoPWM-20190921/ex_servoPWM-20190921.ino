#include "servoPWM1.h"

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
  
  servoSetting();
  
  delay(1000);
}

boolean flag = true;

void loop() {
  //Serial.println(flag);
  
  if(flag == true) {
    boolean num = set_smoothServo(3, 1, 140, 1500, 3, 140, 1500, 5, 140, 1500);
    
    if(num == true) {
      //Serial.println("---------------------------");
      
      flag = false;
    }
  } else {
    boolean num = set_smoothServo(3, 1, 160, 1500, 3, 160, 1500, 5, 160, 1500);
    if(num == true) {
      //
      Serial.println("---------------------------");
      
      flag = true;
    }
  }
  
  //boolean num = set_smoothServo(3, 1, 140, 1500, 3, 140, 1500, 5, 140, 1500);
}
