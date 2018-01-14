#include "Engine3DAdapter.h"
#include "Game.h"
Game* Engine3DAdapter::game;

Engine3DAdapter::Engine3DAdapter()
{
}


Engine3DAdapter::~Engine3DAdapter()
{
}

void Engine3DAdapter::setGame(Game * game)
{
	Engine3DAdapter::game = game;
}

void Engine3DAdapter::keyboardFunc(unsigned char key, int x, int y)
{
	game->keyboardFunc(key,x, y);
}

void Engine3DAdapter::specialKeyboardFunc(int key, int x, int y)
{
	game->specialKeyboard(key, x, y);
}

void Engine3DAdapter::keyboardUpFunc(unsigned char key, int x, int y)
{
	game->releaseKey(key, x, y);
}

void Engine3DAdapter::displayFunc()
{
	game->displayFunc();
}

void Engine3DAdapter::reshapeFunc(int w, int h)
{
	game->reshapeFunc(w,h);
}

void Engine3DAdapter::timerFunc(int value)
{
	game->timerFunc(value);
}

void Engine3DAdapter::mouseMotionFunc(int x, int y)
{
	game->mouseMove(x, y);
}

void Engine3DAdapter::mouseButtonsFunc(int button, int state, int x, int y)
{
	game->mouseButton(button, state, x, y);
}

void Engine3DAdapter::specialKeyboardUpFunc(int key, int x, int y)
{
	game->releaseSpecialKey(key, x, y);
}
