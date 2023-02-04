int buzzer = 8 ; // Deklaration des Buzzer-Ausgangspin

void setup ()
{
  pinMode (buzzer, OUTPUT) ;// Initialisierung als Ausgangspin
}


void loop ()
{
  unsigned char i;
  while (1)
  {
    // In diesem Programm wird der Buzzer abwechselnd mit zwei verschiedenen Frequenzen angesteuert
    // Das Signal hierbei besteht aus einer Rechteckspannung.
    // Das an- und ausmachen am Buzzer generiert dann einen Ton, der in etwa der Frequenz entspricht.
    // Die Frequenz definiert sich dadurch, wie lang jeweils die An- und Ausphase sind
    
    //Frequenz 1
    for (i = 0; i <80; i++) 
    {
      digitalWrite (buzzer, HIGH) ;
      delay (1) ;
      digitalWrite (buzzer, LOW) ;
      delay (1) ;
    }
    //Frequenz 2
    for (i = 0; i <100; i++) 
    {
      digitalWrite (buzzer, HIGH) ;
      delay (2) ;
      digitalWrite (buzzer, LOW) ;
      delay (2) ;
    }
  }
}
