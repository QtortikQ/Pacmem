#include "Ghost.h"

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

string Ghost::findPacMan(int x, int y) {
	return "";
}