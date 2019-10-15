#include "servoPWM.h"
#include "servoPWM1.h"

#include "motion_stop.h"
#include "motion_snoring.h"
#include "motion_talk.h"

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
  
  servoSetting();
  
  delay(1000);
}

void loop() {
  //motion_stop();
  //motion_snoring();
  motion_talk();
  //setAngle(2, 160);
  
}
