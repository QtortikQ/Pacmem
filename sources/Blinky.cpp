#include "Blinky.hpp"
#include "Constants.hpp"

Blinky::Blinky() {
}

Blinky::~Blinky() {
}

const char Blinky::getModel() const{
	return 'B';
}

void Blinky::move(std::vector<int> pacManPos) {
	if (pacManPos[0] > pos[0]) {
		setPosition(getPosition()[0] + 1, getPosition()[1]);
		pac_man_here_ = RIGHT;
	}
	if (pacManPos[0] < pos[0]) {
		setPosition(getPosition()[0] - 1, getPosition()[1]);
		pac_man_here_ = LEFT;
	}
	if (pacManPos[1] > pos[1]) {
		setPosition(getPosition()[0], getPosition()[1] + 1);
		pac_man_here_ = DOWN;
	}
	if (pacManPos[1] < pos[1]) {
		setPosition(getPosition()[0], getPosition()[1] - 1);
		pac_man_here_ = UP;
	}
}