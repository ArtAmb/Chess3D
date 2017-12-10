#pragma once
#include "Engine3D.h"
class Game
{
	static Engine3D* engine;
public:
	static void keyboardFunc(unsigned char key, int x, int y);
	static void displayFunc();
	static void reshapeFunc(int w, int h);
	Game();
	~Game();
};

