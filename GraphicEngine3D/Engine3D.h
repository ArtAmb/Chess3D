#pragma once
#include <iostream>
#include "RGB.h"
#include "Point3D.h"
#include "GlutHeader.h"

class Engine3D
{
	void createWindow();
	void initRendering();

public:
	void loadModels();
	void drawLoadedModels();
	void init(int argc, char**argv);
	void unload();
	void clean(Colors::RGB color);
	void displayText(float x, float y, Colors::RGB color, std::string string);

	void setKeyboard(void(*keyboard)(unsigned char, int, int));
	void setSpecialKeyboard(void(*keyboard)(int, int, int));
	void setSpecialUpKeyboard(void(*keyboard)(int, int, int));
	void setKeyboardUp(void(*keyboard)(unsigned char, int, int));
	void setDisplay(void (*dispFunc)(void));
	void setReshape(void(*reshape)(int, int));
	void setTimer(int ms, void(*update)(int), int value);
	void mouseButtonsFunc(void(*mouseButton)(int, int, int, int));
	void mouseMotionFunc(void(*moveMotion)(int, int));

	void startMainLoop();
	void setLightsAndMaterials();

	Engine3D* glVertex3p(Point3D p);
	Engine3D* glColor3c(Colors::RGB c);

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

