#include <EEPROM.h>

const int v=A0,v1=A1,v2=A2,v3=A3;   //this is push button for swich
int p=2;  //Output pin for relay
int s=0;  //veriable for storing input

int s1=0; //veriable for storing input
int s2=0; //veriable for storing input
int s3=0; //veriable for storing input
bool q=EEPROM.read('eeprom');
bool g=!q; //signal for relay
void setup(){
   pinMode(v,INPUT);
   pinMode(v1,INPUT);
   pinMode(v2,INPUT);
   pinMode(v3,INPUT);
  pinMode(p,OUTPUT);   
  Serial.begin(9600);
}

void loop(){
  
  s=digitalRead(v);
  s1=digitalRead(v);
  s2=digitalRead(v);
  s3=digitalRead(v);
  if(s==1 || s1==1 || s2==1 || s3==1){
    digitalWrite(p,g);
    EEPROM.write('eeprom',g); 
    g=!g;
   Serial.print("if");
 Serial.println(g);
    delay(1000);
  }

  else{
    Serial.println(EEPROM.read('eeprom'));
   digitalWrite(p,EEPROM.read('eeprom'));
    
  }

 


 
}
