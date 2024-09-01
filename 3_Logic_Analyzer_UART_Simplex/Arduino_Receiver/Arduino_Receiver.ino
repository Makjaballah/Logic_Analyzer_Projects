/*
 * Project_Name    :   UART_Simplex
 * File_Name       :   Arduino_Receiver.ino
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

  if  (Serial.available ()){
  
  Serial.println (Serial.readString ()); 
 }  

}
