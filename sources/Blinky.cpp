#include "Blinky.hpp"
#include "Constants.hpp"

Blinky::Blinky() {
}

Blinky::~Blinky() {
}

const char Blinky::getModel() const{
	return 'B';
}

void Blinky::setPosition(int x, int y) {
	position_struct_.posX = x;
	position_struct_.posY = y;
}

PositionStruct Blinky::getPosition() {
	return position_struct_;
}

void Blinky::move() {
	switch (pac_man_here_) {
	case UP:
		setPosition(getPosition().posX, getPosition().posY - 1);
		break;
	case DOWN:
		setPosition(getPosition().posX, getPosition().posY + 1);
		break;
	case LEFT:
		setPosition(getPosition().posX - 1, getPosition().posY);
		break;
	case RIGHT:
		setPosition(getPosition().posX + 1, getPosition().posY);
		break;
	default:
		setPosition(startXPosBlinky(), startYPosBlinky());
	}
}

int Blinky::findPacMan(int xPM, int yPM) {
	if (xPM > getPosition().posX) {
		pac_man_here_ = RIGHT;
		return RIGHT;
	}

	if (yPM > getPosition().posY) {
		pac_man_here_ = DOWN;
		return pac_man_here_;
	}

	if (xPM < getPosition().posX) {
		pac_man_here_ = LEFT;
		return pac_man_here_;
	}

	if (yPM < getPosition().posY) {
		pac_man_here_ = UP;
		return pac_man_here_;
	}

	if (xPM == getPosition().posX && yPM == getPosition().posY) {
		pac_man_here_ = DEAD;
		return pac_man_here_;
	}
}