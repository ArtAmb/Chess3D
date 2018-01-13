#pragma once
#include "Engine3D.h"
class Game
{
	static Engine3D* engine;
public:
	static void keyboardFunc(unsigned char key, int x, int y);
	static void specialKeyboard(int key, int x, int y);
	static void displayFunc();
	static void reshapeFunc(int w, int h);
	static void timerFunc(int value);
	static void mouseButton(int button, int state, int x, int y);
	static void mouseMove(int x, int y);
	static void releaseKey(unsigned char key, int x, int y);
	static void releaseSpecialKey(int key, int x, int y);

	Game();
	~Game();
};

