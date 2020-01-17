#ifndef BLINKY_
#define BLINKT_

#include "Ghost.hpp"

class Blinky : public Ghost
{
public:
	Blinky();
	virtual ~Blinky();
	virtual const char getModel() const override;
	virtual void move(std::vector<int> positionStruct) override;

};

#endif