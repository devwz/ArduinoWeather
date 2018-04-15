
//
// Arduino Weather
// Made by DevWz || Wellington Antonio Zaneze
//

// Inclui bibliotecas
#include "DHT.h"

class Higrometro
{
  const int pin;
  public:
    int solo;

    int getPin() { return pin; }
    Higrometro(int pin) { pin = pin; }
};


#define DHTPIN A1
#define DHTTYPE DHT11

Higrometro higrometro(A2);
DHT dht(DHTPIN, DHTTYPE);

// A rotina de configuração é executada uma vez quando o reset é pressionado:
void setup()
{
    Serial.begin(9600);
    pinMode(higrometro.getPin(), INPUT);
    dht.begin();
}

// A rotina de loop é executada repetidamente para sempre:
void loop()
{

  delay(2048);

  int h = dht.readHumidity();
  int t = dht.readTemperature();

  higrometro.solo = analogRead(higrometro.getPin());

  Serial.print("{");
  Serial.print(" \"umidade\" : ");
  Serial.print(h);
  Serial.print(",");
  Serial.print(" \"temperatura\" : ");
  Serial.print(t);
  Serial.print(",");
  Serial.print(" \"solo\" : ");
  
  if (higrometro.solo > 0 && higrometro.solo < 400)
  {
    Serial.print("\"Umido\"");
  }
  else if (higrometro.solo > 400 && higrometro.solo < 800)
  {
    Serial.print("\"Moderado\"");
  }
  else if (higrometro.solo > 800 && higrometro.solo < 1024)
  {
    Serial.print("\"Seco\"");
  }
  
  Serial.println("}");
  
}

