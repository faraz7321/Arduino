#include <Adafruit_ADS1015.h>
#include <math.h>

Adafruit_ADS1115 ads;

void setup(void)
{
  Serial.begin(9600);
  
  Serial.println("Werte des analogen Eingaenges A1 des ADS1115 werden ausgelesen und ausgegeben");
  Serial.println("ADC Range: +/- 4.096V  1 bit = 0.125mV");
  
  // Dieses Modul besitzt an seinen analogen Eingängen Signalverstärker, deren
  // Verstärkung per Software in den unten stehenden Bereichen konfiguriert werden
  // können.
  // Dieses ist in dem Fall gewünscht, wenn ein bestimmter Spannungsbereich
  // als messergebnis erwartet wird und man so eine höhere Auflösung des Signals
  // erhält.
  // Als Standardverstärkung ist Gain=[2/3] gewählt und kann durch Auskommentieren
  // auf eine andere Verstärkung umgestellt werden.
  //                                                                ADS1115
  //                                                                -------
  // ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 0.1875mV
  ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.0078125mV
  
  ads.begin();
}

void loop(void)
{
  uint16_t adc1;
  float voltage1;
  float gain_conversion_factor;
  
  // Der Befehl "ads.readADC_SingleEnded(0)" ist die eigentliche Operation, die die Messung im ADC startet.
  // die "0" als Variable für diese Funktion definiert den verwendeten Channel, der gemessen werden soll
  // Soll z.B. der dritte Channel gemessen werden, so muss diese mit der "3" ausgetauscht werden
  adc1 = ads.readADC_SingleEnded(1);
  
  // Dieser Wert wird für die Umrechnung in eine Spannung benötigt - dieser hängt von der eingestellten Verstärkung ab.
  // Der passende Wert zur Verstärkung sollte aus der oben aufgezeigten Tabelle entnommen werden
  gain_conversion_factor = 0.125;
  
  // Umrechnung der aufgezeichneten Werte in eine Spannung
  voltage1 = (adc1 * gain_conversion_factor);
  
  // Ausgabe der Werte auf die serielle Schnittstelle
  Serial.print("Analoger Eingang 1: "); Serial.print(voltage1); Serial.println("mV");
 
  double Temp;
  Temp = ((voltage1 / 3300) * 10000) / (1 - (voltage1 / 3300));
  Temp = 1 / ((1/298.15) + (1 / 3950.0) * log(Temp / 10000));
  Temp = Temp - 273.15;
  
  Serial.print("Aktuelle Temperatur ist:");
  Serial.print(Temp);
  Serial.println("°C");
  Serial.println("---------------------------------------");

  delay(1000);
}
