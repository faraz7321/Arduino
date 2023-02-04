int sensorPin = A5; // Hier wird der Eingangs-Pin deklariert
 
// Serielle Ausgabe in 9600 Baud
void setup()
{
    Serial.begin(9600);
}
 
// Das Programm misst den aktuellen Spannungswert am Sensor,
// berechnet aus diesen und dem bekannten Serienwiderstand den aktuellen
// Widerstandswert des Sensors und gibt die Ergebnisse auf der serielle Ausgabe aus
 
void loop()
{      
        // Aktueller Spannungswert wird gemessen...
    int rawValue = analogRead(sensorPin);
        float voltage = rawValue * (5.0/1023) * 1000;
         
        float resitance = 10000 * ( voltage / ( 5000.0 - voltage) );
         
    // ... und hier auf die serielle Schnittstelle ausgegeben
    Serial.print("Spannungswert:"); Serial.print(voltage); Serial.print("mV");
    Serial.print(", Widerstandswert:"); Serial.print(resitance); Serial.println("Ohm");
    Serial.println("---------------------------------------");
 
    delay(500);
}
