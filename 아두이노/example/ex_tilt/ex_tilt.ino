void setup() {
  pinMode(11, INPUT);
  Serial.begin(9600);
}

int timer = 0;
boolean flag = true;

boolean get_tiltVal() {
  int tilt = digitalRead(11);
  int system_time = millis();
  int total_time = system_time - timer;
  
  if(flag == true && tilt > 0) {
    flag = false;
    timer = millis();
  }

  int second = 1000;
  
  if(total_time >= second && flag == false) {
    flag = true;
  }
  
  return flag;
}

void loop() {
  Serial.println(get_tiltVal());
}
