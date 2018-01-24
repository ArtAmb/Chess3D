/* Autorzy: Ambrolewicz Artur, Bątkowska Karolina */
#include "Engine3D.h"
#include "Game.h"
#include "Engine3DAdapter.h"
#include "GlutHeader.h"
#include "World.h"


int main(int argc, char** argv)
{
	Engine3DLoader::loadEngine(argc, argv);
	Engine3D* engine = Engine3DLoader::getEngine();
	Game game;
	Engine3DAdapter::setGame(&game);

	engine->setDisplay(Engine3DAdapter::displayFunc);
	engine->setKeyboard(Engine3DAdapter::keyboardFunc);
	engine->setSpecialKeyboard(Engine3DAdapter::specialKeyboardFunc);
	engine->setSpecialUpKeyboard(Engine3DAdapter::specialKeyboardUpFunc);
	engine->setKeyboardUp(Engine3DAdapter::keyboardUpFunc);
	engine->setReshape(Engine3DAdapter::reshapeFunc);
	engine->mouseButtonsFunc(Engine3DAdapter::mouseButtonsFunc);
	engine->mouseMotionFunc(Engine3DAdapter::mouseMotionFunc);
	engine->prepareTextures();
	engine->setLightsAndMaterials();

	engine->setTimer(25, Engine3DAdapter::timerFunc, 0);

	engine->startMainLoop();




	return 0;
}
