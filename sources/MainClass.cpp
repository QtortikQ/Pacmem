//#pragma warning(disable : 4996)
#include "MainClass.hpp"
#include "Constants.hpp"
#include "PerformanceCounter.hpp"
#include <conio.h>

CStopwatch timer;
CStopwatch timeSpawn;
CStopwatch timeEnergized;

MainClass::MainClass() : score_(0), 
	time_(0),
	numFruits_(0),
	level_(1),
	currTime_(0),
	canSpawnFruit_(true),
	scores_("0"),
	pacManLives_("2"),
	button_(FORWARD),
	pause_(true),
	specFruits(""){
}

MainClass::~MainClass() {
}

void MainClass::spawnPacMan() {
	render_.setChar(getWidth(), pacMan_.getPosition()[0], pacMan_.getPosition()[1], pacMan_.getModel());
}

void MainClass::spawnScepFruit(int fruit, 
	int posX, 
	int PosY) {
	if (fruit == numFruits_ && canSpawnFruit_) {
		timeSpawn.CStart();
		render_.setChar(getWidth(), posX, PosY, render_.renderSpecFruit());
		localMap_[PosY][posX] = render_.renderSpecFruit();
		canSpawnFruit_ = false;
	}
	if (timeToTakeSFruit() < timeSpawn.CNow()) {
		localMap_[PosY][posX] = 0;
		canSpawnFruit_ = true;
	}
}

void MainClass::spawnGhost() {
	for (int i = 0; i < numOfGhosts(); i++) {
		render_.setChar(getWidth(), ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1], ghostV[i]->getModel());
	}
}

void MainClass::update(float deltaTime) {
	int k = 0;
	render_.renderMap(localMap_);
	for (int i = 0; i < getHeight(); i++) {
		fillBoard(i, k);
	}

	if (true == pacMan_.getIsEnergized() && timeToEatGhost() < timeEnergized.CNow()) {
		pacMan_.setIsEnergized(false);
	}

	spawnScepFruit(SpawnSpecFruit1(), spawnPosSpecFruitX1(), spawnPosSpecFruitY());
	spawnScepFruit(SpawnSpecFruit2(), spawnPosSpecFruitX2(), spawnPosSpecFruitY());

	movement();
	ghostMovement();
	spawnPacMan();
	spawnGhost();
	render_.renderScene();
	startPause();
}

void MainClass::setMovement(int button) {

		if (FORWARD == button &&
			render_.getChar(getWidth(), pacMan_.getPosition()[0], pacMan_.getPosition()[1] - 1) != char(getWall())) {

			button_ = button;
		}
		if (BACKWARD == button && 
			render_.getChar(getWidth(), pacMan_.getPosition()[0], pacMan_.getPosition()[1] + 1) != char(getWall())) {
			button_ = button;
		}
		if (TOLEFT == button && 
			render_.getChar(getWidth(), pacMan_.getPosition()[0] - 1, pacMan_.getPosition()[1]) != char(getWall())) {
			button_ = button;
		}
		if (TORIGHT == button &&
			render_.getChar(getWidth(), pacMan_.getPosition()[0] + 1, pacMan_.getPosition()[1]) != char(getWall())) {
			button_ = button;
		}
}

