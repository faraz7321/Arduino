int Led_Rot = 10;
int Led_Gruen = 11;
 
void setup ()
{
  // Initialisierung Ausgangspins für die LEDs
  pinMode (Led_Rot, OUTPUT); 
  pinMode (Led_Gruen, OUTPUT); 
}
 
void loop () //Hauptprogrammschleife
{
  digitalWrite (Led_Rot, HIGH); // LED wird eingeschaltet
  digitalWrite (Led_Gruen, LOW); // LED wird eingeschaltet
  delay (3000); // Wartemodus für 3 Sekunden
 
  digitalWrite (Led_Rot, LOW); // LED wird eingeschaltet
  digitalWrite (Led_Gruen, HIGH); // LED wird eingeschaltet
  delay (3000); // Wartemodus für weitere zwei Sekunden in denen die LEDs dann umgeschaltet sind
}
