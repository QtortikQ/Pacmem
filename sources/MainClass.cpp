//#pragma warning(disable : 4996)
#include "MainClass.hpp"
#include "Constants.hpp"
#include "PerformanceCounter.hpp"
#include "SmartPointer.hpp"
#include <conio.h>

CStopwatch timer;
CStopwatch timeSpawn;
CStopwatch timeEnergized;

MainClass::MainClass() : score_(0), 
	time_(0),
	num_fruits_(0),
	level_(1),
	curr_time_(0),
	can_spawn_fruit_(true),
	scores_("0"),
	pac_man_lives_("2"), 
	pause_(true),
	button_(FORWARD) {

}

MainClass::~MainClass() {
}

void MainClass::spawnPacMan() {
	render_.setChar(getWidth(), pac_man_.getPosition()[0], pac_man_.getPosition()[1], pac_man_.getModel());
}

void MainClass::spawnScepFruit(int fruit, int posX, int PosY) {
	if (fruit == num_fruits_ && can_spawn_fruit_) {
		timeSpawn.CStart();
		render_.setChar(getWidth(), posX, PosY, render_.renderSpecFruit());
		local_map_[PosY][posX] = render_.renderSpecFruit();
		can_spawn_fruit_ = false;
	}
	if (timeToTakeSFruit() < timeSpawn.CNow()) {
		local_map_[PosY][posX] = 0;
		can_spawn_fruit_ = true;
	}
}

void MainClass::spawnGhost() {
	for (int i = 0; i < numOfGhosts(); i++) {
		render_.setChar(getWidth(), ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1], ghostV[i]->getModel());
	}
}

void MainClass::update(float deltaTime) {
	int k = 0;
	render_.renderMap(local_map_);
	for (int i = 0; i < getHeight(); i++) {
		fillBoard(i, k);
	}

	if (true == pac_man_.getIsEnergized() && timeToEatGhost() < timeEnergized.CNow()) {
		pac_man_.setIsEnergized(false);
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
			render_.getChar(getWidth(), pac_man_.getPosition()[0], pac_man_.getPosition()[1] - 1) != char(getWall())) {

			button_ = button;
		}
		if (BACKWARD == button && 
			render_.getChar(getWidth(), pac_man_.getPosition()[0], pac_man_.getPosition()[1] + 1) != char(getWall())) {
			button_ = button;
		}
		if (TOLEFT == button && 
			render_.getChar(getWidth(), pac_man_.getPosition()[0] - 1, pac_man_.getPosition()[1]) != char(getWall())) {
			button_ = button;
		}
		if (TORIGHT == button &&
			render_.getChar(getWidth(), pac_man_.getPosition()[0] + 1, pac_man_.getPosition()[1]) != char(getWall())) {
			button_ = button;
		}
}

void MainClass::movement() {
	render_.setChar(getWidth(), pac_man_.getPosition()[0], pac_man_.getPosition()[1], ' ');
	local_map_[pac_man_.getPosition()[1]][pac_man_.getPosition()[0]] = 0;
	switch (button_) {
	case FORWARD:
		if (render_.getChar(getWidth(), pac_man_.getPosition()[0], pac_man_.getPosition()[1] - 1) != char(getWall())) {

			eatFruit(pac_man_.getPosition()[0], pac_man_.getPosition()[1] - 1);

			pac_man_.setPosition(pac_man_.getPosition()[0],
				pac_man_.getPosition()[1] - 1);
		}
		break;

	case BACKWARD:
		if (render_.getChar(getWidth(), pac_man_.getPosition()[0], pac_man_.getPosition()[1] + 1) != char(getWall())) {

			eatFruit(pac_man_.getPosition()[0], pac_man_.getPosition()[1] + 1);

			pac_man_.setPosition(pac_man_.getPosition()[0],
				pac_man_.getPosition()[1] + 1);
		}
		break;

	case TOLEFT:
		if (render_.getChar(getWidth(), pac_man_.getPosition()[0] - 1, pac_man_.getPosition()[1]) != char(getWall())) {

			if (pac_man_.getPosition()[0] - 1 == 0) {
				pac_man_.setPosition(pac_man_.getPosition()[0] + endOfField(),
					pac_man_.getPosition()[1]);
				render_.setChar(28, pac_man_.getPosition()[0],
					pac_man_.getPosition()[1], pac_man_.getModel());
			}

			eatFruit(pac_man_.getPosition()[0] - 1, pac_man_.getPosition()[1]);

			pac_man_.setPosition(pac_man_.getPosition()[0] - 1,
				pac_man_.getPosition()[1]);
		}
		break;

	case TORIGHT:
		if (render_.getChar(getWidth(), pac_man_.getPosition()[0] + 1, pac_man_.getPosition()[1]) != char(getWall())) {

			if (pac_man_.getPosition()[0] + 1 == getWidth()) {
				pac_man_.setPosition(pac_man_.getPosition()[0] - endOfField(),
					pac_man_.getPosition()[1]);
				render_.setChar(28, pac_man_.getPosition()[0],
					pac_man_.getPosition()[1], pac_man_.getModel());
			}

			eatFruit(pac_man_.getPosition()[0] + 1, pac_man_.getPosition()[1]);

			pac_man_.setPosition(pac_man_.getPosition()[0] + 1,
				pac_man_.getPosition()[1]);
		}
		break;
	default:
		break;
	}
}

