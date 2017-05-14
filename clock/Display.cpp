#include "Display.h"



Display::Display(){
	byte numDigits = 4;
	byte digitPins[] = {0, 1, 2, 3};
	byte segmentPins[] = {4, 5, 6, 7, 8, 9, 10, 11};
	bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
	byte hardwareConfig = COMMON_CATHODE; // See README.md for options
	bool updateWithDelays = false; // Default. Recommended
	bool leadingZeros = true; // Use 'true' if you'd like to keep the leading zeros

	sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
	sevseg.setBrightness(90);
	
}

void Display::setNumber(int number,int decimalIndex){
	sevseg.setNumber(number, decimalIndex);
}


void Display::update(){
	sevseg.refreshDisplay(); // Must run repeatedly	
}