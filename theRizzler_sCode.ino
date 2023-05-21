#include <dht.h>

dht DHT;

#define DHT11_PIN 2
float hum;
float temp;
const int buzzer = 4;

void setup(){
  Serial.begin(9600);
  pinMode(buzzer, 4);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  hum = DHT.humidity;
  temp = DHT.temperature;
  Serial.println(" ");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" ");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" ");

  if (temp > 20 && temp < 25) {
  Serial.print("Wound healing can occur! ");
  } else {
  Serial.print("Wound healing cannot occur! ");
    tone(buzzer, 4000, 3000); // Higher frequency for bad temp 
  }

    if (hum > 20 && hum < 25) { 
  Serial.print("Wound healing can occur! ");
  } else {
  Serial.print("Wound healing cannot occur! ");
    tone(buzzer, 2000, 3000); // Lower frequency for bad hum
  }

  Serial.println(" ");
  delay(1500);
}
