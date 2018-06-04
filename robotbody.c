
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <ArduinoRobot.h>

const int motorRight = 2;
const int motorLeft = 4;
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  pinMode(motorRight, OUTPUT);
  pinMode(motorLeft, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  Robot.begin();
}
void loop() {
  int superman = 0;
  if (radio.available()) {
    int sup = 0;
    radio.read(&sup, sizeof(sup));
    superman = sup;
  }
    
  if (superman = 4){
    Robot.motorsWrite(255,-255);
    Serial.write("4");
  }
  if (superman = 3){
    Robot.motorsWrite(-255,255);
    Serial.write("3");
  }
  if (superman = 2){
    Robot.motorsWrite(-255,-255);
    Serial.write("2");
  }
  if (superman = 1){
    Robot.motorsWrite(255,255);
    Serial.write("1");
  }
  if (superman = 0){
    Robot.motorsWrite(0,0);
    Serial.write("0");
  }
  
   
  
}
