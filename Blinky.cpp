#include "Blinky.h"
#include "Constants.h"

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
	
	if ("RIGHT" == pac_man_here_) {
		setPosition(getPosition().posX + 1, getPosition().posY);
	}

	if ("DOWN" == pac_man_here_ || "DOWNRIGHT" == pac_man_here_ || "DOWNLEFT" == pac_man_here_) {
		setPosition(getPosition().posX, getPosition().posY + 1);
		return ;
	}

	if ("LEFT" == pac_man_here_) {
		setPosition(getPosition().posX - 1, getPosition().posY);
	}

	if ("UP" == pac_man_here_ || "UPLEFT" == pac_man_here_ || "UPRIGHT" == pac_man_here_) {
		setPosition(getPosition().posX, getPosition().posY - 1);
	}

	if ("DEAD" == pac_man_here_) {
		setPosition(startXPosBlinky(), startYPosBlinky());
	}
}

string Blinky::findPacMan(int xPM, int yPM) {
	if (xPM > getPosition().posX) {
		pac_man_here_ = "RIGHT";
		return pac_man_here_;
	}

	if (yPM > getPosition().posY) {
		pac_man_here_ = "DOWN";
		return pac_man_here_;
	}

	if (xPM < getPosition().posX) {
		pac_man_here_ = "LEFT";
		return pac_man_here_;
	}

	if (yPM < getPosition().posY) {
		pac_man_here_ = "UP";
		return pac_man_here_;
	}

	if (xPM > getPosition().posX) {
		if ( yPM < getPosition().posX) {
			pac_man_here_ = "UPRIGHT";
			return pac_man_here_;
		} else {
			pac_man_here_ = "DOWNRIGHT";
			return pac_man_here_;
		}
	}
	
	if (xPM < getPosition().posX) {
		if (yPM > getPosition().posX) {
			pac_man_here_ = "DOWNLEFT";
			return pac_man_here_;
		} else {
			pac_man_here_ = "UPLEFT";
			return pac_man_here_;
		}
	}

	if (xPM == getPosition().posX && yPM == getPosition().posY) {
		pac_man_here_ = "DEAD";
		return pac_man_here_;
	}
}