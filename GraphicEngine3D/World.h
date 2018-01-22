#pragma once

#include <iostream>

#include "GlutHeader.h"
#include "Engine3D.h"



class World {

	//Point3D startPoint;



public:
Colors::RGB color;
	World();
	//World(Point3D);
	~World();


	void draw();
};


