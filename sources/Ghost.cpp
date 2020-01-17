#include "Ghost.hpp"

Ghost::Ghost() {
}

Ghost::~Ghost() {
}

const char Ghost::getModel() const {
	return '#';
}



bool Ghost::destroy() {
	return true;
}

void Ghost::move(std::vector<int> positionStruct) {
}

void Ghost::setPosition(int x, int y) {
	pos.resize(XY());
	pos[0] = x;
	pos[1] = y;
}

std::vector<int> Ghost::getPosition() {
	return pos;
}

int Ghost::pacManDiraction() {
	return pac_man_here_;
}