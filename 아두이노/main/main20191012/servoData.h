#include "servoPWM1.h"

void snoring() { //코골기
  set_smoothServo(3, 1, 145, 1500, 
                    3, 145, 1500, 
                    5, 145, 1500);
  set_smoothServo(3, 1, 160, 1500, 
                    3, 160, 1500, 
                    5, 160, 1500);

  Serial.println("helo");
}

void surprise() { //깜짝
  set_smoothServo(3, 1, 180, 0, 
                    3, 180, 0, 
                    5, 180, 0);
}
