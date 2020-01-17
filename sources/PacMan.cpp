#include "PacMan.hpp"
#include "Constants.hpp"

PacMan::PacMan() : numOfLives_(2), 
	isEnergized_(false) {
}

PacMan::~PacMan() {
}

const char PacMan::getModel() const {
	return '@';
}

const bool PacMan::destroy() {
	if(0 == numOfLives_) {
		return true;
	}
}

void PacMan::setPosition(const int x, const int y) {
	pos.resize(XY());
	pos[0] = x;
	pos[1] = y;
	//position_struct_.position[0] = x;
	//position_struct_.position[1] = y;
}

std::vector<int> PacMan::getPosition() {
	return pos;
}

void PacMan::setIsEnergized(const bool b) {
		isEnergized_ = b;
}

bool PacMan::getIsEnergized() {
	return isEnergized_;
}

bool PacMan::takeDamage(const int damage) {
	numOfLives_ -= damage;
	destroy();
	return true;
}

int PacMan::getLives() {
	return numOfLives_;
}

void PacMan::setLives() {
	numOfLives_ = pacManLives();
}