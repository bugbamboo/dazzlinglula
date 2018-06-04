#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


// constants won't change. They're used here to set pin numbers:
const int buttonPinRight = 4; 
const int buttonPinLeft = 2;
const int buttonPinUp = 10;
const int buttonPinDown = 5;
// the number of the pushbutton pin

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
variables will change:
int buttonStateLeft = 0; 
int buttonStateRight = 0;
int buttonStateUp = 0;
int buttonStateDown = 0;
// variable for reading the pushbutton status

//variable to hold data
int sup = 0;

void setup() {
  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPinRight, INPUT);
  pinMode(buttonPinLeft, INPUT);
  pinMode(buttonPinUp, INPUT);
  pinMode(buttonPinDown, INPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateRight = digitalRead(buttonPinRight);
  buttonStateLeft = digitalRead(buttonPinLeft);
  buttonStateUp = digitalRead(buttonPinUp);
  buttonStateDown = digitalRead(buttonPinDown);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonStateRight == 1) 
  {
    sup = 4;
    Serial.write("4");
  } 
  else if(buttonStateLeft == 1)
  {
    sup = 3;
    Serial.write("3");
  } 
  else if (buttonStateUp == 1) {
    sup = 1;
    Serial.write("1");
  } 
  else if (buttonStateDown == 1) 
  {
    sup = 2;
    Serial.write("2");
  } 
  else 
  {
    sup = 0;
    Serial.write("0");
  }

  
radio.write(&sup, sizeof(sup));
}
