#ifndef GHOST_
#define GHOST_

#include "Creature.h"

class Ghost : public Creature
{
public:
	Ghost();
	virtual ~Ghost();
	virtual const char getModel() const;
	virtual bool destroy();
	virtual void move();
	virtual string findPacMan(int xPM, int yPM);
protected:
	string pac_man_here_;
};

#endif // !GHOST_