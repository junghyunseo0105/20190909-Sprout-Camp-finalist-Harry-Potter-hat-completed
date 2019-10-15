#include "DHT.h"

#define DHTPIN 10
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

int get_humidity() {
  float humidity = dht.readHumidity();

  if (isnan(humidity) ) {
    humidity = -1;
  }

  return (int)humidity;
}

int get_temperature() {
  float temperature = dht.readTemperature();

  if (isnan(temperature) ) {
    temperature = -1;
  }

  return (int)temperature;
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  // 온도와 습도값을 시리얼 모니터에 출력해 줍니다.
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");

  delay(1500);
}
