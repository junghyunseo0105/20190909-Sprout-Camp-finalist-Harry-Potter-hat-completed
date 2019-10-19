boolean sing_flag = true;

void motion_sing() {
  
  if(sing_flag) {
    boolean num = set_smoothServo(3, 1, 160, 500, 
                                      3, 160, 500,
                                      5, 160, 500
                                      );
    
    if(num) {
      sing_flag = false;
    }
  } else {
    boolean num = set_smoothServo(3, 1, 180, 400, 
                                      3, 180, 400,
                                      5, 180, 400
                                      );
    if(num) {
      sing_flag = true;
    }
  }
}
