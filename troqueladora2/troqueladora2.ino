
const int bajarPrensa = 2;
//const int finalOpen = 18;//a0

const int sw1 = 8;
const int sw2 = 9;
const int status_down = A2;//A2
const int link = A4; //A4

int delayBajarPin;
//int retardoBajarPrensa=0;
int retardoBajarPrensa;

void testSwitchs(void);
void testTrimmer(void);
void testPot(void);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bajarPrensa, OUTPUT);
  pinMode(status_down, OUTPUT);
   //digitalWrite(link,HIGH);  
   // digitalWrite(link,HIGH);  
  pinMode(link, OUTPUT);

  pinMode(delayBajarPin, INPUT);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);


  digitalWrite(bajarPrensa, LOW);
  digitalWrite(status_down, LOW);
  digitalWrite(link, LOW);

}

void loop() {

  retardoBajarPrensa = analogRead(delayBajarPin);
 //retardoBajarPrensa=1000;
  delay(10);
  retardoBajarPrensa = map(retardoBajarPrensa, 0, 1023, 130, 650);//650
  Serial.println(retardoBajarPrensa);

  if (digitalRead(sw1) && digitalRead(sw2)) { //press buttons to same time
    delay(150);
    if (digitalRead(sw1) && digitalRead(sw2)) {
      digitalWrite(status_down, HIGH);
      digitalWrite(bajarPrensa, HIGH); //
      delay(retardoBajarPrensa);
      digitalWrite(bajarPrensa, LOW);
      digitalWrite(status_down, LOW);
      delay(100);
       digitalWrite(status_down, LOW);
       while(digitalRead(sw1) || digitalRead(sw2)){
      digitalWrite(link,HIGH);
       }
        digitalWrite(link,LOW);
        delay(800);
  }
 }
 

 /*
 digitalWrite(bajarPrensa, HIGH);
 delay(1000);
 digitalWrite(bajarPrensa, LOW);
 delay(1000);
*/
  
 // testSwitchs();



}



void testSwitchs(void) {
  if (digitalRead(sw1)) {
    digitalWrite(link, HIGH); //
    digitalWrite(bajarPrensa, HIGH);
  } else {
    digitalWrite(link, LOW);
    digitalWrite(bajarPrensa, LOW);

  }



  if (digitalRead(sw2)) {
    digitalWrite(status_down, HIGH);
    digitalWrite(bajarPrensa, HIGH); //
  } else {
    digitalWrite(status_down, LOW);
    digitalWrite(bajarPrensa, LOW); //
  }
 
 /*digitalWrite(status_down, HIGH);
 digitalWrite(link, HIGH);
 delay(1000);
  digitalWrite(status_down, LOW);
  digitalWrite(link, LOW);
  delay(1000);
*/
  
}



void testPot (void) {
  retardoBajarPrensa = analogRead(delayBajarPin);
  Serial.println(retardoBajarPrensa);
  digitalWrite(status_down, HIGH);
  delay(retardoBajarPrensa);
  digitalWrite(status_down, LOW);
  delay(retardoBajarPrensa);
}