void MainClass::movement() {
	render_.setChar(getWidth(), pacMan_.getPosition()[0], pacMan_.getPosition()[1], ' ');
	localMap_[pacMan_.getPosition()[1]][pacMan_.getPosition()[0]] = 0;
	switch (button_) {
	case FORWARD:
	case AFORWARD:
		if (render_.getChar(getWidth(), pacMan_.getPosition()[0], pacMan_.getPosition()[1] - 1) != char(getWall())) {

			eatFruit(pacMan_.getPosition()[0], pacMan_.getPosition()[1] - 1);

			pacMan_.setPosition(pacMan_.getPosition()[0],
				pacMan_.getPosition()[1] - 1);
		}
		break;

	case BACKWARD:
	case ABACKWARD:
		if (render_.getChar(getWidth(), pacMan_.getPosition()[0], pacMan_.getPosition()[1] + 1) != char(getWall())) {

			eatFruit(pacMan_.getPosition()[0], pacMan_.getPosition()[1] + 1);

			pacMan_.setPosition(pacMan_.getPosition()[0],
				pacMan_.getPosition()[1] + 1);
		}
		break;

	case TOLEFT:
	case ATOLEFT:
		if (render_.getChar(getWidth(), pacMan_.getPosition()[0] - 1, pacMan_.getPosition()[1]) != char(getWall())) {

			if (pacMan_.getPosition()[0] - 1 == 0) {
				pacMan_.setPosition(pacMan_.getPosition()[0] + endOfField(),
					pacMan_.getPosition()[1]);
				render_.setChar(28, pacMan_.getPosition()[0],
					pacMan_.getPosition()[1], pacMan_.getModel());
			}

			eatFruit(pacMan_.getPosition()[0] - 1, pacMan_.getPosition()[1]);

			pacMan_.setPosition(pacMan_.getPosition()[0] - 1,
				pacMan_.getPosition()[1]);
		}
		break;

	case TORIGHT:
	case ATORIGHT:
		if (render_.getChar(getWidth(), pacMan_.getPosition()[0] + 1, pacMan_.getPosition()[1]) != char(getWall())) {

			if (pacMan_.getPosition()[0] + 1 == getWidth()) {
				pacMan_.setPosition(pacMan_.getPosition()[0] - endOfField(),
					pacMan_.getPosition()[1]);
				render_.setChar(28, pacMan_.getPosition()[0],
					pacMan_.getPosition()[1], pacMan_.getModel());
			}

			eatFruit(pacMan_.getPosition()[0] + 1, pacMan_.getPosition()[1]);

			pacMan_.setPosition(pacMan_.getPosition()[0] + 1,
				pacMan_.getPosition()[1]);
		}
		break;
	default:
		break;
	}
}

void MainClass::ghostMovement() {
	for (int i = 0; i < numOfGhosts(); i++) {
		ghostV[i]->findPacMan(pacMan_.getPosition());
		switch (ghostV[i]->pacManDiraction()) {
		case UP:
			if (render_.getChar(getWidth(), ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1] - 1) != char(getWall())) {
				/*if (true == pacMan_.getIsEnergized())
				{
					stateMachine_.setState();
				} else {}*/
				chooseState(i);
				//ghostV[i]->move();
			} else {
				ghostV[i]->setPosition(ghostV[i]->getPosition()[0] - 1, ghostV[i]->getPosition()[1]);
			}
			break;

		case DOWN:
			if (render_.getChar(getWidth(), ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1] + 1) != char(getWall())) {
				//ghostV[i]->move();
				chooseState(i);
			} else {
				ghostV[i]->setPosition(ghostV[i]->getPosition()[0] + 1, ghostV[i]->getPosition()[1]);
			}
			break;

		case LEFT:
			if (render_.getChar(getWidth(), ghostV[i]->getPosition()[0] - 1, ghostV[i]->getPosition()[1]) != char(getWall())) {
				//ghostV[i]->move();
				chooseState(i);
			} else {
				ghostV[i]->setPosition(ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1] + 1);
			}
			break;

		case RIGHT:
			if (render_.getChar(getWidth(), ghostV[i]->getPosition()[0] + 1, ghostV[i]->getPosition()[1]) != char(getWall())) {
				//ghostV[i]->move();
				chooseState(i);
			} else {
				ghostV[i]->setPosition(ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1] - 1);
			}
			break;
		}
		tryEatPacMan(pacMan_.getPosition(), pacMan_.getIsEnergized(), i);
		eatGhost(i);
	}
}

void MainClass::chooseState(int &iterator) {
	if (true == pacMan_.getIsEnergized()) {
		stateMachine_.setState(ghostV[iterator]);
		stateMachine_.disbandState();
	} else {
		stateMachine_.setState(ghostV[iterator]);
		stateMachine_.moveState();
	}
}

