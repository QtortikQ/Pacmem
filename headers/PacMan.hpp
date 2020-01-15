#ifndef PAC_MAN_
#define PAC_MAN_

#include "Creature.hpp"

class PacMan : public Creature
{
public:
	PacMan();
	virtual ~PacMan();
	virtual const char getModel() const;
	virtual bool destroy();
	void setPosition(int x, int y);
	PositionStruct getPosition();
	void setIsEnergized(bool b);
	bool getIsEnergized();
	bool takeDamage(int damage);
	int getLives();
	void setLives();
private:
	bool is_energized_;
	int num_of_lives_;
};

#endif