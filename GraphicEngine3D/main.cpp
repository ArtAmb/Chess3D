#include "Engine3D.h"
#include "Game.h"
#include <glut.h>

int main(int argc, char** argv)
{
	Engine3DLoader::loadEngine();
	Engine3D* engine = Engine3DLoader::getEngine();

	engine->setDisplay(Game::displayFunc);
	engine->setReshape(Game::reshapeFunc);
	engine->setKeyboard(Game::keyboardFunc);

	engine->startMainLoop();

	return 0;
}