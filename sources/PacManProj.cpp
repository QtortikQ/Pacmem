#include "MainClass.hpp"
#include <Windows.h>
#include <iostream>

int main()
{
	//SetConsoleCP(437);
	//SetConsoleOutputCP(437);


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
