#include <iostream>
#include "Game.h"
#include "Point3D.h"
#include "Rectangle3D.h"
#include <glut.h>
Engine3D* Game::engine;

Game::Game()
{
	engine = Engine3DLoader::getEngine();
}


Game::~Game()
{
}


void Game::keyboardFunc(unsigned char key, int x, int y) {

}

void lookAt(Point3D cameraPosition, Point3D placeCameraLookingAt, Point3D cameraVerticalOffset) {
//	std::cout << cameraPosition.toString() << ", " << placeCameraLookingAt.toString() << ", " << cameraVerticalOffset.toString() << std::endl;
	gluLookAt(cameraPosition.getX(), cameraPosition.getY(), cameraPosition.getZ(),
		placeCameraLookingAt.getX(), placeCameraLookingAt.getY(), placeCameraLookingAt.getZ(),
		cameraVerticalOffset.getX(), cameraVerticalOffset.getY(), cameraVerticalOffset.getZ());

}

Rectangle3D board(Point3D(50, 50, 50), 80, 40, 20);

Point3D cameraPosition(0, 0, 3.0);
Point3D placeCameraLookingAt = board.getL1_LB_C_Point();
Point3D cameraVerticalOffset(0.0,1.0,0.0);


void Game::displayFunc() {

	Engine3DLoader::getEngine()->clean(Colors::RGB(1.0, 1.0, 1.0, 1.0));
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	std::cout << cameraPosition.toString() << ", " << placeCameraLookingAt.toString() << ", " << cameraVerticalOffset.toString() << std::endl;
	lookAt(cameraPosition, placeCameraLookingAt, cameraVerticalOffset);
	//Engine3D* e = Engine3DLoader::getEngine();
	//e->glBegin(GL_LINES)->glVertex3f(0, 0, -5)->glVertex3f(2, 2, -5)->glEnd();
	glBegin(GL_POLYGON);
	glColor3f(.5, .5, .5);

	glVertex3fv(board.getL1_LB_C_Point().toVector());
	glVertex3fv(board.getL1_RB_C_Point().toVector());
	glVertex3fv(board.getL1_RT_C_Point().toVector());
	glVertex3fv(board.getL1_LT_C_Point().toVector());

	glVertex3fv(board.getL2_LB_C_Point().toVector());
	glVertex3fv(board.getL2_RB_C_Point().toVector());
	glVertex3fv(board.getL2_RT_C_Point().toVector());
	glVertex3fv(board.getL2_LT_C_Point().toVector());

	glEnd();
	glFlush();
	glutSwapBuffers();
}
void Game::reshapeFunc(int width, int height) {

	/*
	if (width > height)
		glViewport((width - height) / 2, 0, height, height);
	else
	if (width < height)
		glViewport(0, (height - width) / 2, width, width);
		*/
	glViewport(0, 0, height, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, 0.0, height, -100, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

