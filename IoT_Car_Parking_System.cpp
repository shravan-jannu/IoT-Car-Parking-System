#define BLYNK_TEMPLATE_ID "TMPL3SILhBdPF"
#define BLYNK_TEMPLATE_NAME "car parking"
#define BLYNK_AUTH_TOKEN "VJJBaIAHg3Rrx6msRADHpoj2j7T6sz05"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>
Servo servo1;
Servo servo2;
char auth[] = "VJJBaIAHg3Rrx6msRADHpoj2j7T6sz05";
char ssid[] = "Shravan";
char pass[] = "india123";

#define CAR1   D1         
#define CAR2   D2   
#define CAR3   D3
#define ENT    D6
#define EXT    D5
#define BUZ    D7

WidgetLED led1(V0);
WidgetLED led2(V1);
WidgetLED led3(V2);
int flag1=0;
int flag2=0;
int flag3=0;
void setup()
{
  Serial.begin(9600);
  Serial.println("WELCOME"); 
  servo1.attach(D4); // NodeMCU D4 pin   
  servo2.attach(D0); // NodeMCU D0 pin    
  pinMode(CAR1, INPUT);  
  pinMode(CAR2, INPUT);
  pinMode(CAR3, INPUT);  
  pinMode(BUZ, OUTPUT);   
  pinMode(ENT, INPUT);    
  pinMode(EXT, INPUT);   
  digitalWrite(BUZ,LOW);  
  Blynk.begin(auth, ssid, pass);
  servo1.write(180);
  delay(500);
  servo2.write(180); 
  delay(500);      
}
 
void loop()
{
  Blynk.run();
  if(digitalRead(CAR1)==LOW)
  {
  led1.on(); 
//  Serial.println("SLOT1 IS FULL");
  flag1=1;
  }
  else
  {
  led1.off();   
 // Serial.println("SLOT1 IS EMPTY"); 
  flag1=0;
  }
  if(digitalRead(CAR2)==LOW)
  {
  led2.on(); 
//  Serial.println("SLOT2 IS FULL");
  flag2=1;
  }
  else
  {
  led2.off();   
//  Serial.println("SLOT2 IS EMPTY"); 
  flag2=0;
  }
  if(digitalRead(CAR3)==LOW)
  {
  led3.on(); 
//  Serial.println("SLOT3 IS FULL");
  flag3=1;
  }
  else
  {
  led3.off();   
//  Serial.println("SLOT3 IS EMPTY"); 
  flag3=0;
  }    
  if(digitalRead(ENT)==LOW)
  {  
  Serial.println("ENTRY IR");   
  if((flag1==0)||(flag2==0)||(flag3==0))  
  {
  servo1.write(0);
  digitalWrite(BUZ,HIGH);    
  delay(5000);  
  servo1.write(180);
  digitalWrite(BUZ,LOW);    
  delay(500);     
  }
  }
  if(digitalRead(EXT)==LOW)
  {  
  Serial.println("EXIT IR");    
  servo2.write(0);
  digitalWrite(BUZ,HIGH);    
  delay(5000);  
  servo2.write(180);
  digitalWrite(BUZ,LOW);    
  delay(500);     
  }

}
