//#pragma warning(disable : 4996)
#include "MainClass.h"
#include "Constants.h"
#include "PerformanceCounter.h"
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
	pause_(true) {

}

MainClass::~MainClass() {
}

void MainClass::spawnPacMan() {
	render_.setChar(getWidth(), pac_man_.getPosition().posX, pac_man_.getPosition().posY, pac_man_.getModel());
}

void MainClass::spawnScepFruit(int fruit, int posX, int PosY) {
	if (fruit == num_fruits_ && can_spawn_fruit_) {
		timeSpawn.CStart();
		render_.setChar(getWidth(), posX, PosY, render_.renderSpecFruit());
		local_map_[PosY][posX] = render_.renderSpecFruit();
		can_spawn_fruit_ = false;
	}
	if (9000 < timeSpawn.CNow()) {
		local_map_[PosY][posX] = 0;
		can_spawn_fruit_ = true;
	}
}

void MainClass::spawnGhost() {
	render_.setChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY, blinky_.getModel());
}

void MainClass::update(float deltaTime) {
	render_.renderMap(local_map_);
	int k = 0;
	for (int i = 0; i < getHeight(); i++) {
		for (int j = 0; j < getWidth(); j++) {
			render_.setChar(getWidth(), j, i, local_map_[i][j]);
			if (34 < i && getHeight() > i && j == 8) {
				render_.setChar(getWidth(), j, i, pac_man_lives_[0]);
			}
			if (7 < i && getWidth() > i && j == 1 && k < scores_.size()) {
				render_.setChar(getWidth(), i, j, scores_[k]);
				k++;
			}
		}
	}

	if (true == pac_man_.getIsEnergized() && 6000 < timeEnergized.CNow()) {
		pac_man_.setIsEnergized(false);
	}

	spawnScepFruit(SpawnSpecFruit1(), spawnPosSpecFruitX1(), spawnPosSpecFruitY());
	spawnScepFruit(SpawnSpecFruit2(), spawnPosSpecFruitX2(), spawnPosSpecFruitY());

	movement();
	ghostMovement();
	spawnPacMan();
	spawnGhost();
	render_.renderScene();
	if (true == pause_) {
		system("pause");
		system("cls");
		pause_ = false;
	}
}

void MainClass::setMovement(int button) {

		if (FORWARD == button &&
			render_.getChar(getWidth(), pac_man_.getPosition().posX, pac_man_.getPosition().posY - 1) != char(getWall())) {

			button_ = button;
		}
		if (BACKWARD == button && 
			render_.getChar(getWidth(), pac_man_.getPosition().posX, pac_man_.getPosition().posY + 1) != char(getWall())) {
			button_ = button;
		}
		if (LEFT == button && 
			render_.getChar(getWidth(), pac_man_.getPosition().posX - 1, pac_man_.getPosition().posY) != char(getWall())) {
			button_ = button;
		}
		if (RIGHT == button &&
			render_.getChar(getWidth(), pac_man_.getPosition().posX + 1, pac_man_.getPosition().posY) != char(getWall())) {
			button_ = button;
		}
}

