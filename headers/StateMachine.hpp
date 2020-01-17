#ifndef STATE_MACHINE_
#define STATE_MACHINE_

#include "Ghost.hpp"

class StateMachine
{
public:
	StateMachine();
	virtual ~StateMachine();
	virtual void setState(Ghost ghost);
	virtual void moveState();
	virtual void disbandState();

private:
	Ghost ghost_;
};

#endif // !STATE_MACHINE_

