// C++ code
//
#include <Adafruit_LiquidCrystal.h>
int IR1=4;
int IR2=12;

int led1=9;
int led2=10;
int led3=11;

int led4=3;
int led5=5;
int led6=6;

int trig1=13;
int echo1=8;
int trig2=2;
int echo2=7;

Adafruit_LiquidCrystal lcd(0);

void setup()
{
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  
  pinMode(trig1,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(echo2,INPUT);
  
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  
  lcd.begin(16,2);
  lcd.setBacklight(0);
  lcd.setBacklight(1);
  lcd.setCursor(0,0);
  lcd.print("vehicles should go");
  lcd.clear();
}
void loop(){
  
  int value1=digitalRead(IR1);
  int value2=digitalRead(IR2);
  
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH);delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  unsigned long duration=pulseIn(echo1,HIGH);
  float inches=duration*0.0132/2;
  float cm=duration*0.034/2;
  
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  unsigned long duration1=pulseIn(echo2,HIGH);
  float inches1=duration1*0.0132/2;
  float cm1=duration1*0.034/2;
  
  if (value1==HIGH && value2==LOW){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    lcd.print("WAY 1 GO....!");
    lcd.clear();
    lcd.print("GO SLOWLY...!");
  }
  else if (value1==LOW && value2==HIGH){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
    lcd.print("WAY 2 GO....!");
    lcd.clear();
    lcd.print("GO SLOWLY...!");
  }
  else if(value1==HIGH && value2==HIGH){
   if(cm1>cm){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    digitalWrite(led5,LOW);
    digitalWrite(led6,LOW);
    
    lcd.print("TRFFIC IS THERE");
    lcd.clear();
    lcd.print("WAY1 VEHICLES GO..!");
    delay(200);
    lcd.clear();
    lcd.print("AT A DISTANCE OF");
    lcd.clear();
    lcd.print(inches);
    lcd.print("inches");
    lcd.print(cm);
    lcd.print("cm");
    lcd.clear();
    lcd.print("GO SLOWLY...!");
    delay(1000);
    digitalWrite(led4,LOW);
    digitalWrite(led5,HIGH);
  
  }
  else{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    digitalWrite(led6,HIGH);
    
    lcd.print("TRAFFIC IS THERE");
    lcd.clear();
    lcd.print("WAY2 VEHICLES GO");
    delay(200);
    lcd.clear();
    lcd.print("AT A DISTANCE OF");
    lcd.clear();
    lcd.print(inches1);
    lcd.print("inches");
    lcd.print(cm1);
    lcd.print("cm");
    lcd.clear();
    lcd.print("GO SLOWLY...!");
    delay(1000);
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
  
  }
 }
  
 else{
   digitalWrite(led3,HIGH);
   digitalWrite(led6,HIGH);
   lcd.print("NO TRAFFIC");
   lcd.clear();
   lcd.print("YOU CAN GO!");
   lcd.clear();
   lcd.print("GO SLOWLY...!");
   lcd.print("");
 }
    
  
}