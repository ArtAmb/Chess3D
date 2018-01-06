#include "Engine3D.h"
#include "Game.h"
#include <glut.h>

int main(int argc, char** argv)
{
	Engine3DLoader::loadEngine(argc, argv);
	Engine3D* engine = Engine3DLoader::getEngine();

	engine->setDisplay(Game::displayFunc);
	engine->setKeyboard(Game::keyboardFunc);
	engine->setReshape(Game::reshapeFunc);
	engine->setTimer(25, Game::timerFunc, 0);

	engine->startMainLoop();

	return 0;
}