#include "Engine3D.h"
#include "Game.h"
#include <glut.h>

int main(int argc, char** argv)
{
	Engine3DLoader::loadEngine(argc, argv);
	Engine3D* engine = Engine3DLoader::getEngine();

	engine->setDisplay(Game::displayFunc);
	engine->setKeyboard(Game::keyboardFunc);
	engine->setSpecialKeyboard(Game::specialKeyboard);
	engine->setSpecialUpKeyboard(Game::releaseKey);
	engine->setReshape(Game::reshapeFunc);
	engine->setMouseButtons(Game::mouseButton);
	engine->setMouseMotion(Game::mouseMove);
	engine->setTimer(25, Game::timerFunc, 0);

	engine->startMainLoop();

	return 0;
}