void MainClass::ghostMovement() {
	for (int i = 0; i < numOfGhosts(); i++) {
		switch (ghostV[i]->pacManDiraction()) {
		case UP:
			if (render_.getChar(getWidth(), ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1] - 1) != char(getWall())) {
				ghostV[i]->move(pac_man_.getPosition());
			} else {
				ghostV[i]->setPosition(ghostV[i]->getPosition()[0] - 1, ghostV[i]->getPosition()[1]);
			}
			break;

		case DOWN:
			if (render_.getChar(getWidth(), ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1] + 1) != char(getWall())) {
				ghostV[i]->move(pac_man_.getPosition());
			} else {
				ghostV[i]->setPosition(ghostV[i]->getPosition()[0] + 1, ghostV[i]->getPosition()[1]);
			}
			break;

		case LEFT:
			if (render_.getChar(getWidth(), ghostV[i]->getPosition()[0] - 1, ghostV[i]->getPosition()[1]) != char(getWall())) {
				ghostV[i]->move(pac_man_.getPosition());
			} else {
				ghostV[i]->setPosition(ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1] + 1);
			}
			break;

		case RIGHT:
			if (render_.getChar(getWidth(), ghostV[i]->getPosition()[0] + 1, ghostV[i]->getPosition()[1]) != char(getWall())) {
				ghostV[i]->move(pac_man_.getPosition());
			} else {
				ghostV[i]->setPosition(ghostV[i]->getPosition()[0], ghostV[i]->getPosition()[1] - 1);
			}
			break;
		}
	}
	tryEatPacMan(pac_man_.getPosition(), pac_man_.getIsEnergized());
	eatGhost();
}

void MainClass::eatFruit(int x, int y) {
	if (render_.getChar(getWidth(), x, y) == '.') {
		score_ += nFruitScore();
		scores_ = std::to_string(score_);
		num_fruits_ += 1;
	}
	if (render_.getChar(getWidth(), x, y) == '*') {
		score_ += eFruitScore();
		scores_ = std::to_string(score_);

		energizePacMan();
	}
	if (render_.getChar(getWidth(), x, y) == '&') {
		score_ += sFruitScore() * level_;
		scores_ = std::to_string(score_);
	}
}

void MainClass::eatGhost() {
	if (true == pac_man_.getIsEnergized() &&
		ghostV[0]->getPosition()[0] == pac_man_.getPosition()[0] &&
		ghostV[0]->getPosition()[1] == pac_man_.getPosition()[1]) {
		score_ += 100 * level_;
		scores_ = std::to_string(score_);
	}
}

void MainClass::energizePacMan() {
	timeEnergized.CStart();
	pac_man_.setIsEnergized(true);
}

void MainClass::tryEatPacMan(std::vector<int> positionStruct, bool energize) {
	if (positionStruct[0] == ghostV[0]->getPosition()[0] && 
		positionStruct[1] == ghostV[0]->getPosition()[1] && 
		false == energize) {
		pac_man_.takeDamage(1);
		pac_man_.setPosition(startPacManPosX(), startPacManPosY());
		pac_man_lives_ = std::to_string(pac_man_.getLives());
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
		render_.setChar(getWidth(), j, iterationF, local_map_[iterationF][j]);
		if (getHeight() - 2 < iterationF && getHeight() > iterationF && j == posPacManLife()) {
			render_.setChar(getWidth(), j, iterationF, pac_man_lives_[0]);
		}
		if (posScore() < iterationF && getWidth() > iterationF && j == 1 && iterationS < scores_.size()) {
			render_.setChar(getWidth(), iterationF, j, scores_[iterationS]);
			iterationS++;
		}
	}
}

void MainClass::run() {
	game_field_.generateMap();
	local_map_ = game_field_.getMap();
	int sum = 0;
	int counter = 0;
	int deltaTime = 0;
	num_fruits_ = 0;

	ghostV.push_back(Ghost::creatGhost(BLINKY));
	ghostV.push_back(Ghost::creatGhost(PINKY));
	ghostV.push_back(Ghost::creatGhost(INKY));
	ghostV.push_back(Ghost::creatGhost(KLAYD));

	render_.prepScene(getWidth(), getHeight());
	pac_man_.setLives();
	pac_man_.setPosition(startPacManPosX(), startPacManPosY());
	for (int i = 0; i < numOfGhosts(); i++) {
		ghostV[i]->setPosition(startXPosGhosts() + i, startYPosGhosts());
	}
	while (true) {
		timer.CStart();
		if (_kbhit())
		{
			setMovement(_getch());
			if (!FlushConsoleInputBuffer(render_.mConsoleIn))
				std::cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
		}
		if (false == main_menu_.paused()) {
			update((float)deltaTime / 1000.0f);

			Sleep(1);
			while (1)
			{
				deltaTime = timer.CNow();
				if (deltaTime > 200)
					break;
			}

			sum += deltaTime;
			counter++;
			if (sum >= 10000)
			{
				TCHAR  szbuff[255];
				StringCchPrintf(szbuff, 255, TEXT("FPS: %d"), counter);
				SetConsoleTitle(szbuff);

				counter = 0;
				sum = 0;
			}

			if (240 == num_fruits_) {
				level_++;
				run();
			}

			if (true == pac_man_.destroy()) {
				score_ = 0;
				scores_ = "0";
				pac_man_lives_ = "2";
				level_ = 0;
				pause_ = true;
				render_.cleanScene(getWidth(), getHeight());
				render_.renderScene();
				free(render_.mChiBuffer);
				break;
			}
		}
	}
}

Ghost* Ghost::creatGhost(GhostID id) {
	Ghost *ghost;
	ghost = new Blinky();
	switch (id) {
	case BLINKY:
		ghost = new Blinky();
		break;
	case PINKY:
		ghost = new Pinky();
		break;
	case INKY:
		ghost = new Inky();
		break;
	case KLAYD:
		ghost = new Klayd();
		break;
	default:
		assert(false);
	}
	return ghost;
}