#include "World.h"


World::World() {
}

World::~World() {
}
/*
World::World(Point3D startPoint) {
	this->startPoint = startPoint;
}
*/

void World::draw( ) {



    Engine3DLoader::getEngine()->glColor3c(Colors::LIGHTBLUE);
   	glutSolidSphere(30, 100,100);
}

