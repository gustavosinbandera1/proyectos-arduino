
#include <ArduinoJson.h>
#include <EEPROM.h>





//ENTRADAS
const int in4_ManualAutomatico = A3;
const int in5_Start = A4;
const int in6_finalCarrera = A5;

const int in1_TumbarChancla = A0;
/*const int in2_ExpulsarChamcla = A1;
const int in3_SubirTanque = A2;
const int in4_SacudirChancla = A3;
const int in5_RotarChancla = A4;
const int in6_ManualAutomatico = A5;
const int in7_finalCarrera = 2;
const int in6_Start = 3;*/

//SALIDAS
const int out1_Banda = 6;
const int out2_Tanque = 7;
const int out3_Transportador = 8;
const int out4_Sacudida = 9;
const int out5_Tumbar = 10;
const int out6_Tumbar_ = 11;
const int out6_Indicador = 11;

 static int count_state = 0;



// this function generates an EV_TIME event
// each 500 ms
void timeManager() {
    static unsigned long prevMillis = 0;
    unsigned long currMillis;

    currMillis = millis();
    if (currMillis - prevMillis >= 500) {  ////para generar eventos cada 1 minuto
        prevMillis = currMillis;
    }
}


void setup() {
 

   pinMode(in4_ManualAutomatico, INPUT_PULLUP);
   pinMode(in6_finalCarrera,INPUT_PULLUP);
   pinMode(in5_Start, INPUT_PULLUP );
   pinMode(in1_TumbarChancla,INPUT_PULLUP);

  pinMode(out1_Banda, OUTPUT);
  pinMode(out2_Tanque, OUTPUT);
  pinMode(out3_Transportador, OUTPUT);
  pinMode(out4_Sacudida, OUTPUT);
  pinMode(out5_Tumbar, OUTPUT);
    pinMode(out6_Tumbar_, OUTPUT);
  pinMode(out6_Indicador, OUTPUT);

  digitalWrite(out1_Banda,LOW);
  digitalWrite(out2_Tanque,LOW);
  digitalWrite(out3_Transportador,LOW);
  digitalWrite(out4_Sacudida,LOW);
  digitalWrite(out5_Tumbar,LOW);

   Serial.begin(115200);


if(digitalRead(in6_finalCarrera)){
   while(digitalRead(in6_finalCarrera)){///mientras en final de carrera no este presionado
     digitalWrite(out3_Transportador,HIGH);
   }
}  
digitalWrite(out3_Transportador,LOW);
  

  


}

void loop() {


if(digitalRead(in4_ManualAutomatico ) == 1){  //automatico

  if(!digitalRead(in5_Start)){
       digitalWrite(out3_Transportador,HIGH);
       delay(3000);
       
 
    while(digitalRead(in6_finalCarrera)){
       digitalWrite(out3_Transportador,HIGH);
    }
    digitalWrite(out3_Transportador,LOW);
    delay(400);
    
    digitalWrite(out2_Tanque,HIGH );
    delay(5000);
    digitalWrite(out2_Tanque, LOW);
    delay(1000);
    digitalWrite(out4_Sacudida,HIGH);
    digitalWrite(out6_Tumbar_,HIGH);
     digitalWrite(out1_Banda,HIGH);
    delay(2000);
     digitalWrite(out6_Tumbar_,LOW);
   
    delay(4000);
     digitalWrite(out4_Sacudida,LOW);
   
    digitalWrite(out1_Banda,LOW);
    
    
  }
  
  
}

if(digitalRead(in4_ManualAutomatico ) == 0){  //manual
   if(!digitalRead(in5_Start)){
       digitalWrite(out3_Transportador,HIGH);
       delay(3000);
       
 
    while(digitalRead(in6_finalCarrera)){
       digitalWrite(out3_Transportador,HIGH);
    }
    digitalWrite(out3_Transportador,LOW);
    delay(400);
    
    //digitalWrite(out2_Tanque,HIGH );
   // delay(4500);
   // digitalWrite(out2_Tanque, LOW);
    //delay(400);
    //digitalWrite(out4_Sacudida,HIGH);
    digitalWrite(out6_Tumbar_,HIGH);
    digitalWrite(out1_Banda,HIGH);
    delay(3000);
     digitalWrite(out4_Sacudida,LOW);
    digitalWrite(out6_Tumbar_,LOW);
    digitalWrite(out1_Banda,LOW);
    
    
  }
  
  
}




}
