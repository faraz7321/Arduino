int Led = 13 ;// Deklaration des LED-Ausgangspin
int Sensor = 10; // Deklaration des Sensor-Eingangspin
int val; // Temporaere Variable
  
void setup ()
{
  pinMode (Led, OUTPUT) ; // Initialisierung Ausgangspin
  pinMode (Sensor, INPUT) ; // Initialisierung Sensorpin
}
  
void loop ()
{
  val = digitalRead (Sensor) ; // Das gegenwärtige Signal am Sensor wird ausgelesen
  
  if (val == HIGH) // Falls ein Signal erkannt werden konnte, wird die LED eingeschaltet.
  {
    digitalWrite (Led, LOW);
  }
  else
  {
    digitalWrite (Led, HIGH);
  }
}
