#include "GameField.hpp"
#include "Constants.hpp"

std::vector<std::string> GameField::getMap() {
	return map_;
}

void GameField::generateMap() {
	mapFile_.open("rcs/map.txt");
	if (!mapFile_.is_open()) {
		std::cout << "Wrong file" << std::endl;
	} else {
		map_.resize(getHeight());
		for (int i = 0; i < getHeight(); i++) {
			map_[i].resize(getWidth());
			for (int j = 0; j < getWidth(); j++) {
				mapFile_ >> map_[i][j];
			}
		}
		mapFile_.close();
	}
}