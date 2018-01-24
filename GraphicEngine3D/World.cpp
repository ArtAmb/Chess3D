#include "World.h"


World::World()
{
}

World::~World()
{
	gluDeleteQuadric(state);
}
/*
World::World(Point3D startPoint) {
	this->startPoint = startPoint;
}
*/

void World::draw( int numberOfTexture )
{
    Engine3DLoader::getEngine()->glColor3c(Colors::WHITE);
    //state =gluNewQuadric();

    gluQuadricNormals(state, GLU_SMOOTH);
    gluQuadricTexture(state,GL_TRUE);

    glBindTexture(GL_TEXTURE_2D,Engine3DLoader::getEngine()->tex[numberOfTexture]);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glEnable(GL_TEXTURE_2D);
    gluSphere(state, 25, 100,100);

   // gluDeleteQuadric(state);
    glDisable(GL_TEXTURE_2D);

}

void World::killWorld()
{
    gluDeleteQuadric(state);
}

