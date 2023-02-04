// Erforderliche Bibliotheken werden importiert
#include <OneWire.h>
#include <DallasTemperature.h>            

// Hier wird der Eingangspin deklariert, an den das Sensormodul angeschlossen wird
#define KY001_Signal_PIN 4

// Bibliotheken werden konfiguriert
OneWire oneWire(KY001_Signal_PIN);          
DallasTemperature sensors(&oneWire);    


void setup() {

    // Initialisierung des seriellen Ausgangs
    Serial.begin(9600);
    Serial.println("KY-001 temperature measurement");

    // Sensor wird initialisiert
    sensors.begin();  
}

// Hauptprogrammschleife
void loop()
{
    // Temperaturmessung wird gestartet...
    sensors.requestTemperatures();
    // ... und gemessene Temperatur ausgeben
    Serial.print("Temperature: ");
    Serial.print(sensors.getTempCByIndex(0));
    Serial.println(" °C");

    delay(1000); // 1s Pause bis zur nächsten Messung
}
