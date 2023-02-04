int Buzzer = 13;

void setup ()
{
  pinMode (Buzzer, OUTPUT); // Initialisierung Ausgangspin für den Buzzer
}

void loop () //Hauptprogrammschleife
{
  digitalWrite (Buzzer, HIGH); // Buzzer wird eingeschaltet
  delay (4000); // Wartemodus für 4 Sekunden
  digitalWrite (Buzzer, LOW); // Buzzer wird ausgeschaltet
  delay (2000); // Wartemodus für weitere zwei Sekunden in denen die LED dann ausgeschaltet ist
}
