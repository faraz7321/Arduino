#define Echo_EingangsPin 7 // Echo Eingangs-Pin
#define Trigger_AusgangsPin 8 // Trigger Ausgangs-Pin

// Benoetigte Variablen werden definiert
int maximumRange = 300; 
int minimumRange = 2; 
long Abstand;
long Dauer;

void setup() {
 pinMode(Trigger_AusgangsPin, OUTPUT);
 pinMode(Echo_EingangsPin, INPUT);
 Serial.begin (9600);
}

void loop() {

 // Abstandsmessung wird mittels des 10us langen Triggersignals gestartet
 digitalWrite(Trigger_AusgangsPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(Trigger_AusgangsPin, LOW);
 
 // Nun wird am Echo-Eingang gewartet, bis das Signal aktiviert wurde
 // und danach die Zeit gemessen, wie lang es aktiviert bleibt 
 Dauer = pulseIn(Echo_EingangsPin, HIGH);
 
 // Nun wird der Abstand mittels der aufgenommenen Zeit berechnet
 Abstand = Dauer/58.2;
 
 // Überprüfung ob gemessener Wert innerhalb der zulässingen Entfernung liegt
 if (Abstand >= maximumRange || Abstand <= minimumRange)
 {
    // Falls nicht wird eine Fehlermeldung ausgegeben.
      Serial.println("Abstand außerhalb des Messbereichs");
      Serial.println("-----------------------------------");
 }  
 
 else 
 {
    // Der berechnete Abstand wird in der seriellen Ausgabe ausgegeben
      Serial.print("Der Abstand betraegt:");
      Serial.print(Abstand);
      Serial.println("cm");
      Serial.println("-----------------------------------");
 }
  // Pause zwischen den einzelnen Messungen
 delay(500);
}
