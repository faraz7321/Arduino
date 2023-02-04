int Sensor = 10; // Deklaration des Sensor-Eingangspin
  
void setup ()
{
  Serial.begin(9600); // Initialisierung serielle Ausgabe
  pinMode (Sensor, INPUT) ; // Initialisierung Sensorpin
}
  
// Das Programm liest den aktuellen Status des Sensor-Pins aus und
// gibt in der seriellen Konsole aus, ob ein Hindernis aktuell erkannt wird
// oder ob kein Hindernis sich vor dem Sensor befindet
void loop ()
{
  bool val = digitalRead (Sensor) ; // Das gegenwärtige Signal am Sensor wird ausgelesen
  
  if (val == HIGH) // Falls ein Signal erkannt werden konnte, wird die LED eingeschaltet.
  {
    Serial.println("Kein Hindernis");
  }
  else
  {
    Serial.println("Hindernis erkannt");
  }
  Serial.println("------------------------------------");
  delay(500); // Pause zwischen der Messung von 500ms
}
