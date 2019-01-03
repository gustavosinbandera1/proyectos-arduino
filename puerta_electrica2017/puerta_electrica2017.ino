

/*
 * 
 /*
 el final de carrera para abrir y cerrar debe tener la linea 
 comun conectada a vcc,
 el pulso de open y close llega desde el modulo de RF, se 
 utilizaran las teclas A Y B
 */
const int finalClose = 6;
const int finalOpen = 12;
const int openPulse = 10;
const int closePulse = 8;
const int closeDoor = 2;
const int openDoor = 3;
const int enableOut = 5;
void setup() {
  // put your setup code here, to run once:
pinMode(finalClose,INPUT);
pinMode(finalOpen, INPUT);
pinMode(openPulse,INPUT);
pinMode(closePulse,INPUT);
pinMode(closeDoor,OUTPUT);
pinMode(openDoor,OUTPUT);
pinMode(enableOut,OUTPUT);
digitalWrite(enableOut,LOW);
digitalWrite(openDoor,LOW);
digitalWrite(closeDoor,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

if(digitalRead(openPulse)){// dan la orden de abrir la puerta 
   digitalWrite(openDoor,HIGH);
   delay(150);
   digitalWrite(enableOut,HIGH);
   delay(300);
   while(1){
      if(!digitalRead(finalOpen)){
        digitalWrite(enableOut,LOW);
        delay(100);
        digitalWrite(openDoor,LOW);
        break;
      }
      if(digitalRead(openPulse)){//si la puerta se esta abriendo y dan la orden de abrir nuevamente , la puerta se debe detener
        digitalWrite(enableOut,LOW);
        delay(100);
        digitalWrite(openDoor,LOW);
        delay(300);
        break;
      }
   }
}


if(digitalRead(closePulse)){// dan la orden de cerrar la puerta 
  
   digitalWrite(closeDoor,HIGH);
   delay(150);
   digitalWrite(enableOut,HIGH);
   delay(300);
   while(1){
      if(!digitalRead(finalClose)){
        digitalWrite(enableOut,LOW);
        delay(100);
        digitalWrite(closeDoor,LOW);
        break;
      }
      if(digitalRead(closePulse)){//si la puerta se esta cerrando y dan la orden de cerrar nuevamente , la puerta se debe detener
        digitalWrite(enableOut,LOW);
        delay(100);
        digitalWrite(closeDoor,LOW);
        delay(300);
        break;
      }
   }
}






}
