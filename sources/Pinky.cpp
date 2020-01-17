#include "Pinky.hpp"

Pinky::Pinky() {
}

Pinky::~Pinky() {
}

const char Pinky::getModel() const {
	return 'P';
}

void Pinky::move(std::vector<int> pacManPos) {
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