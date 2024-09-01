/*
 * Project_Name    :   Counter.ino
 * File_Name       :   Counter.ino
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Arduino Uno
 * Environnement   :   Arduino IDE 2.1
*/

int cnt;

void setup() {
  // put your setup code here, to run once:

  Serial.begin (9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  cnt ++;

  Serial.print ("Counter = ");
  Serial.println (cnt);
  delay (250);

}
