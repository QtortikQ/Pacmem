#include "Blinky.hpp"
#include "Constants.hpp"

Blinky::Blinky() {
}

Blinky::~Blinky() {
}

const char Blinky::getModel() const{
	return 'B';
}

void Blinky::move() {
	if (RIGHT == pacManDiraction()) {
		setPosition(pos[0] + 1, pos[1]);
	}
	if (LEFT == pacManDiraction()) {
		setPosition(pos[0] - 1, pos[1]);
	}
	if (DOWN == pacManDiraction()) {
		setPosition(pos[0], pos[1] + 1);
	}
	if (UP == pacManDiraction()) {
		setPosition(pos[0], pos[1] - 1);
	}
}

void Blinky::disband() {
	if (disbandXBlinky() < pos[0]) {
		setPosition(pos[0] - 1, pos[1]);
	}
	if (disbandYBlinky() < pos[1]) {
		setPosition(pos[0], pos[1] - 1);
	}
}