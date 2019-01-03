#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 4, 5, 6, 7,9);
int Htime;              //integer for storing high time
int Ltime;                //integer for storing low time
float dutyCycle;
float Ttime;            // integer for storing total time of a cycle
float frequency=0;        //storing frequency
float lastFrequency=0;
float Sensibilidad=0.066; //sensibilidad en Voltios/Amperio para sensor de 5A
float I=0,lastI=0;
float offset=0.240; // Equivale a la amplitud del ruido

void setup()
{
    pinMode(8,INPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
}
void loop()
{
    //lcd.clear();
   
    Serial.print("Frequency of signal:  ");
    Htime=pulseIn(8,HIGH);      //read high time
    Ltime=pulseIn(8,LOW);        //read low time
    
    Ttime = Htime+Ltime;
    frequency=1000000/Ttime;    //getting frequency with Ttime is in Micro seconds
    dutyCycle = Htime/Ttime;
    //lcd.setCursor(0,1);
    //lcd.print(frequency);
   
    if(frequency<1){frequency=1;}
    if(frequency > lastFrequency+1 || frequency < lastFrequency-1){
    //
//lcd.clear();
     lcd.setCursor(0,0);
    lcd.print("Freq: ");
    lcd.print(frequency,0);
    lcd.print(" Hz   ");
    Serial.print(frequency);
    Serial.print(" Hz");
    Serial.println("");
    //lcd.print(" Hz");
    lastFrequency=frequency;
    delay(300);
    }

    lcd.setCursor(0,1);
    lcd.print("V:");
    lcd.print(dutyCycle*150,0);
    lcd.print(" ");
    lcd.print("I:");
    lcd.print(get_corriente(5),2);
/*
     I=get_corriente(20);//obtenemos la corriente promedio de 500 muestras 
    //float Ip=get_corrienteP();//obtenemos la corriente pico
  //float Irms=Ip*0.707; //Intensidad RMS = Ipico/(2^1/2)
   if(I>lastI+0.03|| I<lastI-0.03){
    lcd.setCursor(0,1);
    lcd.print("I: ");
    lcd.print(I,2);
    lastI=I;
   }*/
}


float get_corriente(int n_muestras)
{
  float voltajeSensor;
  float corriente=0;
//  for(int i=0;i<n_muestras;i++)
 // {
    voltajeSensor = analogRead(A1) * (1.0 / 1023.0);////lectura del sensor
    
 // }
  corriente=voltajeSensor;
  return(corriente);
}



float get_corrienteP()
{
  float voltajeSensor;
  float corriente=0;
  long tiempo=millis();
  float Imax=0;
  float Imin=0;
  while(millis()-tiempo<200)//realizamos mediciones durante 0.5 segundos
  { 
    voltajeSensor = analogRead(A0) * (5.0 / 1023.0);//lectura del sensor
    corriente=0.9*corriente+0.1*((voltajeSensor-2.527)/Sensibilidad); //Ecuación  para obtener la corriente
    if(corriente>Imax)Imax=corriente;
    if(corriente<Imin)Imin=corriente;
  }
  return(((Imax-Imin)/2)-offset);
}

