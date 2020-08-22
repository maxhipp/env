#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Seeed_BME280.h>
#include <SPI.h>
#include <SD.h>

BME280 bme280;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
 lcd.init();
 lcd.backlight();
 lcd.setCursor(0,0);
 lcd.print("Loading...");
 Serial.begin(9600);
 if(!bme280.init()) {
  lcd.setCursor(0,1);
  lcd.print("BME280 Failed");
 }
 else {
  lcd.setCursor(0,1);
  lcd.print("BME280 success");
 }
}

void loop() {
 clearLine(1);
 lcd.setCursor(0,1);
 lcd.print("T : ");
 lcd.print(bme280.getTemperature());
 delay(3000);
 clearLine(1);
 lcd.setCursor(0,1);
 lcd.print("F : ");
 lcd.print(bme280.getHumidity());
 lcd.print("%");
 delay(3000);
}

void clearLine(int line) {               
 lcd.setCursor(0,line);
   for(int n = 0; n < 16; n++) {
     lcd.print(" ");
   }
}
