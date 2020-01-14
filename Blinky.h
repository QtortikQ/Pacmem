#ifndef BLINKY_
#define BLINKT_

#include "Ghost.h"

class Blinky : public Ghost
{
public:
	Blinky();
	virtual ~Blinky();
	virtual const char getModel() const;
	virtual void move();
	virtual string findPacMan(int x, int y);
	virtual void setPosition(int x, int y);
	virtual PositionStruct getPosition();

};

#endif