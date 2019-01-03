 /*
 The circuit:
 * LCD RS pin to digital pin 12       4
 * LCD Enable pin to digital pin 11   6
 * LCD D4 pin to digital pin 5        7
 * LCD D5 pin to digital pin 4        8
 * LCD D6 pin to digital pin 3        9
 * LCD D7 pin to digital pin 2        10
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)*/

#include <LiquidCrystal.h>

//LiquidCrystal lcd(4, 6, 7, 8, 9, 10);
long tiempo;
int disparador = 3;   // triger
int entrada = 2;      // echo
float distancia;

void setup()
{
   for(int i=4;i<11;i++){
    pinMode(i,OUTPUT);
   }
  pinMode(disparador, OUTPUT);
  pinMode(entrada, INPUT);
  
  //lcd.begin(16, 2);
  Serial.begin(9600);
  //lcd.print("   Distancia");
  
}


void loop()
{
  // lanzamos un pequeño pulso para activar el sensor
  digitalWrite(disparador, HIGH);
  delayMicroseconds(10);
  digitalWrite(disparador, LOW);
  
  // medimos el pulso de respuesta
  tiempo = (pulseIn(entrada, HIGH)/2); // dividido por 2 por que es el 
                                       // tiempo que el sonido tarda
                                       // en ir y en volver
  // ahora calcularemos la distancia en cm
  // sabiendo que el espacio es igual a la velocidad por el tiempo
  // y que la velocidad del sonido es de 343m/s y que el tiempo lo 
  // tenemos en millonesimas de segundo
  distancia = float(tiempo * 0.0343);
  
  // y lo mostramos por el puerto serie una vez por segundo
  Serial.println(distancia);
  
 // lcd.setCursor(1,1);
 // lcd.print(distancia);lcd.print("  cm   ");
  delay(300);
}
