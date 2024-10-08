/*
 * Project_Name    :   Logic_Analyzer_Scanner
 * File_Name       :   Scanner.ino
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/

#include <Wire.h>


void setup()
{
  Wire.begin();
  Serial.begin(9600);
  Serial.println("--------------------------");
  Serial.println("I2C Hex hexAddress Scanner");
  Serial.println("--------------------------");
}


void loop()
{
  byte response, hexAddress;
  int deviceCnt = 0;
    
  Serial.println("Scanning...");
  for (hexAddress = 0; hexAddress < 127; hexAddress++ )
  {
    // Start transmitting on every known hex hexAddress
    Wire.beginTransmission(hexAddress);

    // See if something acknowledged the transmission
    response = Wire.endTransmission();
    if (response == 0)
    {
      Serial.print("I2C device found at hexAddress 0x");
      if (hexAddress < 16)
        Serial.print("0");
      Serial.println(hexAddress, HEX);
            deviceCnt++;
    }
    else if (response == 4) // unknown error
    {
      Serial.print("Unknown response at hexAddress 0x");
      if (hexAddress < 16)
        Serial.print("0");
      Serial.println(hexAddress, HEX);
    }
  }

  // Nothing found at any of the hexAddresses
  if (deviceCnt == 0)
    Serial.println("No I2C devices found\n");
  else
    Serial.println("Scan completed.\n");

  // Delay 5 seconds and repeat scan
  delay(5000);
}
