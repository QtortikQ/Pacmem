#ifndef PAC_MAN_
#define PAC_MAN_

#include "Creature.hpp"

class PacMan : public Creature
{
public:
	PacMan();
	virtual ~PacMan();
	virtual const char getModel() const;
	virtual const bool destroy();
	void setPosition(const int x, const int y);
	std::vector<int> getPosition();
	void setIsEnergized(const bool b);
	bool getIsEnergized();
	bool takeDamage(const int damage);
	int getLives();
	void setLives();
private:
	bool isEnergized_;
	int numOfLives_;
};

#endif