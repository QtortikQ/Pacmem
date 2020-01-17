#include "Pinky.hpp"

Pinky::Pinky() {
}

Pinky::~Pinky() {
}

const char Pinky::getModel() const {
	return 'P';
}

void Pinky::move() {
	/*if (RIGHT == pacManDiraction()) {
		setPosition(getPosition()[0] + 1, getPosition()[1]);
	}
	if (LEFT == pacManDiraction()) {
		setPosition(getPosition()[0] - 1, getPosition()[1]);
	}
	if (DOWN == pacManDiraction()) {
		setPosition(getPosition()[0], getPosition()[1] + 1);
	}
	if (UP == pacManDiraction()) {
		setPosition(getPosition()[0], getPosition()[1] - 1);
	}*/
}

void Pinky::disband() {
	if (disbandXBlinky() < pos[0]) {
		setPosition(pos[0] - 1, pos[1]);
	}
	if (disbandYBlinky() < pos[1]) {
		setPosition(pos[0], pos[1] - 1);
	}
}