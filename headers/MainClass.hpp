#ifndef MAIN_CLASS_
#define MAIN_CLASS_
//#pragma warning(disable : 4996)

#include "GameField.hpp"
#include "PacMan.hpp"
#include "Blinky.hpp"
#include "Pinky.hpp"
#include "MainMenu.hpp"
#include "Inky.hpp"
#include "Klayd.hpp"

class MainClass
{
public:
	MainClass();
	virtual ~MainClass();
	void spawnPacMan();
	void spawnGhost();
	void spawnScepFruit(int fruit, int posX, int posY);
	void tryEatPacMan(std::vector<int> positionStruct, bool energize);
	void setMovement(int button);
	void run();
	void update(float deltaTime);
	void movement();
	void eatFruit(int x, int y);
	void energizePacMan();
	void ghostMovement();
	void eatGhost();
	void startPause();
	void fillBoard(int &iterationF, int &iterationS);

private:
	int score_;
	int time_;
	int num_fruits_;
	int level_;
	int curr_time_;
	bool can_spawn_fruit_;
	int button_;
	bool pause_;
	std::string pac_man_lives_;
	std::string scores_;
	std::vector<std::string> local_map_;
	std::vector<Ghost*> ghostV;
	//vector<Ghost> ghosts_;
	PacMan pac_man_;
	GameField game_field_;
	Render render_;
	MainMenu main_menu_;
};

#endif