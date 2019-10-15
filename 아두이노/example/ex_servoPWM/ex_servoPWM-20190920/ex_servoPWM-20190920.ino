#include "servoPWM.h"

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
  
  servoSetting();
}



void loop() {
  
  addAngle_delay(3, -13, 700);
  addAngle_delay(5, -20, 700);
  delay(500);

  addAngle_delay(3, 13, 700);
  addAngle_delay(5, 20, 700);
  delay(500);
}
