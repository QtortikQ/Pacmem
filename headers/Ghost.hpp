#ifndef GHOST_
#define GHOST_

#include "Creature.hpp"
#include <string>

class Ghost : public Creature
{
public:
	Ghost();
	virtual ~Ghost();
	virtual const char getModel() const;
	virtual bool destroy();
	virtual void move();
	virtual int findPacMan(int xPM, int yPM);
protected:
	int pac_man_here_;
};

#endif // !GHOST_