#pragma once

#include <iostream>

#include "GlutHeader.h"
#include "Engine3D.h"



class World {

	GLUquadric * state=gluNewQuadric();;
	int numberOfTexture;



public:
Colors::RGB color;
	World();

	~World();


	void draw(int numberOfTexture);
	void killWorld();

};


