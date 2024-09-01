/*
 * Project_Name    :   DHT22_SD_Card
 * File_Name       :   DHT22_SD_Card.ino
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega328p
*/


#include <DHT22.h>
#include <SD.h>
#include <SPI.h>

#define DATA PD2


File Datalog;
DHT22 dht22(DATA); 


void setup() {
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
}

void loop() {
  
  delay (2000);
  float temp = dht22.getTemperature();
  float hum  = dht22.getHumidity();

  if (dht22.getLastError() != dht22.OK) {
    Serial.print("last error :");
    Serial.println(dht22.getLastError());
  }
  
 
  Serial.print("Temperature = ");
  Serial.print(temp);
  Serial.print(" °C ");
  Serial.print("Humidity = ");
  Serial.print(hum);
  Serial.println(" % ");


  Datalog = SD.open("Datalog.txt", FILE_WRITE);
  if (Datalog) {
  Datalog.print("Temperature = ");
  Datalog.print(temp);
  Datalog.print("°C");
  Datalog.print("      Humidity = ");
  Datalog.print(hum);
  Datalog.println("% ");
    // close the file:
  Datalog.close();
    
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

 delay(3000);

}
