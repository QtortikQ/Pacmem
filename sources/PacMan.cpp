#include "PacMan.hpp"
#include "Constants.hpp"

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
	pos.resize(XY());
	pos[0] = x;
	pos[1] = y;
	//position_struct_.position[0] = x;
	//position_struct_.position[1] = y;
}

std::vector<int> PacMan::getPosition() {
	return pos;
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