void MainClass::movement() {
	render_.setChar(getWidth(), pac_man_.getPosition().posX, pac_man_.getPosition().posY, ' ');
	local_map_[pac_man_.getPosition().posY][pac_man_.getPosition().posX] = 0;
	//tryEatPacMan(pac_man_.getPosition());
	switch (button_) {
	case FORWARD:
		if (render_.getChar(getWidth(), pac_man_.getPosition().posX, pac_man_.getPosition().posY - 1) != char(getWall())) {

			eatFruit(pac_man_.getPosition().posX, pac_man_.getPosition().posY - 1);

			pac_man_.setPosition(pac_man_.getPosition().posX,
				pac_man_.getPosition().posY - 1);
		}
		break;

	case BACKWARD:
		if (render_.getChar(getWidth(), pac_man_.getPosition().posX, pac_man_.getPosition().posY + 1) != char(getWall())) {

			//tryEatPacMan(pac_man_.getPosition());

			eatFruit(pac_man_.getPosition().posX, pac_man_.getPosition().posY + 1);

			pac_man_.setPosition(pac_man_.getPosition().posX,
				pac_man_.getPosition().posY + 1);
		}
		break;

	case LEFT:
		if (render_.getChar(getWidth(), pac_man_.getPosition().posX - 1, pac_man_.getPosition().posY) != char(getWall())) {

			//tryEatPacMan(pac_man_.getPosition());

			if (pac_man_.getPosition().posX - 1 == 0) {
				render_.setChar(getWidth(), pac_man_.getPosition().posX,
					pac_man_.getPosition().posY, L' ');
				pac_man_.setPosition(pac_man_.getPosition().posX + endOfField(),
					pac_man_.getPosition().posY);
				render_.setChar(28, pac_man_.getPosition().posX,
					pac_man_.getPosition().posY, pac_man_.getModel());
			}

			eatFruit(pac_man_.getPosition().posX - 1, pac_man_.getPosition().posY);

			pac_man_.setPosition(pac_man_.getPosition().posX - 1,
				pac_man_.getPosition().posY);
		}
		break;

	case RIGHT:
		if (render_.getChar(getWidth(), pac_man_.getPosition().posX + 1, pac_man_.getPosition().posY) != char(getWall())) {

			//tryEatPacMan(pac_man_.getPosition());

			if (pac_man_.getPosition().posX + 1 == getWidth()) {
				render_.setChar(getWidth(), pac_man_.getPosition().posX,
					pac_man_.getPosition().posY, L' ');
				pac_man_.setPosition(pac_man_.getPosition().posX - endOfField(),
					pac_man_.getPosition().posY);
				render_.setChar(28, pac_man_.getPosition().posX,
					pac_man_.getPosition().posY, pac_man_.getModel());
			}

			eatFruit(pac_man_.getPosition().posX + 1, pac_man_.getPosition().posY);

			pac_man_.setPosition(pac_man_.getPosition().posX + 1,
				pac_man_.getPosition().posY);
		}
		break;
	}
}

void MainClass::ghostMovement() {
	if ("UP" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		if ((render_.getChar(getWidth(), blinky_.getPosition().posX - 1, blinky_.getPosition().posY) && 
			render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY - 1)) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX + 1,
				blinky_.getPosition().posY);
		}
		if ((render_.getChar(getWidth(), blinky_.getPosition().posX + 1, blinky_.getPosition().posY) &&
			render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY - 1)) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX - 1,
				blinky_.getPosition().posY);

		}
		if (render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY - 1) == char(getWall())) {
			blinky_.setPosition(blinky_.getPosition().posX - 1,
				blinky_.getPosition().posY);
		} else {
			blinky_.move();
		}
	}

	/*if ("UPLEFT" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		if (render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY - 1) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX - 1,
				blinky_.getPosition().posY);
		}
		else {
			blinky_.move();
		}
	}

	if ("UPRIGHT" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		if (render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY - 1) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX + 1,
				blinky_.getPosition().posY);
		} else {
			blinky_.move();
		}
	}*/

	if ("DOWN" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		if ((render_.getChar(getWidth(), blinky_.getPosition().posX - 1, blinky_.getPosition().posY) &&
			render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY + 1)) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX + 1,
				blinky_.getPosition().posY);
		}
		if ((render_.getChar(getWidth(), blinky_.getPosition().posX + 1, blinky_.getPosition().posY) &&
			render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY + 1)) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX - 1,
				blinky_.getPosition().posY);
		}
		if (render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY + 1) == char(getWall())) {
			blinky_.setPosition(blinky_.getPosition().posX + 1,
				blinky_.getPosition().posY);
		}	else {
			blinky_.move();
		}
	}

	if ("DOWNRIGHT" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		if (render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY + 1) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX + 1,
				blinky_.getPosition().posY);
		}
		else
		{
			blinky_.move();
		}
	}

	if ("DOWNLEFT" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		if (render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY + 1) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX - 1,
				blinky_.getPosition().posY);
		}
		else
		{
			blinky_.move();
		}
	}

	if ("LEFT" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		if ((render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY + 1) &&
			render_.getChar(getWidth(), blinky_.getPosition().posX - 1, blinky_.getPosition().posY)) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX,
				blinky_.getPosition().posY - 1);
		}
		if ((render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY - 1) &&
			render_.getChar(getWidth(), blinky_.getPosition().posX - 1, blinky_.getPosition().posY)) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX,
				blinky_.getPosition().posY + 1);
		}
		if (render_.getChar(getWidth(), blinky_.getPosition().posX - 1, blinky_.getPosition().posY) == char(getWall())) {
			blinky_.setPosition(blinky_.getPosition().posX,
				blinky_.getPosition().posY - 1);
		} else {
			blinky_.move();
		}
	}

	if ("RIGHT" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		if ((render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY + 1) &&
			render_.getChar(getWidth(), blinky_.getPosition().posX + 1, blinky_.getPosition().posY)) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX,
				blinky_.getPosition().posY - 1);
		}
		if ((render_.getChar(getWidth(), blinky_.getPosition().posX, blinky_.getPosition().posY - 1) &&
			render_.getChar(getWidth(), blinky_.getPosition().posX + 1, blinky_.getPosition().posY)) == char(getWall())) {

			blinky_.setPosition(blinky_.getPosition().posX,
				blinky_.getPosition().posY + 1);
		}
		if (render_.getChar(getWidth(), blinky_.getPosition().posX + 1, blinky_.getPosition().posY) == char(getWall())) {
			blinky_.setPosition(blinky_.getPosition().posX,
				blinky_.getPosition().posY + 1);
		}
		else {
			blinky_.move();
		}
	}

	if ("DEAD" == blinky_.findPacMan(pac_man_.getPosition().posX, pac_man_.getPosition().posY)) {
		tryEatPacMan(pac_man_.getPosition(), pac_man_.getIsEnergized());
		eatGhost();
		blinky_.move();
	}
}

