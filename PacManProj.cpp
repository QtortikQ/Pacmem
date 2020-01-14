#include "MainClass.h"

int main()
{
	int choice;
	MainMenu mainMenu;
	MainClass mainClass;
	while (true) {
		system("cls");
		choice = mainMenu.mainMenu();
		if (1 == choice) {
			mainClass.run();
		}
		if (0 == choice) {
			break;
		}
	}
}
