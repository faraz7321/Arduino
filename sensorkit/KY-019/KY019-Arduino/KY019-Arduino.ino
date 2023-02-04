int relay = 10; // Hier wird der Pin deklariert, an dem das Relay angeschlossen ist
 
int delayTime = 1; // Wert in Sekunden, wie lange zwischen den Umschaltungen gewartet werden soll
 
void setup ()
{
  pinMode (relay, OUTPUT); // Der Pin wird als Ausgang deklariert
}
 
// Das Programm bildet einen Blinker nach - es schaltet das Relais in vorher definierter 
// Zeit (delayTime) zwischen den beiden Zuständen (bzw. Ausgangsterminals) um.
void loop ()
{
  digitalWrite (relay, HIGH); // "NO" ist nun kurzgeschlossen;
  delay (delayTime * 1000);
  digitalWrite (relay, LOW); // "NC" ist nun kurzgeschlossen;
  delay (delayTime * 1000);
}
