#ifndef Display_H
#define Display_H

#include <Arduino.h>
#include "SevSeg.h"

class Display 
{
	
private:
	SevSeg sevseg;

public:
	Display();
	void setNumber(int number,int decimalIndex);
	void update();
};

#endif
