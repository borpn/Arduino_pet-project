#include "DHT.h"
#define DHTPIN 2 
#define DHTTYPE DHT11
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,20,4);  
byte degree[8] = 
{
0b01100,
0b10010,
0b10010,
0b01100,
0b00000,
0b00000,
0b00000,
0b00000
};
void setup()
{
 lcd.init();                      
 dht.begin();
 Serial.begin(9600);
 lcd.createChar(1,degree);
}
void loop()
{   
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("Temperature:");
 lcd.setCursor(8,1);
 lcd.print(t);
 Serial.print("Temperature:");
 Serial.print(t);
 Serial.print("°C");
 Serial.print('\n');
 lcd.setCursor(13,1);
 lcd.print(char(1));
 lcd.setCursor(14,1);
 lcd.print("C");
 lcd.setCursor(0,2);
 lcd.print("Humidity:");
 lcd.setCursor(8,3);
 lcd.print(h);
 Serial.print("Humidity:");
 Serial.print(h);
 Serial.print("%");
 Serial.print('\n');
 lcd.setCursor(13,3);
 lcd.print("%"); 
 delay(20000);
}
