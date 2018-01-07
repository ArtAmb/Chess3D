#pragma once
#include "RGB.h"
#include <glut.h>

class Engine3D
{
	void createWindow();
	void initRendering();

public:
	void init(int argc, char**argv);
	void unload();
	void clean(Colors::RGB color);

	void setKeyboard(void(*keyboard)(unsigned char, int, int));
	void setSpecialKeyboard(void(*keyboard)(int, int, int));
	void setSpecialUpKeyboard(void(*keyboard)(int, int, int));
	void setDisplay(void (*dispFunc)(void));
	void setReshape(void(*reshape)(int, int));
	void setTimer(int ms, void(*update)(int), int value);
	void setMouseButtons(void(*mouseButton)(int, int, int, int));
	void setMouseMotion(void(*moveMotion)(int, int));
	void startMainLoop();

	Engine3D(int argc, char**argv);
	~Engine3D();

private:
};

class Engine3DLoader {
	static Engine3D* engine;


public:
	static void loadEngine(int argc, char**argv) { engine = new Engine3D(argc, argv); }
	static Engine3D* getEngine() {
		return engine;
	}

	void unload() {
		engine->unload();
	}
};

