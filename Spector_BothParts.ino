// SPECTOR Project
// ------------------------------------------------------
// Class:         CEN5035 - Software Engineering
// Students:      Richard Altamore & Julian-Justin Djoum
// Term:          Spring 2021
// Teacher:       Dr. Ankur Agarwal
// ------------------------------------------------------

char blue_INval = 0;
#define Motion_S 2

void setup() 
{
  
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  digitalWrite(Motion_S, LOW);
  pinMode(Motion_S, INPUT);

}

void loop() 
{
/**/
//Bluetooth Module Code...
  if (Serial.available() > 0)
  {
    blue_INval = Serial.read();
    //Serial.print(blue_INval);
    //Serial.print("/n");
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
/**/
//PIR Sensor Code...
  if (digitalRead(Motion_S) == HIGH)
  {
    Serial.print("A");
    digitalWrite(5, HIGH);
    delay(100);
  }
  else
  {
    Serial.print("a");
    digitalWrite(5, LOW);
    delay(100);
  }
  delay(1000);
/**/
}