void MainClass::eatFruit(int x, int y) {
	if (render_.getChar(getWidth(), x, y) == '.') {
		score_ += nFruitScore();
		scores_ = to_string(score_);
		num_fruits_ += 1;
	}
	if (render_.getChar(getWidth(), x, y) == '*') {
		score_ += eFruitScore();
		scores_ = to_string(score_);

		energizePacMan();
	}
	if (render_.getChar(getWidth(), x, y) == '&') {
		score_ += sFruitScore() * level_;
		scores_ = to_string(score_);
	}
}

void MainClass::eatGhost() {
	if (true == pac_man_.getIsEnergized() &&
		blinky_.getPosition().posX == pac_man_.getPosition().posX &&
		blinky_.getPosition().posY == pac_man_.getPosition().posY) {
		score_ += 100 * level_;
		scores_ = to_string(score_);
	}
}

void MainClass::energizePacMan() {
	timeEnergized.CStart();
	pac_man_.setIsEnergized(true);
}

void MainClass::tryEatPacMan(PositionStruct positionStruct, bool energize) {
	if (positionStruct.posX == blinky_.getPosition().posX && positionStruct.posY == blinky_.getPosition().posY && false == energize) {
		pac_man_.takeDamage(1);
		pac_man_.setPosition(startPacManPosX(), startPacManPosY());
		pac_man_lives_ = to_string(pac_man_.getLives());
	}
}

void MainClass::run() {
	game_field_.generateMap();
	local_map_ = game_field_.getMap();
	int sum = 0;
	int counter = 0;
	int deltaTime = 0;
	num_fruits_ = 0;

	render_.prepScene(getWidth(), getHeight());
	pac_man_.setLives();
	pac_man_.setPosition(startPacManPosX(), startPacManPosY());
	blinky_.setPosition(startXPosBlinky(), startYPosBlinky());
	while (true) {
		timer.CStart();
		if (_kbhit())
		{
			setMovement(_getch());
			//main_menu_.pauseMenu(button_);
			if (!FlushConsoleInputBuffer(render_.mConsoleIn))
				cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
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