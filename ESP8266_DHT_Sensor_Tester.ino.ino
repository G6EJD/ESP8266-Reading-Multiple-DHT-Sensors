/*************************************************** 
  This is a example sketch demonstrating the graphics
  capabilities of the SSD1331 library  for the 0.96" 
  16-bit Color OLED with SSD1331 driver chip

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/684

  These displays use SPI to communicate, 4 or 5 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// You can use any (4 or) 5 pins 
#define sclk D5 //--- connect this to the display module SCL pin      (Serial Clock)
#define mosi D7 //--- connect this to the display module SDA/MOSI pin (Serial Data)
#define rst  D6 //--- connect this to the display module RES pin      (Reset)
#define dc   D8 //--- connect this to the display module DC  pin      (Data or Command)
#define cs   D0 //--- connect this to the display module CS  pin      (Chip Select)

#define DHTPIN1  D4
#define DHTTYPE1 DHT11   // AM2303 was called DHT11
#define DHTPIN2  D3
#define DHTTYPE2 DHT21   // AM2301 was called DHT21
#define DHTPIN3  D2
#define DHTTYPE3 DHT22   // AM2302 was called DHT22

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_Sensor.h>
#include <SPI.h>
#include <Wire.h>
#include "DHT.h"

//------------------------------------------------------------------
// Create the display object
Adafruit_ILI9341 display = Adafruit_ILI9341(cs, dc);
//------------------------------------------------------------------
// Create the DHT22 temperature and humidity sensor object
DHT dht1(DHTPIN1, DHTTYPE1);
DHT dht2(DHTPIN2, DHTTYPE2);
DHT dht3(DHTPIN3, DHTTYPE3);

void setup(void) {
  Serial.begin(9600);
  display.begin();
  display.fillScreen(ILI9341_BLACK);
  display.setRotation(3);
  display.setTextSize(2);
  dht1.begin();
  dht2.begin();
  dht3.begin();
  display.fillScreen(ILI9341_BLACK);
  display.setCursor(0,0);
}

void loop() {
  // Read DHT temperature and humidity values
  float AM2301_t = dht2.readTemperature();
  float AM2301_h = dht2.readHumidity();
  delay(300);

  // Read DHT temperature and humidity values
  float DHT22_t = dht3.readTemperature();
  float DHT22_h = dht3.readHumidity();
  delay(300);

  // Read DHT temperature and humidity values
  float DHT11_t = dht1.readTemperature();
  float DHT11_h = dht1.readHumidity();
  delay(300);

  // Clear screen and display titles
  display.fillScreen(ILI9341_BLACK);
  display.setCursor(0,0);
  display.setTextColor(ILI9341_YELLOW);
  display.setTextSize(2);
  display.println("  Temperature & Humidity "); 
  display.println("    Device Comparator"); 
  
  // Display temperature and humidity for each device. Humidity = 0 when device does not support that function
  display_temp_humi("DHT11",    0,  50,  DHT11_t, DHT11_h,  "2.0","5");
  display_temp_humi("AM2301",  100, 50, AM2301_t, AM2301_h, "0.5","2");
  display_temp_humi("DHT22",  200,  50, DHT22_t,  DHT22_h,  "0.5","2");
  delay(1000);
}

void display_temp_humi(String device, int x, int y, float temp, float humi, String tolerance1, String tolerance2) {
  display.setCursor(x,y);
  display.setTextColor(ILI9341_GREEN);
  display.print(device);
  display.setCursor(x,y+20);
  display.setTextColor(ILI9341_RED);
  display.print(temp,1);
  display.print(char(247));
  display.print("C");
  if (humi > 0) {
    display.setCursor(x,y+40);
    display.setTextColor(ILI9341_MAGENTA);
    display.print(humi,1);
    display.print("%rH");
  }
  display.setTextColor(ILI9341_WHITE);
  display.setCursor(x,y+60);
  display.setTextSize(1);
  display.print(char(240));
  display.print(tolerance1+char(247)+"C");
  if (tolerance2 != "") {
    display.print(", "+String(char(240)));
    display.print(tolerance2+"%rH");
  }
  display.setTextSize(2);
}

