
void motion_stop() {
  for(int i = 0; i < 7; i++) {  
    setAngle(i, servo_angle[i]);  
  }
}
