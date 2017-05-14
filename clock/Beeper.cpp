#include "Beeper.h"



Beeper::Beeper(int pin){
	
  	
}

void Beeper::play(){
	playing = true;
	playBeep();
}

void Beeper::stop(){
	playing = false;
}

void Beeper::playBeep(){
	while(playing){
		for(unsigned int i = 0; i < sizeof(beepFreq) / sizeof(beepFreq[0]) && playing; ++i){
			int freq = beepFreq[i];
			int duration = beepDuration[i];
			
			tone(buzzerPin,freq,duration);
      digitalWrite(A0,LOW);
			delay(duration);
      digitalWrite(A0,HIGH);
      delay(20);
		}
   delay(500);
	}
 
}


void Beeper::playStarWars(){
  /*const int* segmentOrder[5] = {starwarsFreq1, starwarsFreq2,starwarsFreq3,starwarsFreq2,starwarsFreq4};
  const int* durationOrder[5] = {starwarsDuration1, starwarsDuration2,starwarsDuration3,starwarsDuration2,starwarsDuration4};
    
  int curSegment = 0;
  
  while(playing){
    
    const int *freqs = segmentOrder[curSegment];
    const int *durations = durationOrder[curSegment];
    
    for(unsigned int i = 0; i < sizeof(starwarsFreq1) && playing; ++i){
      int freq = freqs[i];
      int duration = durations[i];
      
      tone(buzzerPin,freq,duration);
      delay(duration);
    }
    
    curSegment++;
    
    if(curSegment >= sizeof(segmentOrder)){
      curSegment = 0;
    }
    
  }

  delete segmentOrder;
  delete durationOrder;*/
}





