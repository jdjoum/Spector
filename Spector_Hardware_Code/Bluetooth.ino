// SPECTOR Project
// ------------------------------------------------------
// Class:         CEN5035 - Software Engineering
// Students:      Richard Altamore & Julian-Justin Djoum
// Term:          Spring 2021
// Teacher:       Dr. Ankur Agarwal
// ------------------------------------------------------

char blue_INval = 0;

void setup() 
{
  
  Serial.begin(9600);
  pinMode(6, OUTPUT);

}

void loop() 
{
/**/
  if (Serial.available() > 0)
  {
    blue_INval = Serial.read();
    Serial.print(blue_INval);
    Serial.print("/n");
    if (blue_INval == '1')
    {
      digitalWrite(6, HIGH);    
    }
    else if (blue_INval == '0')
    {
      digitalWrite(6, LOW);
    }
  }
/**/
}
