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
#include "StateMachine.hpp"

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
	int numFruits_;
	int level_;
	int currTime_;
	bool canSpawnFruit_;
	int button_;
	bool pause_;
	std::string pacManLives_;
	std::string scores_;
	std::string specFruits;
	std::vector<std::string> localMap_;
	std::vector<std::shared_ptr<Ghost>> ghostV;
	//vector<Ghost> ghosts_;
	PacMan pacMan_;
	GameField gameField_;
	Render render_;
	MainMenu mainMenu_;
	StateMachine stateMachine_;
};

#endif