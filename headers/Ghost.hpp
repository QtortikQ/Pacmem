#ifndef GHOST_
#define GHOST_

#include "Creature.hpp"
#include "Constants.hpp"
#include <memory>
#include <string>

class Blinky;
class Pinky;
class Inky;
class Klayd;

class Ghost : public Creature
{
public:
	Ghost();
	virtual ~Ghost();
	virtual const char getModel() const;
	virtual const bool destroy();
	virtual void move();
	virtual void disband();
	virtual void setPosition(const int x, const int y);
	virtual std::vector<int> getPosition();
	static std::shared_ptr<Ghost> creatGhost(GhostID id);
	virtual const int pacManDiraction();
	virtual void findPacMan(std::vector<int> pacManPos);
protected:
	int pacManHere_;
};

#endif // !GHOST_