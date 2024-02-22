#include "SevSeg.h"




SevSeg sevseg;       //Instanciamos el object
//se genera un problema a partir del valor 32759
int hora=13;
int minuto=57;
int segundo=30;
unsigned long tiempo1=0;  
unsigned long tiempo2=0;
long actual=0;


void setup() 
{
   byte hardwareConfig = N_TRANSISTORS;  //Indica que es cátodo común con NPN
   byte numDigits = 6;
   byte digitPins[] = {8,9,10,11,12,13}; //transistores
   byte segmentPins[] = {1,2,3,4,5,6,7,0};
   bool resistorsOnSegments = true;     //true indica que resistencia esta en el pin de segmento
   bool updateWithDelays = false;       //Recomendado
   bool leadingZeros = true;            //true muestra ceros a izquierda
  
   sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
   sevseg.setBrightness(60);            //Establece brillo a 90%
}


void loop()
{
 
un_seg (); //void un seg

   
contador(); //void contador
actual= ((hora*10000L)+(minuto*100)+(segundo)); 
sevseg.setNumber(actual,6); //convierte los valores hora, minuto y segundo en un unico valor permitiendo su uso con set number
sevseg.refreshDisplay(); // Must run repeatedly; don't use blocking code (ex: delay()) in the loop() function or this won't work right
}


void un_seg()
{
tiempo2=(millis()/1000);    
if ( tiempo1 != tiempo2 ) {
 tiempo1=tiempo2;
 segundo++;      
 }     
}
 
void contador(){

//rutina segundos 
if ( segundo == 61 ) {
segundo =0;
segundo++;} 
 
if ( ( segundo == 60 ) ) {
segundo =0;
minuto++;} 
 
 
// Rutina para los minutos
 
if (minuto == 61 ) {
minuto =0;
minuto++; } 
 
if ( ( minuto == 60 ) ) {
minuto =0;     
hora++;} 

// Rutina para las horas
 
if ( hora == 25 ) {
hora =0;
hora++; } 
 
if ( (hora == 24) ) {
hora =0;
minuto =0;
segundo =0; 
 } 
}
