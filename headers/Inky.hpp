#ifndef INKY_
#define INKY_

#include "Ghost.hpp"


class Inky : public Ghost
{
public:
	Inky();
	virtual ~Inky();
	virtual const char getModel() const override;
	virtual void move() override;
	virtual void disband() override;
};

#endif // ! INKY_