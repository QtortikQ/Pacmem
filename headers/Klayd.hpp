#ifndef KLAYD_
#define KLAYD_

#include "Ghost.hpp"

class Klayd : public Ghost
{
public:
	Klayd();
	virtual ~Klayd();
	virtual const char getModel() const override;
	virtual void move(std::vector<int> pacManPos) override;
};

#endif // !KLAYD_