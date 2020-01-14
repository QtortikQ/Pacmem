#include "GameField.h"
#include "Constants.h"

vector<string> GameField::getMap() {
	return map_;
}

void GameField::generateMap() {
	mapFile_.open("map.txt");
	map_.resize(getHeight());
	for (int i = 0; i < getHeight(); i++) {
		map_[i].resize(getWidth());
		for (int j = 0; j < getWidth(); j++) {
			mapFile_ >> map_[i][j];
		}
	}
	mapFile_.close();
}