void MainClass::eatFruit(int x, int y) {
	if (render_.getChar(getWidth(), x, y) == '.') {
		score_ += nFruitScore();
		scores_ = std::to_string(score_);
		numFruits_ += 1;
	}
	if (render_.getChar(getWidth(), x, y) == '*') {
		score_ += eFruitScore();
		scores_ = std::to_string(score_);

		energizePacMan();
	}
	if (render_.getChar(getWidth(), x, y) == '&') {
		score_ += sFruitScore() * level_;
		scores_ = std::to_string(score_);
		specFruits += render_.renderSpecFruit();
	}
}

void MainClass::eatGhost(int &iterator) {
	if (true == pacMan_.getIsEnergized() &&
		ghostV[iterator]->getPosition()[0] == pacMan_.getPosition()[0] &&
		ghostV[iterator]->getPosition()[1] == pacMan_.getPosition()[1]) {
		score_ += 100 * level_;
		scores_ = std::to_string(score_);
	}
}

void MainClass::energizePacMan() {
	timeEnergized.CStart();
	pacMan_.setIsEnergized(true);
}

void MainClass::tryEatPacMan(std::vector<int> positionStruct, 
	bool energize, 
	int &iterator) {
	if (positionStruct[0] == ghostV[iterator]->getPosition()[0] &&
		positionStruct[1] == ghostV[iterator]->getPosition()[1] &&
		false == energize) {
		pacMan_.takeDamage(1);
		pacMan_.setPosition(startPacManPosX(), startPacManPosY());
		pacManLives_ = std::to_string(pacMan_.getLives());
	}
}

void MainClass::startPause() {
	if (true == pause_) {
		system("pause");
		system("cls");
		pause_ = false;
	}
}

void MainClass::fillBoard(int &iterationF, int &iterationS) {
	for (int j = 0; j < getWidth(); j++) {
		render_.setChar(getWidth(), j, iterationF, localMap_[iterationF][j]);
		if (getHeight() - 2 < iterationF && getHeight() > iterationF && j == posPacManLife()) {
			render_.setChar(getWidth(), j, iterationF, pacManLives_[0]);
		}
		if (posScore() < iterationF && getWidth() > iterationF && j == 1 && iterationS < scores_.size()) {
			render_.setChar(getWidth(), iterationF, j, scores_[iterationS]);
			iterationS++;
		}
	}
}

void MainClass::run() {
	gameField_.generateMap();
	localMap_ = gameField_.getMap();
	int sum = 0;
	int counter = 0;
	int deltaTime = 0;
	numFruits_ = 0;

	ghostV.push_back(Ghost::creatGhost(BLINKY));
	ghostV.push_back(Ghost::creatGhost(PINKY));
	ghostV.push_back(Ghost::creatGhost(INKY));
	ghostV.push_back(Ghost::creatGhost(KLAYD));

	render_.prepScene(getWidth(), getHeight());
	pacMan_.setLives();
	pacMan_.setPosition(startPacManPosX(), startPacManPosY());
	for (int i = 0; i < numOfGhosts(); i++) {
		ghostV[i]->setPosition(startXPosGhosts() + i, startYPosGhosts());
	}
	while (true) {
		timer.CStart();
		if (_kbhit())
		{
			button_ = _getch();
			if (!FlushConsoleInputBuffer(render_.mConsoleIn))
				std::cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
		}
		if (button_ == ignoredCode()) {
			continue;
		}
		setMovement(button_);

		if (false == mainMenu_.paused()) {
			update((float)deltaTime / 1000.0f);

			Sleep(true);
			while (true) {
				deltaTime = timer.CNow();
				if (deltaTime > 200)
					break;
			}

			sum += deltaTime;
			counter++;
			if (sum >= 10000) {
				TCHAR  szbuff[255];
				StringCchPrintf(szbuff, 255, TEXT("FPS: %d"), counter);
				SetConsoleTitle(szbuff);

				counter = 0;
				sum = 0;
			}

			if (240 == numFruits_) {
				level_++;
				run();
			}

			if (true == pacMan_.destroy()) {
				score_ = 0;
				scores_ = "0";
				pacManLives_ = "2";
				level_ = 0;
				pause_ = true;
				specFruits = "";
				render_.cleanScene(getWidth(), getHeight());
				render_.renderScene();
				free(render_.mChiBuffer);
				break;
			}
		}
	}
}