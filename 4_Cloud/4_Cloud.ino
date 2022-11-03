// NOTA: INSTALAR LIBRERÍA Adafuit
// Programa --> Incluír libería --> Administrar Bibliotecas --> Adafruit IO Arduino (4.2.3)


#include "DHT.h"
#include "config.h"

#define DHTPIN 13
#define DHTTYPE DHT11   // Escribir DHT11 o DHT22 según sea el caso.

#define blueLED 02

DHT dht(DHTPIN, DHTTYPE);
AdafruitIO_Feed *humidity = io.feed("humedad");
AdafruitIO_Feed *temperature = io.feed("temperatura");


void setup() {
   Serial.begin(9600);
   delay(10); 
   Serial.println("Connecting to Cloud");    

   pinMode(blueLED, OUTPUT);
   dht.begin();

   io.connect();
   while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());   
}

void loop() {

  io.run();
  
  float t = dht.readTemperature();
  float h = dht.readHumidity();    

  if (isnan(h) || isnan(t)) {
    Serial.println("SENSOR NO ENCONTRADO... REVISAR CONEXIÓN");
    return;
  }
  
  if(h>50){
    digitalWrite(blueLED, !HIGH);
  }
  else{
    digitalWrite(blueLED, !LOW);
  }  
  
  Serial.print("sending -> ");
  Serial.println(h);
  Serial.print("sending -> ");
  Serial.println(t);

  humidity ->save(h);
  temperature ->save(t);
  delay(5000);
}
