/*
 * Project_Name    :   DS18B20_Temperature
 * File_Name       :   DS18B20_Temperature.ino
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   STM32F103C8T6_Blue_Pill
 * Environnement   :   Arduino IDE 2.1
*/


#include <OneWireSTM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

OneWire  ds(PB10);

LiquidCrystal_I2C lcd(0x27, 16, 2); 

byte degree [8] = {
  0b01100,
  0b10010,
  0b10010,
  0b01100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup(void) {
  Serial.begin(9600);
  lcd.init();
  lcd.createChar (1, degree);
}

void loop(void) {
  byte i;
  byte present = 0;
  byte type_s;
  byte data[12];
  byte addr[8];
  float celsius ;

  if ( !ds.search(addr)) {
    Serial.println();
    ds.reset_search();
    delay(5000);
    return;
  }
  
   Serial.print("ROM =");
  for( i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(addr[i], HEX);
  }

  // the first ROM byte indicates which chip
  if (addr[0] == 0x10) {
    Serial.println("  Chip = DS18B20");  
    } 

  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);   // start conversion, with parasite power on at the end
  delay(1000);     
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

  Serial.print("  Data = ");
  Serial.print(present, HEX);
  Serial.print(" ");

  for ( i = 0; i < 9; i++) {           
    data[i] = ds.read();
    Serial.print(data[i], HEX);
    Serial.print(" ");
  } 
  Serial.println();
  

  int16_t raw = (data[1] << 8) | data[0];
  if (type_s) {
    raw = raw << 3; 
    if (data[7] == 0x10) {
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7; 
    else if (cfg == 0x20) raw = raw & ~3; 
    else if (cfg == 0x40) raw = raw & ~1;
  }
  celsius = (float)raw / 16.0;
  Serial.print("Temperature = ");
  Serial.print(celsius);
  Serial.print(" °C ");
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("DS18B20_STM32");
  lcd.setCursor(1,1);
  lcd.print("Temp= ");
  lcd.print(celsius);
  lcd.setCursor(14,1);
  lcd.write(1);
  lcd.print("C");

  delay(1000);
}

