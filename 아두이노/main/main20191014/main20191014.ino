#include "dht11Handler.h"
#include "tiltHandler.h"
#include "servoPWM.h"
#include "servoPWM1.h"

#include "motion_snoring.h"
#include "motion_stop.h"
#include "motion_surprise.h"
#include "motion_talk.h"

#include "motion.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht11_setting();
  tilt_setting();

  servoSetting();
  
  delay(1000);
}

int motion_num = 0;

void loop() {
  if(Serial.available()) {
    String inString = Serial.readStringUntil('\n');

    if(inString.equals("tilt")) {
      Serial.println(get_tiltVal());
    } 
    else if(inString.equals("temp")) {
      Serial.println(get_temperature());
    } 
    else if(inString.equals("humi")) {
      Serial.println(get_humidity());
    } 
    else if(inString.equals("snoring")) {  //코골기
      motion_num = 1;
    }
    else if(inString.equals("surprise")) {  //깜짝놀라기
      motion_num = 2;
    }
    else if(inString.equals("stop")) {  //동작멈추기 (허리펴기)
      motion_num = 3;
    }
    else if(inString.equals("talk")) {  //말하기
      motion_num = 4;
    }
    else {
      Serial.println("-2");
    }
  }
  
  motion(motion_num);
  
  get_tiltVal();
}
