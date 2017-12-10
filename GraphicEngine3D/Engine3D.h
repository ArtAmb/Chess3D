#pragma once
#include "RGB.h"
#include <glut.h>

class Engine3D
{
	void createWindow();
	void initRendering();

public:
	void init();
	void unload();
	void clean(Colors::RGB color);

	void setKeyboard(void(*keyboard)(unsigned char, int, int));
	void setDisplay(void (*dispFunc)(void));
	void setReshape(void(*reshape)(int, int));
	void startMainLoop();

	Engine3D();
	~Engine3D();

private:
};

class Engine3DLoader {
	static Engine3D* engine;


public:
	static void loadEngine() { engine = new Engine3D(); }
	static Engine3D* getEngine() {
		return engine;
	}

	void unload() {
		engine->unload();
	}
};

