// ESP8266 or Arduinio reading multiple DHT (11,21,22) Temperature and Humidity Sensors
// (c) D L Bird 2018

#include "DHT.h"   //https://github.com/adafruit/DHT-sensor-library 
// Create the DHT temperature and humidity sensor objects
// The example here is for a Wemos D1 Mini, you can chose and use any (available) pins you like for each sensor 
DHT sensor1(D4, DHT11); // Change the pin D4 to suit your needs and sensor type to match yours e.g. DHT11, or DHT 21 or DHT22
DHT sensor2(D3, DHT11); // Change the pin D3 to suit your needs and sensor type to match yours e.g. DHT11, or DHT 21 or DHT22
DHT sensor3(D2, DHT11); // Change the pin D2 to suit your needs and sensor type to match yours e.g. DHT11, or DHT 21 or DHT22
DHT sensor4(D1, DHT11); // Change the pin D1 to suit your needs and sensor type to match yours e.g. DHT11, or DHT 21 or DHT22

// Now declare the variables that will hold the sensor readings
float sensor1_temp,
      sensor2_temp,
      sensor3_temp,
      sensor4_temp; // Add more if required

float sensor1_humi,
      sensor2_humi,
      sensor3_humi,
      sensor4_humi; // Add more if required

void setup(void) {
  Serial.begin(9600);
  sensor1.begin();
  sensor2.begin();
  sensor3.begin();
  sensor4.begin(); // Add more if you have the spare pins available!
}

void loop() {
  // Read DHT temperature and humidity values for Sensor-1
  sensor1_temp = sensor1.readTemperature();
  sensor1_humi = sensor1.readHumidity();

  // Read DHT temperature and humidity values for Sensor-2
  sensor2_temp = sensor2.readTemperature();
  sensor2_humi = sensor2.readHumidity();

  // Read DHT temperature and humidity values for Sensor-3
  sensor3_temp = sensor3.readTemperature();
  sensor3_humi = sensor3.readHumidity();

  //sensor4_temp = sensor4.readTemperature(); // Uncomment for 4 sensors
  //sensor4_humi = sensor4.readHumidity();    // Uncomment for 4 sensors
  
  Serial.print("Sensor-1 Readings:  ");
  Serial.print(sensor1_temp,1); Serial.print(String(char(176))+"C  ");
  Serial.print(sensor1_humi,1); Serial.println("%RH");
  Serial.println();

  Serial.print("Sensor-2 Readings:  ");
  Serial.print(sensor2_temp,1); Serial.print(String(char(176))+"C  ");
  Serial.print(sensor2_humi,1); Serial.println("%RH");
  Serial.println();

  Serial.print("Sensor-3 Readings:  ");
  Serial.print(sensor3_temp,1); Serial.print(String(char(176))+"C  ");
  Serial.print(sensor3_humi,1); Serial.println("%RH");
  Serial.println();

  //Serial.print("Sensor-4 Readings:  "); // Uncomment for 4 sensors
  //Serial.print(sensor4_temp,1); Serial.print(String(char(176))+"C  "); // Uncomment for 4 sensors
  //Serial.print(sensor4_humi,1); Serial.println("%RH"); // Uncomment for 4 sensors
  //Serial.println();
  delay(3000);
}
