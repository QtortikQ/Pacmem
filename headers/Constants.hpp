#ifndef CONSTANTS_
#define CONSTANTS_

enum ButtonCodes {
	FORWARD = 119, 
	BACKWARD = 115, 
	TOLEFT = 97, 
	TORIGHT = 100,
	AFORWARD = 72,
	ABACKWARD = 80,
	ATOLEFT = 75,
	ATORIGHT = 77
};

enum GhostDiraction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
	DEAD
};

enum GhostID {
	BLINKY = 0,
	PINKY,
	INKY,
	KLAYD
};

inline const int numOfGhosts() {
	return 4;
}

inline const int nFruitScore() {
	return 10;
}

inline const int eFruitScore() {
	return 50;
}

inline const int getWidth() {
	return 28;
}

inline const int getHeight() {
	return 36;
}

inline const char getSpace() {
	return 32;
}

inline const char getWall() {
	return 35;
}

inline const int startPacManPosX() {
	return 14;
}

inline const int startPacManPosY() {
	return 26;
}

inline const int endOfField() {
	return 26;
}

inline const int SpawnSpecFruit1() {
	return 70;
}

inline const int SpawnSpecFruit2() {
	return 170;
}

inline const int spawnPosSpecFruitX1() {
	return 14;
}

inline const int spawnPosSpecFruitX2() {
	return 13;
}

inline const int spawnPosSpecFruitY() {
	return 20;
}

inline const int sFruitScore() {
	return 100;
}

inline const int startXPosGhosts() {
	return 14;
}

inline const int startYPosGhosts() {
	return 14;
}

inline const int pacManLives() {
	return 2;
}

inline const int pauseButton() {
	return 112;
}

inline const int timeToTakeSFruit() {
	return 9000;
}

inline const int timeToEatGhost() {
	return 6000;
}

inline const int posScore() {
	return 7;
}

inline const int posPacManLife() {
	return 8;
}

inline const int XY() {
	return 2;
}

inline const int ignoredCode() {
	return 224;
}

inline const int disbandXBlinky() {
	return 26;
}

inline const int disbandYBlinky() {
	return 2;
}

inline const int disbandXPinky() {
	return 0;
}

inline const int disbandYPinky() {
	return 2;
}

inline const int disbandXInky() {
	return 26;
}

inline const int disbandYInky() {
	return 34;
}

inline const int disbandXKlayd() {
	return 0;
}

inline const int disbandYKlayd() {
	return 34;
}

#endif // !CONSTANTS_
