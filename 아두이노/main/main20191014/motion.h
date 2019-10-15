void motion(int i) {
  if(i == 1) {  //코골기
    motion_snoring();
  } else if(i == 2) { //깜짝놀라기
    
  } else if(i == 3) { //동작멈추기
    motion_stop();
  } else if(i == 4) {  //말하기
    motion_talk();
  }
}
