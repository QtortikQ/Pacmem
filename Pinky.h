#ifndef PINKY_
#define PINKY_

#include "Ghost.h"

class Pinky : public Ghost
{
public:
	Pinky();
	virtual ~Pinky();
	virtual void setPosition(int x, int y);
	virtual PositionStruct getPosition();
};

#endif // !PINKY_