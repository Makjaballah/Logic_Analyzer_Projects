/*
 * Project_Name    :   MCP4725_DAC
 * File_Name       :   MCP4725_DAC.ino
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   STM32F103C8T6_Blue_Pill
 * Environnement   :   Arduino IDE 2.1
*/


#include <Wire.h>                   
#include <SoftWire.h>    
#include <LiquidCrystal_I2C.h>      

#define MCP4725_ADDR 0x60 


LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned int Adc_Value, Analog_Read ;
float Op_Volt, Ip_Volt;

byte buffer[3]; //buffer for the values to be written on the DAC



void setup() {
  // put your setup code here, to run once:

  Serial.begin( 9600 );
  Wire.begin();
                     
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("STM32F103C8");
  lcd.setCursor(0,1);
  lcd.print("DAC_with_MCP4725");
  delay(2000);
  lcd.clear();
}
  
  
  void loop() {
  // put your main code here, to run repeatedly:

  
  Adc_Value = analogRead(PA0);  
  Ip_Volt = (3.3/4096.0) * Adc_Value; 

  buffer[0] = 0b01000000;
  buffer[1] = Adc_Value >> 4; // D4 - D11 part
  buffer[2] = Adc_Value << 4; // D3 - D0 part
  
  Wire.beginTransmission(MCP4725_ADDR); //We can write MCP4725 because of the definition in the beginning of the code    
  Wire.write(buffer[0]); //C2 = 0, C1 = 1, C0 = 0, rest: 00000.
  Wire.write(buffer[1]);  //Sends the first byte 
  Wire.write(buffer[2]);  //Sends the second byte  
  Wire.endTransmission(); //actually sending the data to the DAC

  Analog_Read = analogRead(PA1);
  Op_Volt = (3.3/4096.0) *  Analog_Read; 

  Serial.print(" Adc_value = ");
  Serial.print( Adc_Value );
  Serial.print( "\n\r" );
  Serial.print(" Ip_Volt= ");
  Serial.print( Ip_Volt );
  Serial.print( "\n\r" );
  
  Serial.print(" Analog_Read = ");
  Serial.print( Analog_Read );
  Serial.print( "\n\r" );
  Serial.print(" Op_Volt= ");
  Serial.print( Op_Volt );
  Serial.print( "\n\r" );

  delay (1000);
   

  lcd.setCursor(0,0);
  lcd.print("A_IP:");
  lcd.print(Adc_Value);                  
  lcd.setCursor(10,0);
  lcd.print("V:");                 
  lcd.print(Ip_Volt);

  lcd.setCursor(0,1);
  lcd.print("D_IP:");
  lcd.print(Analog_Read);                  
  lcd.setCursor(10,1);
  lcd.print("V:");                 
  lcd.print(Op_Volt);
  
  delay(200);
  
  

}
