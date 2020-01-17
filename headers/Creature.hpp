#ifndef CREATURE_
#define CREATURE_

#include <vector>

class Creature
{
public:
	Creature() {
	}
	virtual ~Creature() {
	}
	virtual const char getModel() const = 0;
	virtual void setPosition(int x, int y) = 0;
	virtual bool destroy() = 0;
protected:
	float speed_;
	std::vector<int> pos;
	
};

#endif // !CREATURE_