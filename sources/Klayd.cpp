#include "Klayd.hpp"

Klayd::Klayd() {
}

Klayd::~Klayd() {
}

const char Klayd::getModel() const {
	return 'K';
}

void Klayd::move(std::vector<int> pacManPos) {
	if (pacManPos[0] > pos[0]) {
		setPosition(getPosition()[0] + 1, getPosition()[1]);
	}
	if (pacManPos[0] < pos[0]) {
		setPosition(getPosition()[0] - 1, getPosition()[1]);
	}
	if (pacManPos[1] > pos[1]) {
		setPosition(getPosition()[0], getPosition()[1] + 1);
	}
	if (pacManPos[1] < pos[1]) {
		setPosition(getPosition()[0], getPosition()[1] - 1);
	}
}