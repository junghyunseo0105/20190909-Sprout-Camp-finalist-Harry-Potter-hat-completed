void motion_talk() {
  int mouth = 30;
  int eye = 10;
  int waist = 20;

  int servo_num = 4;
  
  if(snoring_flag) {
    
    boolean num = set_smoothServo(servo_num, 0, 0 + mouth, 400,
                                            1, 180 - waist, 400,  
                                            2, 160 - mouth, 400,
                                            5, 180 - waist, 500
                                            );
    
    if(num) {
      snoring_flag = false;
    }
  } else {
    boolean num = set_smoothServo(servo_num, 0, 0, 400, 
                                            1, 180, 400,
                                            2, 160, 400,
                                            5, 180, 500
                                            );
    if(num) {
      snoring_flag = true;
    }
  }
}
