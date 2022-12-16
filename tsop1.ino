#include<IRremote.h>
int recv_pin=3;
#define led1 4
#define led2 5
#define led3 6
unsigned int value;
IRrecv irrcev(recv_pin);
decode_results result;
int onled[]={0,0,0,0};
//define pin value
#define codeR 8415
#define codeG 41055
#define codeB 24735

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrcev.enableIRIn();
  Serial.println("Ir data ");
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrcev.decode(&result)){
    value=result.value;
    Serial.print("data: ");
    Serial.println(value);
    switch(value){
      case codeR:
          if(onled[1]==1){
            digitalWrite(led1,0);
            onled[1]=0;
          }
          else{
            digitalWrite(led1,1);
            onled[1]=1;
            }
        break;
      case codeG:
          if(onled[2]==1){
            digitalWrite(led2,0);
            onled[2]=0;
          }
          else{
            digitalWrite(led2,1);
            onled[2]=1;
            }
        break;
      case codeB:
            if(onled[3]==1){
            digitalWrite(led3,0);
            onled[3]=0;
          }
          else{
            digitalWrite(led3,1);
            onled[3]=1;
            }
         break;
      }
    irrcev.resume();
  }
  delay(10);
}
