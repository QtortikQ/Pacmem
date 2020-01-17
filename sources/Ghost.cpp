#include "Ghost.hpp"
#include "Blinky.hpp"
#include "Pinky.hpp"
#include "Inky.hpp"
#include "Klayd.hpp"

Ghost::Ghost():pacManHere_(LEFT) {
}

Ghost::~Ghost() {
}

const char Ghost::getModel() const {
	return '#';
}

const bool Ghost::destroy() {
	return true;
}

void Ghost::move() {
}

void Ghost::disband() {
}

void Ghost::setPosition(const int x, const int y) {
	pos.resize(XY());
	pos[0] = x;
	pos[1] = y;
}

std::vector<int> Ghost::getPosition() {
	return pos;
}

const int Ghost::pacManDiraction() {
	return pacManHere_;
}

void Ghost::findPacMan(std::vector<int> pacManPos) {
	if (pacManPos[0] > pos[0]) {
		pacManHere_ = RIGHT;
	}
	if (pacManPos[0] < pos[0]) {
		pacManHere_ = LEFT;
	}
	if (pacManPos[1] < pos[1]) {
		pacManHere_ = UP;
	}
	if (pacManPos[1] > pos[1]) {
		pacManHere_ = DOWN;
	}
}

std::shared_ptr<Ghost> Ghost::creatGhost(GhostID id) {
	std::shared_ptr<Ghost> ghost(new Ghost);
	switch (id) {
	case BLINKY: {
		std::shared_ptr<Ghost> blinky(new Blinky);
		ghost = blinky;
		break;
	}
	case PINKY: {
		std::shared_ptr<Ghost> pinky(new Pinky);
		ghost = pinky;
		break;
	}
	case INKY: {
		std::shared_ptr<Ghost> inky(new Inky);
		ghost = inky;
		break;
	}
	case KLAYD: {
		std::shared_ptr<Ghost> klayd(new Klayd);
		ghost = klayd;
		break;
	}
	default:
		break;
	}
	return ghost;
}