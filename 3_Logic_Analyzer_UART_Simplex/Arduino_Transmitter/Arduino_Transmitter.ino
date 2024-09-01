/*
 * Project_Name    :   UART_Simplex
 * File_Name       :   Arduino_Transmitter.ino
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Arduino Uno
 * Environnement   :   Arduino IDE 2.1
*/


void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println ("Hello Logic_Analyzer !");
  delay (1000);

}
