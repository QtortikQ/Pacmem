#ifndef GAME_FIELD_
#define GAME_FIELD_

#include "PositionStruct.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class GameField
{
public:
	vector<string> getMap();
	void generateMap();
private:
	ifstream mapFile_;
	PositionStruct position_struct_;
	vector<string> map_;
};

#endif