#pragma once

class Game;
class Engine3DAdapter
{
	static Game* game;
public:
	Engine3DAdapter();
	~Engine3DAdapter();

	static void setGame(Game* game);

	static void keyboardFunc(unsigned char key, int x, int y);
	static void specialKeyboardFunc(int key, int x, int y);
	static void specialKeyboardUpFunc(int key, int x, int y);
	static void keyboardUpFunc(unsigned char key, int x, int y);
	static void displayFunc();
	static void reshapeFunc(int w, int h);
	static void timerFunc(int value);
	static void mouseButtonsFunc(int button, int state, int x, int y);
	static void mouseMotionFunc(int x, int y);
};

