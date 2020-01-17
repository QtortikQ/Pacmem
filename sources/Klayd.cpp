#include "Klayd.hpp"

Klayd::Klayd() {
}

Klayd::~Klayd() {
}

const char Klayd::getModel() const {
	return 'K';
}

void Klayd::move() {
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

void Klayd::disband() {
	if (disbandXKlayd() < pos[0]) {
		setPosition(pos[0] - 1, pos[1]);
	}
	if (disbandYKlayd() > pos[1]) {
		setPosition(pos[0], pos[1] + 1);
	}
}