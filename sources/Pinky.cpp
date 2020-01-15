#include "Pinky.hpp"

Pinky::Pinky() {
}

Pinky::~Pinky() {
}

void Pinky::setPosition(int x, int y) {
	position_struct_.posX = x;
	position_struct_.posY = y;
}

PositionStruct Pinky::getPosition() {
	return position_struct_;
}