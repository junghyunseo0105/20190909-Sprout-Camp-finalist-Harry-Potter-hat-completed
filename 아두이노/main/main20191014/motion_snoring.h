boolean snoring_flag = true;

void motion_snoring() {
  
  if(snoring_flag) {
    boolean num = set_smoothServo(3, 1, 140, 1700, 3, 140, 1700, 5, 140, 1700);
    
    if(num) {
      snoring_flag = false;
    }
  } else {
    boolean num = set_smoothServo(3, 1, 160, 1700, 3, 160, 1700, 5, 160, 1700);
    if(num) {
      snoring_flag = true;
    }
  }
}
