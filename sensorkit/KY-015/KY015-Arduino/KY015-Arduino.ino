// Adafruit_DHT Library wird eingefügt
#include "DHT.h"

// Hier kann der jeweilige EingangsPin deklariert werden
#define DHTPIN 2     

// Der Sensor wird initialisiert
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  Serial.println("KY-015 Test - Temperatur und Luftfeuchtigkeits-Test:");

  // Messung wird gestartet
  dht.begin();
}


// Hauptprogrammschleife
// Das Programm startet die Messung und liest die gemessenen Werte aus
// Zwischen den Messungen wird eine Pause von 2 Sekunden eingelegt,
// damit beim nächsten Druchlauf eine neue Messung erfasst werden kann.
void loop() {

  // Zwei Sekunden Pause zwischen den Messungen
  delay(2000);

  // Luftfeuchtigkeit wird gemessen
  float h = dht.readHumidity();
  // Temperatur wird gemessen
  float t = dht.readTemperature();
  
  // Hier wird überprüft, ob die Messungen fehlerfrei druchgelaufen sind
  // Bei Detektion eines Fehlers, wird hier eine Fehelrmeldung ausgegeben
  if (isnan(h) || isnan(t)) {
    Serial.println("Fehler beim Auslesen des Sensors");
    return;
  }

  // Ausgabe in die serrielle Konsole
  Serial.println("-----------------------------------------------------------");
  Serial.print("Luftfeuchtigkeit: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatur: ");
  Serial.print(t);
  Serial.print(char(186)); //Ausgabe <°> Symbol
  Serial.println("C ");
  Serial.println("-----------------------------------------------------------");
  Serial.println(" ");
}
