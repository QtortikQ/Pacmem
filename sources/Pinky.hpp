#ifndef PINKY_
#define PINKY_

#include "Ghost.hpp"

class Pinky : public Ghost
{
public:
	Pinky();
	virtual ~Pinky();
	virtual const char getModel() const override;
	virtual void move() override;
	virtual void disband() override;
};

#endif // !PINKY_