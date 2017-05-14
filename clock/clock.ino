#include "Beeper.h"
#include "Display.h"

const int RED_LED = A7;
const int YELLOW_LED = A6;
const int GREEN_LED = A5;
const int LEFT_BUTTON = A4;
const int RIGHT_BUTTON = A3;
const int MIDDLE_BUTTON = A2;
const int BUZZER = A1;
const int MIDDLE_LED = A0;

Beeper beeper(BUZZER);
Display disp;

int timerTime = 360; //standard 6 minutes for an egg

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(MIDDLE_LED,OUTPUT);
  for (int i=A0; i<=A5; i++){
    digitalWrite(i,LOW);
  }

  enableInterrupt(MIDDLE_BUTTON);
  enableInterrupt(LEFT_BUTTON);
  enableInterrupt(RIGHT_BUTTON);  

  updateTimerTime();
}


int timerTick = timerTime;
long lastPressTimestamp = 0;
long lastTick = 0;
boolean timerActive = false;

void loop() {
  disp.update();
  
  if(isPressing() && acceptButtonThreshold()){
    handleButtonPresses();
    lastPressTimestamp = millis();
  }
  if(timerTick <= 0 && timerActive){
    beeper.play();
    timerActive = false;
    updateTimerTime();
  }
  else if(lastTick + 1000 < millis() && timerActive){
    timerTick-=1;
    updateTimerTime();
    lastTick = millis();
  }

  if(timerTick <= 10 && timerTick % 2 && timerActive){
    digitalWrite(MIDDLE_LED,HIGH);
  }else{
    digitalWrite(MIDDLE_LED,LOW);
  }

}

boolean acceptButtonThreshold(){
  return lastPressTimestamp + 350 < millis();
}



boolean isPressing(){
  return analogRead(MIDDLE_BUTTON) || analogRead(LEFT_BUTTON) || analogRead(RIGHT_BUTTON);
}


void handleButtonPresses(){
  boolean pressMiddle = analogRead(MIDDLE_BUTTON);
  boolean pressLeft = analogRead(LEFT_BUTTON);
  boolean pressRight = analogRead(RIGHT_BUTTON);

  int timeIncrease = 0;
  
  if(pressLeft && pressRight){
    timerTime = 0;
    timerTick = 0;
  }else if(pressLeft){
    timeIncrease = 60;
  }else if(pressRight){
    timeIncrease = 15;
  }else if(pressMiddle){
    timerActive = !timerActive;
    timerTick = timerTime;
  }
  
  //max time
  if(timerTime > 60*99){
    timerTime = 60*99;
  }

  if(timerActive){
    timerTick += timeIncrease;
  }else{
    timerTime += timeIncrease;
  }
  
  updateTimerTime();
}


void updateTimerTime(){
  int time = 0;

  if(timerActive){
    time = timerTick;
  }else{
    time = timerTime;
  }
  
  int minutes = time / 60;
  int seconds = time % 60;
  String minutesString = String(minutes);
  String secondsString = String(seconds);

  if(secondsString.length() == 1){
    secondsString = "0" + secondsString;
  }
  
  String timeString = minutesString + secondsString;
  int convertedTime = timeString.toInt();
  disp.setNumber(convertedTime, 2);
}


void enableInterrupt(byte pin){
  *digitalPinToPCMSK(pin) |= bit(digitalPinToPCMSKbit(pin));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

// handle pin change interrupt for A0 to A5 here
ISR (PCINT1_vect){ 
  beeper.stop();
  digitalWrite(MIDDLE_LED,LOW);
}


