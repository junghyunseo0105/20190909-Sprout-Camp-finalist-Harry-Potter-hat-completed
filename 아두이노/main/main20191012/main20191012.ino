#include "dht11Handler.h"
#include "tiltHandler.h"
#include "motion.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht11_setting();
  tilt_setting();
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
    else if(inString.equals("snoring")) {
      motion_num = 1;
    }
    else if(inString.equals("surprise")) {
      motion_num = 2;
    }
    else {
      Serial.println("-2");
    }
  }
  
  motion(motion_num);
  
  get_tiltVal();
}
