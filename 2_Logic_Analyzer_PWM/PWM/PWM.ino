/*
 * Project_Name    :   PWM
 * File_Name       :   PWM.ino
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Arduino Uno
 * Environnement   :   Arduino IDE 2.1
*/

void setup() {
  // put your setup code here, to run once:

  pinMode (3, OUTPUT);
  pinMode (4, OUTPUT);
  analogWrite (5, 64); // PWM signal at 25% duty cycle

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite (3, HIGH); // PWM with 500 Hz output signal at 50% duty cyle
  digitalWrite (4, HIGH); // PWM with 250 Hz output signal at 50% duty cyle
  delay (1);
  digitalWrite (3, LOW);
  delay (1);
  digitalWrite (3, HIGH);
  digitalWrite (4, LOW);
  delay (1);
  digitalWrite (3, LOW);
  delay (1);

}
