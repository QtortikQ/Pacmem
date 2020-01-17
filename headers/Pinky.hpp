#ifndef PINKY_
#define PINKY_

#include "Ghost.hpp"

class Pinky : public Ghost
{
public:
	Pinky();
	virtual ~Pinky();
	virtual const char getModel() const override;
	virtual void move(std::vector<int> pacManPos) override;
};

#endif // !PINKY_