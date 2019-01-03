
const int subirPrensa = 2;
const int bajarPrensa = 3;
const int statusSubir = 19;//a1
const int statusBajar = 21;
const int finalOpen = 18;//a0
const int delayBajarPin = 20;
const int sw1 = 4;
const int sw2 = 5;
const int status_ = 15;
int retardoSubirPrensa=0;
int retardoBajarPrensa=0;

void testSwitchs(void);
void testTrimmer(void);
void testPot(void);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(subirPrensa,OUTPUT);
pinMode(bajarPrensa,OUTPUT);
pinMode(statusSubir,OUTPUT);
pinMode(statusBajar,OUTPUT);
pinMode(finalOpen,INPUT);
pinMode(delayBajarPin,INPUT);
pinMode(status_,OUTPUT);

//turn of all pins declared as output in this project
digitalWrite(subirPrensa,LOW);
digitalWrite(bajarPrensa,LOW);
digitalWrite(statusSubir,LOW);
digitalWrite(statusBajar,LOW);

}

void loop() {
  //retardoSubirPrensa = analogRead(delaySubirPin);
  //delay(10);
  retardoBajarPrensa = analogRead(delayBajarPin);
 
  delay(10);
  retardoBajarPrensa = map(retardoBajarPrensa,0,1400,0,550);
   retardoSubirPrensa = retardoBajarPrensa;


   
 if(retardoBajarPrensa>=300 && retardoBajarPrensa<341){
 retardoSubirPrensa = (retardoSubirPrensa*2)+90;
 }/*
 else if(retardoBajarPrensa>=320 && retardoBajarPrensa<330){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
else if(retardoBajarPrensa>=310 && retardoBajarPrensa<320){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=300 && retardoBajarPrensa<310){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=290 && retardoBajarPrensa<300){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=280 && retardoBajarPrensa<290){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=270 && retardoBajarPrensa<280){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=260 && retardoBajarPrensa<270){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=250 && retardoBajarPrensa<260){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=240 && retardoBajarPrensa<250){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=230 && retardoBajarPrensa<240){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=220 && retardoBajarPrensa<230){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=210 && retardoBajarPrensa<220){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=200 && retardoBajarPrensa<210){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=190 && retardoBajarPrensa<200){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=180 && retardoBajarPrensa<190){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=170 && retardoBajarPrensa<180){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=160 && retardoBajarPrensa<170){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=150 && retardoBajarPrensa<160){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=140 && retardoBajarPrensa<150){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
 else if(retardoBajarPrensa>=130 && retardoBajarPrensa<140){
  retardoSubirPrensa = (retardoSubirPrensa*2) + 100;
 }
*/



  
  Serial.println(retardoSubirPrensa);
  Serial.println(retardoBajarPrensa);
  if(!digitalRead(sw1) && !digitalRead(sw2)){ //press buttons to same time 
   digitalWrite(status_,HIGH);
    digitalWrite(statusBajar,HIGH);
    digitalWrite(bajarPrensa,HIGH);//
    delay(retardoBajarPrensa);
    digitalWrite(bajarPrensa,LOW);
    digitalWrite(statusBajar,LOW);
    delay(100); 

     digitalWrite(statusSubir,HIGH);
    digitalWrite(subirPrensa,HIGH);//
  //  delay(retardoBajarPrensa);
 // delay(680);
// delay(retardoSubirPrensa );
    while(!digitalRead(finalOpen))
    {
      //no haga nada
    }
 
    digitalWrite(subirPrensa,LOW);
    digitalWrite(statusSubir,LOW);
    delay(200);  //dead time
    delay(100);
    
  }
    digitalWrite(status_,LOW);



//testSwitchs();

  
}



void testSwitchs(void){
  if(!digitalRead(sw1)){
      digitalWrite(subirPrensa,HIGH);//
  digitalWrite(statusSubir,HIGH);
  }else{
  digitalWrite(statusSubir,LOW);
    digitalWrite(subirPrensa,LOW);//
  }

  

  if(!digitalRead(sw2)){
    digitalWrite(statusBajar,HIGH);
      digitalWrite(bajarPrensa,HIGH);//
  }else{
    digitalWrite(statusBajar,LOW);
      digitalWrite(bajarPrensa,LOW);//
  }
}

void testTrimmer(void){
  /*retardoSubirPrensa = analogRead(delaySubirPin);
  
  // put your main code here, to run repeatedly:
  digitalWrite(statusSubir,HIGH);
  delay(retardoSubirPrensa);
  digitalWrite(statusSubir,LOW);
  delay(retardoSubirPrensa);
*/
  
}

void testPot (void){
  retardoBajarPrensa = analogRead(delayBajarPin);
  Serial.println(retardoBajarPrensa);
   digitalWrite(statusBajar,HIGH);
  delay(retardoBajarPrensa);
  digitalWrite(statusBajar,LOW);
  delay(retardoBajarPrensa);
}


/*
digitalWrite(subirPrensa,HIGH);
digitalWrite(bajarPrensa,HIGH);
delay(2000);
digitalWrite(subirPrensa,LOW);
digitalWrite(bajarPrensa,LOW);
delay(2000);*/



 /*
  retardoSubir = analogRead(delaySubirPin);
  // put your main code here, to run repeatedly:
  digitalWrite(status_,HIGH);
  digitalWrite(statusSubir,HIGH);
  digitalWrite(statusBajar,HIGH);
delay(retardoSubir);
   digitalWrite(status_,LOW);
  digitalWrite(statusSubir,LOW);
  digitalWrite(statusBajar,LOW);
delay(retardoSubir);*/
