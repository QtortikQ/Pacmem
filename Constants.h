#ifndef CONSTANTS_
#define CONSTANTS_

enum ButtonCodes {
	FORWARD = 119, BACKWARD = 115, 
	LEFT = 97, RIGHT = 100
};

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

inline const int getSpace() {
	return 32;
}

inline const int getWall() {
	return 219;
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

inline const int startXPosBlinky() {
	return 14;
}

inline const int startYPosBlinky() {
	return 14;
}

inline const int pacManLives() {
	return 2;
}

inline const int pauseButton() {
	return 112;
}

#endif // !CONSTANTS_
