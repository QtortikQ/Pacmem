#ifndef GHOST_
#define GHOST_

#include "Creature.hpp"
#include "Constants.hpp"
#include "SmartPointer.hpp"
#include <string>

class Ghost : public Creature
{
public:
	Ghost();
	virtual ~Ghost();
	virtual const char getModel() const;
	virtual bool destroy();
	virtual void move(std::vector<int> pacManPos);
	virtual void setPosition(int x, int y);
	virtual std::vector<int> getPosition();
	static Ghost* creatGhost(GhostID id);
	virtual int pacManDiraction();
protected:
	int pac_man_here_;
};

#endif // !GHOST_