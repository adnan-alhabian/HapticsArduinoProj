//#include <CapacitiveSensor.h>

#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(11,10);

int threshold = -1;
const int ledPin = 12;

const int LForward = 2; 
const int LBackward = 3;

const int RForward =4;
const int RBackward = 5;

const int threeForward = 6;
const int threeBackward = 7;

const int fourForward = 8;
const int fourBackward = 9;
  
const int iteration1[] = {2,4,6,8};

bool hasLooped = false;

long sensorValue;

int counter; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  //motor code
  pinMode(LForward, OUTPUT);
  pinMode(LBackward, OUTPUT);
  pinMode(RForward, OUTPUT);
  pinMode(RBackward, OUTPUT);
  pinMode(threeForward, OUTPUT);
  pinMode(threeBackward, OUTPUT);
  pinMode(fourForward, OUTPUT);
  pinMode(fourBackward, OUTPUT);

  digitalWrite(LBackward, LOW);
  digitalWrite(RBackward, LOW);
  digitalWrite(threeBackward, LOW);
  digitalWrite(fourBackward, LOW);

  /*while(counter != 6){
    long sensorValue = capSensor.capacitiveSensor(30);
    Serial.println(sensorValue);
    
    /*if(sensorValue > 200){
    digitalWrite(ledPin, HIGH);
    }
    int j = rand() % 4;
    digitalWrite(iteration1[j], HIGH);
    //delay(100); //possible can get rid of this
    Serial.println(sensorValue);
    if(sensorValue <= 200){
      digitalWrite(iteration1[j],LOW);
      }
    }
  
    else{
      Serial.print("it's done");
      digitalWrite(ledPin, LOW);
      }

    Serial.print(counter);
    counter++;
    }*/
  }
boolean touchSensor(){
  while(true){
    long sensorValue = capSensor.capacitiveSensor(30);
    Serial.println(sensorValue);
    if(sensorValue > 200){
      break;
    }
  }
  return true;
}

void loop() {  
  
    for (int i = 0; i < 10; i++){
      Serial.println("Level 1");
      int j = rand() % 4;
      digitalWrite(iteration1[j], HIGH);
      boolean var1 = touchSensor();
      if(var1 == true){
        digitalWrite(ledPin,HIGH);
        digitalWrite(iteration1[j],LOW);
        int j = rand() % 4;
        delay(500);
        }
    else{
      digitalWrite(ledPin,LOW);
    }
    if(i == 9){
      digitalWrite(ledPin,LOW);
      exit(0);}
    }
}
