// ESP8266 or Arduinio reading multiple DHT (11,21,22) Temperature and Humidity Sensors
// (c) D L Bird 2016

#include "DHT.h"

// Create the DHT temperature and humidity sensor object
DHT dht1(D4, DHT11);
DHT dht2(D3, DHT21);
DHT dht3(D2, DHT22);

void setup(void) {
  Serial.begin(9600);
  dht1.begin();
  dht2.begin();
  dht3.begin();
}

void loop() {
  // Read DHT temperature and humidity values
  float DHT11_t = dht1.readTemperature();
  float DHT11_h = dht1.readHumidity();

  float DHT21_t = dht2.readTemperature();
  float DHT21_h = dht2.readHumidity();

  float DHT22_t = dht3.readTemperature();
  float DHT22_h = dht3.readHumidity();
    
  Serial.print("DHT11  ");
  Serial.print(DHT11_t,1); Serial.print(String(char(176))+"C  ");
  Serial.print(DHT11_h,1); Serial.println("%RH");
  Serial.println();

  Serial.print("DHT21  ");
  Serial.print(DHT21_t,1); Serial.print(String(char(176))+"C  ");
  Serial.print(DHT21_h,1); Serial.println("%RH");
  Serial.println();

  Serial.print("DHT22  ");
  Serial.print(DHT22_t,1); Serial.print(String(char(176))+"C  ");
  Serial.print(DHT22_h,1); Serial.println("%RH");
  Serial.println();

  delay(3000);
}




















//#define DHTPIN2  D3
//#define DHTTYPE2 DHT21   // AM2301 was called DHT21
//#define DHTPIN3  D2
//#define DHTTYPE3 DHT22   // AM2302 was called DHT22

// Create the DHT temperature and humidity sensor objects
//DHT dht2(DHTPIN2, DHTTYPE2);
//DHT dht3(DHTPIN3, DHTTYPE3);

