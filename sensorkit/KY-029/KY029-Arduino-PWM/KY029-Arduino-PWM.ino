int Led_Rot = 10;
int Led_Gruen = 11;

int val;

void setup () {
  // Initialisierung Ausgangspins für die LEDs
  pinMode (Led_Rot, OUTPUT); 
  pinMode (Led_Gruen, OUTPUT); 
}
void loop () {
   // Innerhalb einer For-Schleife werden den beiden LEDs verschiedene PWM-Werte uebergeben
   // Dadurch entsteht ein Farbverlauf, in dem sich durch das Vermischen unterschiedlicher 
   // Helligkeitstufen der beiden integrierten LEDs, unterschiedliche Farben entstehen
   for (val = 255; val> 0; val--)
      {
      analogWrite (Led_Gruen, val);
      analogWrite (Led_Rot, 255-val);
      delay (15);
   }
   // In der zweiten For-Schleife wird der Farbverlauf rückwärts durchgegangen
   for (val = 0; val <255; val++)
      {
      analogWrite (Led_Gruen, val);
      analogWrite (Led_Rot, 255-val);
      delay (15);
   }
}
