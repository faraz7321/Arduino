#include <Adafruit_ADS1X15.h>
#include <math.h>

// ADS1115 Modul wird initialisiert - alle folgenden Operationen mit dem ADC
// können mit Hilfe des Objektes "ads" ausgeführt werden.
Adafruit_ADS1115 ads; 

void setup(void) 
{
  Serial.begin(9600);
  
  Serial.println("Werte der analogen Eingaenge des ADS1115 (A0..A3) werden ausgelesen und ausgegeben");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 0.1875mV)");
  
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
  ads.setGain(GAIN_TWOTHIRDS);  // 2/3x gain +/- 6.144V  1 bit = 0.1875mV 
  // ads.setGain(GAIN_ONE);        // 1x gain   +/- 4.096V  1 bit = 0.125mV
  // ads.setGain(GAIN_TWO);        // 2x gain   +/- 2.048V  1 bit = 0.0625mV
  // ads.setGain(GAIN_FOUR);       // 4x gain   +/- 1.024V  1 bit = 0.03125mV
  // ads.setGain(GAIN_EIGHT);      // 8x gain   +/- 0.512V  1 bit = 0.015625mV
  // ads.setGain(GAIN_SIXTEEN);    // 16x gain  +/- 0.256V  1 bit = 0.0078125mV
  
  ads.begin();
}

void loop(void) 
{
  uint16_t adc0, adc1, adc2, adc3;
  float voltage0, voltage1, voltage2, voltage3;
  float gain_conversion_factor;
  
  // Der Befehl "ads.readADC_SingleEnded(0)" ist die eigentliche Operation, die die Messung im ADC startet.
  // die "0" als Variable für diese Funktion definiert den verwendeten Channel, der gemessen werden soll
  // Soll z.B. der dritte Channel gemessen werden, so muss diese mit der "3" ausgetauscht werden
  adc0 = ads.readADC_SingleEnded(0); 
  adc1 = ads.readADC_SingleEnded(1);
  adc2 = ads.readADC_SingleEnded(2);
  adc3 = ads.readADC_SingleEnded(3);
  
  // Dieser Wert wird für die Umrechnung in eine Spannung benötigt - dieser ´hängt von der eingestellten Verstärkung ab.
  // Der passende Wert zur Verstärkung sollte aus der oben aufgezeigten Tabelle entnommen werden
  gain_conversion_factor= 0.1875;
  
  // Umrechnung der aufgezeichneten Werte in eine Spannung
  voltage0 = (adc0 * gain_conversion_factor);
  voltage1 = (adc1 * gain_conversion_factor);
  voltage2 = (adc2 * gain_conversion_factor);
  voltage3 = (adc3 * gain_conversion_factor);
  
  // Ausgabe der Werte auf die serielle Schnittstelle
  Serial.print("Analog Eingang 0: "); Serial.print(voltage0);Serial.println("mV");
  Serial.print("Analog Eingang 1: "); Serial.print(voltage1);Serial.println("mV");
  Serial.print("Analog Eingang 2: "); Serial.print(voltage2);Serial.println("mV");
  Serial.print("Analog Eingang 3: "); Serial.print(voltage3);Serial.println("mV");
  Serial.println("------------------------");
  
  delay(1000);
}
