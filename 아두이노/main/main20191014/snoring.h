#include "servoPWM1.h"
boolean snoring_flag = true;

void snoring() {
  
  if(snoring_flag) {
    boolean num = set_smoothServo(3, 1, 140, 1500, 3, 140, 1500, 5, 140, 1500);
    
    if(num) {
      snoring_flag = false;
    }
  } else {
    boolean num = set_smoothServo(3, 1, 160, 1500, 3, 160, 1500, 5, 160, 1500);
    if(num) {
      snoring_flag = true;
    }
  }
}
