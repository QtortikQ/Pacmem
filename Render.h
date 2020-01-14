#ifndef RENDER_
#define RENDER_

#include "PositionStruct.h"
#include <vector>
#include <string>
#include <windows.h>
#include <assert.h>
#include <strsafe.h>
#include <algorithm>
#include <time.h>
#include <iostream>


using namespace std;

class Render
{
public:
	HANDLE mConsoleIn;
	CHAR_INFO* mChiBuffer;
	void prepScene(int sizeX, int sizeY);
	void renderScene();
	void renderMap(vector<string>& mapData);
	char renderSpecFruit();
	void setChar(int sizeX, int x, int y, char c);
	char getChar(int sizeX, int x, int y);
	void cleanScene(int width, int height);
private:
	HANDLE mConsole;
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;
};

#endif