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

void Ghost::move() {
}

int Ghost::findPacMan(int x, int y) {
	return 1;
}