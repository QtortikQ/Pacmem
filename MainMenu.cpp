#include "MainMenu.h"
#include "Constants.h"

MainMenu::MainMenu() : pause_(false) {
}

MainMenu::~MainMenu() {
}

int MainMenu::mainMenu() {
	render_.prepScene(getWidth(), getHeight());
	render_.renderScene();
	cout << "PacMan(C)" << endl << endl;
	cout << "1: Start the game" << endl;
	cout << "2: Close" << endl;

	cin >> button_;

	if (button_ == '1') {
		return 1;
	}
	if(button_ == '2') {
		return 0;
	}
}

void MainMenu::pauseMenu(int button) {
	if (pauseButton() == button && true == pause_) {
		pause_ = false;
	}
	if (pauseButton() == button && false == pause_) {
		pause_ = true;
	}
}

bool MainMenu::paused() {
	return pause_;
}

int MainMenu::exit() {
	return 0;
}