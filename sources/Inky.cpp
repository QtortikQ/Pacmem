#include "Inky.hpp"

Inky::Inky() {
}

Inky::~Inky() {
}

const char Inky::getModel() const {
	return 'I';
}

void Inky::move() {
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

void Inky::disband() {
	if (disbandXInky() > pos[0]) {
		setPosition(pos[0] + 1, pos[1]);
	}
	if (disbandYInky() > pos[1]) {
		setPosition(pos[0], pos[1] + 1);
	}
}