#ifndef KLAYD_
#define KLAYD_

#include "Ghost.hpp"

class Klayd : public Ghost
{
public:
	Klayd();
	virtual ~Klayd();
	virtual const char getModel() const override;
	virtual void move() override;
	virtual void disband() override;
};

#endif // !KLAYD_