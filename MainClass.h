#ifndef MAIN_CLASS_
#define MAIN_CLASS_
//#pragma warning(disable : 4996)

#include "GameField.h"
#include "Render.h"
#include "PacMan.h"
#include "Blinky.h"
#include "Pinky.h"
#include "MainMenu.h"

class MainClass
{
public:
	MainClass();
	virtual ~MainClass();
	void spawnPacMan();
	void spawnGhost();
	void spawnScepFruit(int fruit, int posX, int posY);
	void tryEatPacMan(PositionStruct positionStruct, bool energize);
	void setMovement(int button);
	void run();
	void update(float deltaTime);
	void movement();
	void eatFruit(int x, int y);
	void energizePacMan();
	void ghostMovement();
	void eatGhost();

private:
	int score_;
	int time_;
	int num_fruits_;
	int level_;
	int curr_time_;
	bool can_spawn_fruit_;
	int button_;
	bool pause_;
	string pac_man_lives_;
	string scores_;
	vector<string> local_map_;
	//vector<Ghost> ghosts_;
	PacMan pac_man_;
	GameField game_field_;
	Render render_;
	Blinky blinky_;
	Pinky pinky_;
	MainMenu main_menu_;
};

#endif