#include "Render.hpp"
#include "Constants.hpp"
//#include <>

Render::Render() {
}

Render::~Render() {
}

void Render::prepScene(int sizeX = getWidth(), int sizeY = getHeight()) {
	SMALL_RECT windowSize = { 0, 0, sizeX, sizeY };
	COORD windowBufSize = { sizeX, sizeY };

	mConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	mConsoleIn = GetStdHandle(STD_INPUT_HANDLE);

	if (!SetConsoleScreenBufferSize(mConsole, windowBufSize))
	{
		std::cout << "SetConsoleScreenBufferSize failed with error " << GetLastError() << std::endl;
	}
	if (!SetConsoleWindowInfo(mConsole, TRUE, &windowSize))
	{
		std::cout << "SetConsoleWindowInfo failed with error " << GetLastError() << std::endl;
	}

	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(mConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(mConsole, &cursorInfo);


	mChiBuffer = (CHAR_INFO*)malloc((sizeX + 1) * (sizeY + 1) * sizeof(CHAR_INFO));

	mDwBufferSize.X = sizeX + 1;
	mDwBufferSize.Y = sizeY + 1;

	mDwBufferCoord.X = 0;
	mDwBufferCoord.Y = 0;

	mLpWriteRegion.Left = 0;
	mLpWriteRegion.Top = 0;
	mLpWriteRegion.Right = sizeX + 1;
	mLpWriteRegion.Bottom = sizeY + 1;

	cleanScene(sizeX, sizeY);
}

void Render::cleanScene(const int &width, const int &height) {
	for (int x = 0; x < width + 1; x++)
	{
		fillBoardWithSpace(x);
	}
}

/*Render::~Render() {
	free(mChiBuffer);
}*/

void Render::renderScene() {
	if (!WriteConsoleOutput(mConsole, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion))
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
	}
}

void Render::renderMap(std::vector<std::string>& mapData){
	for (int i = 0; i < getHeight(); i++) {
		chooseTheSymbol(i, mapData);
	}
}

const char Render::renderSpecFruit() {
	return '&';
}

void Render::setChar(const int &sizeX, const int &x, const int &y, char c)
{
	mChiBuffer[x + (sizeX + 1) * y].Char.AsciiChar = c;
	mChiBuffer[x + (sizeX + 1) * y].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
}

char Render::getChar(const int &sizeX, const int &x, const int &y)
{
	return mChiBuffer[x + (sizeX + 1) * y].Char.AsciiChar;
}

void Render::fillBoardWithSpace(int &iterator){
	for (int y = 0; y < getHeight() + 1; y++)
	{
		setChar(getWidth(), iterator, y, getSpace());
	}
}

void Render::chooseTheSymbol(int &iterator, std::vector<std::string>& mapData) {
	for (int j = 0; j < getWidth(); j++) {
		if (mapData[iterator][j] == '1') {
			mapData[iterator][j] = char(getWall());
		}
		if (mapData[iterator][j] == '2') {
			mapData[iterator][j] = '.';
		}
		if (mapData[iterator][j] == '3') {
			mapData[iterator][j] = '*';
		}
		if (mapData[iterator][j] == '0') {
			mapData[iterator][j] = getSpace();
		}
	}
}