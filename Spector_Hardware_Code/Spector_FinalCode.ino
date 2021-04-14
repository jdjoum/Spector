// SPECTOR Project
// ------------------------------------------------------
// Class:         CEN5035 - Software Engineering
// Students:      Richard Altamore & Julian-Justin Djoum
// Term:          Spring 2021
// Teacher:       Dr. Ankur Agarwal
// ------------------------------------------------------

char blue_INval = 0;          //Bluetooth LED app button value (default OFF [0])
#define Motion_S 2            //sets PIR Motion Sensor to pin 2

void setup() 
{
  
  Serial.begin(9600);         //standard Arduino begin value (9600)
  pinMode(5, OUTPUT);         //PIR Motion Sensor Indicator LED on pin 5
  pinMode(6, OUTPUT);         //Arduino Bluetooth Indicator LED on pin 6

  digitalWrite(Motion_S, LOW);          //default PIR Motion Sensor value set to 0 (LOW)
  pinMode(Motion_S, INPUT);             //sets PIR Motion Sensor as an input value

}

void loop() 
{
/**/
//Arduino Bluetooth Module Code Portion...
  if (Serial.available() > 0)         //if the Bluetooth connection is available and set..
  {
    blue_INval = Serial.read();         //reads the value of the Bluetooth LED button from the app

    if (blue_INval == '1')          //if Bluetooth LED app button is toggled ON..
    {
      digitalWrite(6, HIGH);          //turns ON the LED on pin 6
    }
    else if (blue_INval == '0')         //if Bluetooth LED app button is toggled OFF..
    {
      digitalWrite(6, LOW);         //turns OFF the LED on pin 6
    }
  }
/**/
/**/
//PIR Motion Sensor Module Code Portion...
  if (digitalRead(Motion_S) == HIGH)          //if the PIR Motion Sensor has been triggered..
  {
    Serial.print("A");              //prints "A" on the Serial Monitor
    digitalWrite(5, HIGH);          //turns ON the LED on pin 5
    delay(100);                     //small 0.1 second delay
  }
  else          //if the PIR Motion Sensor has NOT been triggered (default state)..
  {
    Serial.print("a");            //prints "a" on the Serial Monitor
    digitalWrite(5, LOW);         //turns OFF the LED on pin 5
    delay(100);                   //small 0.1 second delay
  }
  delay(1000);          //simple 1 second delay
/**/
}
