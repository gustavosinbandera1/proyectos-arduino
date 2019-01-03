#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3, 4, 9,10,11,12);
#include <EEPROM.h>

int releOut = 7;
int reset_ = 6;
int sensor = 5;
long  contador;
void setup() {

  pinMode(releOut,OUTPUT);
  pinMode(reset_,INPUT);
  pinMode(sensor,INPUT);
  digitalWrite(sensor,HIGH);
  digitalWrite(reset_,HIGH);
  // put your setup code here, to run once:
 Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("INDUSTRIAS EVA");
    lcd.setCursor(0,1);
    lcd.print("Cantidad: ");
    contador = EEPROMReadlong(0);
     lcd.setCursor(10,1);
      lcd.print(contador);
       lcd.print("  ");
}

void loop() {
  // put your main code here, to run repeatedly:
 

  if(!digitalRead(sensor)){//si van a taladrar

    //prender motor
    digitalWrite(releOut,HIGH);
    contador++;
      EEPROMWritelong(0, contador);
    lcd.setCursor(10,1);
    lcd.print(contador);
    lcd.print("  ");
    while(!digitalRead(sensor)){}
    delay(300);    
  }
  else{
    digitalWrite(releOut,LOW);
  }

  if(!digitalRead(reset_)){
    contador =0;
     EEPROMWritelong(0, 0);
      lcd.setCursor(10,1);
      lcd.print(0);
       lcd.print("  ");
    
  }
  
 }
 
   
void EEPROMWritelong(int address, long value)
      {
      //Decomposition from a long to 4 bytes by using bitshift.
      //One = Most significant -> Four = Least significant byte
      byte four = (value & 0xFF);
      byte three = ((value >> 8) & 0xFF);
      byte two = ((value >> 16) & 0xFF);
      byte one = ((value >> 24) & 0xFF);

      //Write the 4 bytes into the eeprom memory.
      EEPROM.write(address, four);
      EEPROM.write(address + 1, three);
      EEPROM.write(address + 2, two);
      EEPROM.write(address + 3, one);
      
 }


 long EEPROMReadlong(long address)
      {
      //Read the 4 bytes from the eeprom memory.
      long four = EEPROM.read(address);
      long three = EEPROM.read(address + 1);
      long two = EEPROM.read(address + 2);
      long one = EEPROM.read(address + 3);

      //Return the recomposed long by using bitshift.
      return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
      }


