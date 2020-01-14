#include "PacMan.h"
#include "Constants.h"

PacMan::PacMan() : num_of_lives_(2), 
	is_energized_(false) {
}

PacMan::~PacMan() {
}

const char PacMan::getModel() const {
	return '@';
}

bool PacMan::destroy() {
	if(0 == num_of_lives_) {
		return true;
	}
}

void PacMan::setPosition(int x, int y) {
	position_struct_.posX = x;
	position_struct_.posY = y;
}

PositionStruct PacMan::getPosition() {
	return position_struct_;
}

void PacMan::setIsEnergized(bool b) {
		is_energized_ = b;
}

bool PacMan::getIsEnergized() {
	return is_energized_;
}

bool PacMan::takeDamage(int damage) {
	num_of_lives_ -= damage;
	destroy();
	return true;
}

int PacMan::getLives() {
	return num_of_lives_;
}

void PacMan::setLives() {
	num_of_lives_ = pacManLives();
}