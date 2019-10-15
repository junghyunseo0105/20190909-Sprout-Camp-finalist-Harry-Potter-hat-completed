void motion_surprise() {
  if(snoring_flag) {
    boolean num = set_smoothServo(3, 1, 140, 1300, 3, 140, 1300, 5, 140, 1300);
    
    if(num) {
      snoring_flag = false;
    }
  } else {
    boolean num = set_smoothServo(3, 1, 160, 1300, 3, 160, 1300, 5, 160, 1300);
    if(num) {
      snoring_flag = true;
    }
  }
}
