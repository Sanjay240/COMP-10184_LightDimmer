/**
 * I Sanjay Kumar, 000811237 certify that the given work is my own work and noone 
 * work is considered without professor acknowledgement.
 */ 

#include <Arduino.h>

 bool ledState = false; // global variable to set the led light state on/off
 bool buttonState = false; // global variable to set the button state on/off

void setup()
{

  // configure the USB serial monitor
  Serial.begin(115200);

  // configure pin D5 as digital input - this is the pushbutton
  pinMode(D5, INPUT_PULLUP);

  // configure pin D4 as a digital output - this is the LED
  pinMode(D4, OUTPUT);

  // set default PWM range
  analogWriteRange(1024);
  
}

void loop()
{
  int iButton; // stores the button value 0 or 1 
  int iVal; // stores the digital value of variable resister 1 to 1024
  

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);
  iButton = digitalRead(D5);
  
/**
 * Now I check the button value 0 when pressed and if button state is False then I enter
 * the if statement and change the led state to true and turn on the light. Else the 
 * button state is false and light is off.
 * When the led light is state is true then the light will get the digital value
 * and will change the brightness level.
 */
  if (iButton == 0 && buttonState == false)
  {
    buttonState = true;
    ledState = !ledState;
  }
  else if(iButton == 1 ){
    buttonState = false;
  }
  if(ledState == true){
     analogWrite(D4, iVal);
  }
  else{
    analogWrite(D4, 1024);
  }

}