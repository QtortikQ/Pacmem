#include "MainMenu.hpp"
#include "Constants.hpp"

MainMenu::MainMenu() : pause_(false) {
}

MainMenu::~MainMenu() {
}

int MainMenu::mainMenu() {
	render_.prepScene(getWidth(), getHeight());
	render_.renderScene();
	std::cout << "PacMan(C)" << std::endl << std::endl;
	std::cout << "1: Start the game" << std::endl;
	std::cout << "2: Close" << std::endl;

	std::cin >> button_;

	if (button_ == '1') {
		return 1;
	}
	if(button_ == '2') {
		return 0;
	} else {
		return 0;
	}
}

void MainMenu::pauseMenu(int button) {
	if (pauseButton() == button && true == pause_) {
		pause_ = false;
	}
	if (pauseButton() == button && false == pause_) {
		pause_ = true;
	} else {
		std::cout << "Something went wrong!" << std::endl;
	}
}

bool MainMenu::paused() {
	return pause_;
}

int MainMenu::exit() {
	return 0;
}