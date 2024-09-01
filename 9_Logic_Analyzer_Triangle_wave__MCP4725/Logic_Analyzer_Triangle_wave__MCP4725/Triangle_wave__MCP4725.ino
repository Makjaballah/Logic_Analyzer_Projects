/*
 * Project_Name    :   Triangle_wave_output_from_MCP4725
 * File_Name       :   Triangle_wave__MCP4725.ino
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/

#include <Wire.h>                   
#include <SoftWire.h>    
#include <LiquidCrystal_I2C.h>  

#define MCP4725_ADDR 0x60


void setup() {

  Serial.begin( 9600);
  delay( 1000 );
  Serial.println( "Test writing MCP4725 DAC" );
  Wire.begin(); // Initialize I2C library
}


void loop() {
  
  // Send the rising edge of a triangle wave:
  for( int16_t Dac_Out = 0; Dac_Out < 0xFFF; ++Dac_Out )
  {
    // Transmit the address byte (and a zero R/W bit):
    Wire.beginTransmission( MCP4725_ADDR );
    Wire.write( (Dac_Out >> 8) & 0xF );
    Wire.write( Dac_Out & 0xFF );
    // Send the stop condition onto the I2C bus:
    Wire.endTransmission( true );
    //delay( 5 );
  }
  
  // Send the falling edge of the triangle wave:
  for( int16_t Dac_Out = 0xFFE; Dac_Out > 0; --Dac_Out )
  {
    // See comments in previous loop.
    Wire.beginTransmission( MCP4725_ADDR );
    Wire.write( (Dac_Out >> 8) & 0xF );
    Wire.write( Dac_Out & 0xFF );
    Wire.endTransmission( true );
    //delay( 5 );
  }
  
}
