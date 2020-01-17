#ifndef RENDER_
#define RENDER_

#include <vector>
#include <string>
#include <windows.h>
#include <assert.h>
#include <strsafe.h>
#include <algorithm>
#include <time.h>
#include <iostream>

class Render
{
public:
	Render();
	virtual ~Render();
	HANDLE mConsoleIn;
	CHAR_INFO* mChiBuffer;
	void prepScene(const int sizeX, const int sizeY);
	void renderScene();
	void renderMap(std::vector<std::string>& mapData);
	const char renderSpecFruit();
	void setChar(const int &sizeX, const int &x, const int &y, char c);
	char getChar(const int &sizeX, const int &x, const int &y);
	void cleanScene(const int &width, const int &height);
private:
	HANDLE mConsole;
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;
};

#endif