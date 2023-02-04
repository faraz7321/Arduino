int Sensor = 10; // Deklaration des Sensor-Eingangspin
  
void setup ()
{
  Serial.begin(9600); // Initialisierung serielle Ausgabe
  pinMode (Sensor, INPUT) ; // Initialisierung Sensorpin
}
  
// Das Programm liest den aktuellen Status des Sensor-Pins aus und
// gibt in der seriellen Konsole aus, ob der Linetracker sich aktuell 
// auf der Linie befindet oder nicht
void loop ()
{
  bool val = digitalRead (Sensor) ; // Das gegenwärtige Signal am Sensor wird ausgelesen
  
  if (val == HIGH) // Falls ein Signal erkannt werden konnte, wird die LED eingeschaltet.
  {
    Serial.println("LineTracker ist ueber der Linie");
  }
  else
  {
    Serial.println("Linetracker ist ausserhalb der Linie");
  }
  Serial.println("------------------------------------");
  delay(500); // Pasuse zwischen der Messung von 500ms
}
