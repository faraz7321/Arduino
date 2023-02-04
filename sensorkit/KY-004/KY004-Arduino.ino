// KY-004 BUTTON
int Led = 13;    // declaration of the LED output pin
int Sensor = 10; // Declaration of the sensor input pin
int val;         // Temporary variable

void setup()
{
  pinMode(Led, OUTPUT);       // Initialize output pin
  pinMode(Sensor, INPUT);     // Initialize sensor pin
  digitalWrite(Sensor, HIGH); // Activate internal pull-up resistor
}

void loop()
{
  val = digitalRead(Sensor); // The current signal at the sensor is read out

  if (val == HIGH) // If a signal could be detected, the LED is switched on.
  {
    digitalWrite(Led, LOW);
  }
  else
  {
    digitalWrite(Led, HIGH);
  }
}