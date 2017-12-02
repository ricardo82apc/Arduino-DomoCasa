#include <DHT.h>; //incluir libreria al proyecto.
#define DHTTEMP 4 //pin donde se conectara dato de sensor.
#define DHTTYPE DHT22 //definir que modelo de sensor se utilizara.
DHT dht(DHTTEMP, DHTTYPE); //inicializar variable para comunicar arduino y sensor.
int MOTOR = 5; //crear pin y variable de motor.
int PIR = 2; //crear pin y variable de sensor. 
int LUZ = 13; //crear pin y variable de luz.

void setup(){
  Serial.begin(9600); //inicializar ventana serial(solo muestra datos).
  dht.begin(); //inicializar sensor.
  pinMode(MOTOR, OUTPUT);//inicializar variable motor como dato de salida.
  pinMode(PIR, INPUT); //inicializar variable sensor como dato de entrada.
  pinMode(LUZ, OUTPUT); //inicializar variable luces como dato de salida.
}

void loop(){
  float h = dht.readHumidity(); //crea variable que almacena dato de humedad desde sensor.
  float t = dht.readTemperature(); //crea variable que almacena dato de temperatura desde sensor.
  Serial.print("Humedad: "); //imprime el texto "Humedad" en pantalla PC.
  Serial.println(h);//imprime el dato almacenado en la variable "h"(humedad).
  Serial.print("Temperatura: ");//imprime el texto "Temperatura" en pantalla PC.
  Serial.println(t);//imprime el dato almacenado en la variable "t"(temperatura).
  delay(5000); //espera 5 segundos para volver a tomar otra lectura
  
  // VALIDACION PARA SENSOR DE TEMPERATURA
  if(t <= 24){ //validacion: si temperatura es menor o igual a 20°
    digitalWrite(MOTOR, LOW); //apaga motor
  }
  if(t > 24){ //validacion: si temperatura es mayor a 20°
   digitalWrite(MOTOR, HIGH); //enciende motor
  }

  // VALIDACION PARA SENSOR PIR
  if(digitalRead(PIR) == HIGH){ //validacion: si sensor PIR detecta accion
    digitalWrite(LUZ, HIGH); //enciende luz
  }
  if(digitalRead(PIR) == LOW){ //validacion: si sensor PIR no detecta accion
    digitalWrite(LUZ, LOW); //apaga luz
  }
}  
