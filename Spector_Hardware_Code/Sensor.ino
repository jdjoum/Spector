// SPECTOR Project
// ------------------------------------------------------
// Class:         CEN5035 - Software Engineering
// Students:      Richard Altamore & Julian-Justin Djoum
// Term:          Spring 2021
// Teacher:       Dr. Ankur Agarwal
// ------------------------------------------------------

#define SIGNAL_PIN 2

void setup() 
{
  
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  
  pinMode(SIGNAL_PIN, INPUT);

}

void loop() 
{
/**/
  if (digitalRead(SIGNAL_PIN) == HIGH)
  {
    Serial.println("Movement detected.");
    digitalWrite(5, HIGH);
  }
  else
  {
    Serial.println("Did not detect movement.");
    digitalWrite(5, LOW);
  }
  delay(1000);
/**/
}
