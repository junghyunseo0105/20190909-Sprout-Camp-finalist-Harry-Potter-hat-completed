#include "DHT.h"

#define DHTPIN 10
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);

void dht11_setting() {
  //Serial.begin(9600);
  dht.begin();
}

int get_humidity() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
   
  if (isnan(humidity)) {
    return -1;
  }

  return (int)humidity;
}

int get_temperature() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(temperature) ) {
    return -1;
  }

  return (int)temperature;
}
