// NOTA: INSTALAR LIBRERÍA DHT
// Programa --> Incluír libería --> Administrar Bibliotecas --> DHT Sensor library

#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT11   // Escribir DHT11 o DHT22 según sea el caso.

DHT dht(DHTPIN, DHTTYPE);

void setup() {
   Serial.begin(9600);
   delay(10);
   Serial.println("\nPrograma 2_SenorLocal");
   
   dht.begin();
}

void loop() {

  float t = dht.readTemperature();
  float h = dht.readHumidity();  

  if (isnan(h) || isnan(t)) {
    Serial.println("SENSOR NO ENCONTRADO... REVISAR CONEXIÓN");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(t);

  Serial.print("\tHumedad: ");
  Serial.println(h);

  delay(2000);
}
