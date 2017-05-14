#ifndef Beeper_H
#define Beeper_H

#include <Arduino.h>


class Beeper 
{

private:

  bool playing = false;
  int buzzerPin  = A1; //Had to hardcode this based on gcc error when adding a constructor
  
	/* Frequencies */
	/*const int c = 261;
	const int d = 294;
	const int e = 329;
	const int f = 349;
	const int g = 391;
	const int gS = 415;
	const int a = 440;
	const int aS = 455;
	const int b = 466;
	const int cH = 523;
	const int cSH = 554;
	const int dH = 587;
	const int dSH = 622;
	const int eH = 659;
	const int fH = 698;
	const int fSH = 740;
	const int gH = 784;
	const int gSH = 830;
	const int aH = 880;


	
	
	
	
	int starwarsFreq1[18] = {a,a,a,f,cH,a,f,cH,a,eH,eH,eH,fH,cH,gS,f,cH,a};
	int starwarsDuration1[18] = {500,500,500,350,150,500,350,150,650,500,500,500,350,150,500,350,150,650};
	
	int starwarsFreq2[16] = {aH,a,a,aH,gSH,gH,fSH,fH,fSH, aS,dSH,dH,cSH,cH,b,cH};
	int starwarsDuration2[16] = {500,300,150,500,325,175,125,125,250,250,500,325,175,125,125,250};
	
	int starwarsFreq3[8] = {f,gS,f,a,cH,a,cH,eH};
	int starwarsDuration3[8] = {250,500,350,125,500,375,125,650};
	
	int starwarsFreq4[8] = {f,gS,f,cH,a,f,cH,a};
	int starwarsDuration4[8] = {250,500,375,125,500,375,125,650};*/
	
	int beepFreq[4] = {7500,7500,7500,7500};
	int beepDuration[4] = {250,250,250,250};
	
	void playStarWars();
	void playBeep();

public:
  Beeper(int pin);  
	void play();
	void stop();
	

};

#endif
