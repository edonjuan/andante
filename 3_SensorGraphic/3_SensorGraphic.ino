// NOTA: INSTALAR LIBRERÍA DHT
// Programa --> Incluír libería --> Administrar Bibliotecas --> DHT Sensor library

#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT11   // Escribir DHT11 o DHT22 según sea el caso.

#define blueLED 02

DHT dht(DHTPIN, DHTTYPE);

void setup() {
   Serial.begin(9600);
   delay(10);   

   pinMode(blueLED, OUTPUT);
   dht.begin();
}

void loop() {

  float t = dht.readTemperature();
  float h = dht.readHumidity();    

  if (isnan(h) || isnan(t)) {
    Serial.println("SENSOR NO ENCONTRADO... REVISAR CONEXIÓN");
    return;
  }
  
  Serial.println(h);

  if(h>50){
    digitalWrite(blueLED, !HIGH);
  }
  else{
    digitalWrite(blueLED, !LOW);
  }
  
  delay(500);
}
