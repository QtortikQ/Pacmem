#ifndef MAIN_MENU_
#define MAIN_MENU_

#include "Render.h"

class MainMenu
{
public:
	MainMenu();
	virtual ~MainMenu();
	int mainMenu();
	void pauseMenu(int button);
	bool paused();
	int exit();
private:
	char button_;
	bool pause_;
	Render render_;
};

#endif // !MAIN_MENU_