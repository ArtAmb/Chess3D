#include <iostream>
#include "Game.h"
#include "Point3D.h"
#include "Rectangle3D.h"
#include "ChessBoard.h"
#include <glut.h>
Engine3D* Game::engine;

Game::Game()
{
	engine = Engine3DLoader::getEngine();
}


Game::~Game()
{
}

float _angle = 0.0;
float _cameraangle = 30.0;

void Game::timerFunc(int value)
{
	_angle += 2.0f;
	if (_angle>360.f)
	{
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, timerFunc, 0);
}

void Game::keyboardFunc(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27:
		exit(0);
	}
}

void lookAt(Point3D cameraPosition, Point3D placeCameraLookingAt, Point3D cameraVerticalOffset) {
//	std::cout << cameraPosition.toString() << ", " << placeCameraLookingAt.toString() << ", " << cameraVerticalOffset.toString() << std::endl;
	gluLookAt(cameraPosition.getX(), cameraPosition.getY(), cameraPosition.getZ(),
		placeCameraLookingAt.getX(), placeCameraLookingAt.getY(), placeCameraLookingAt.getZ(),
		cameraVerticalOffset.getX(), cameraVerticalOffset.getY(), cameraVerticalOffset.getZ());

}

//Rectangle3D board(Point3D(50, 50, 50), 80, 40, 20);
ChessBoard chessBoard(Point3D(-1.0f, -1.0f, -1.0f), 0.2, 0.2, 0.2);
Point3D cameraPosition(0, 0, 3.0);
//Point3D placeCameraLookingAt = boardCube1.getL1_LB_C_Point();
Point3D cameraVerticalOffset(0.0,1.0,0.0);

void Game::displayFunc() {

	Engine3DLoader::getEngine()->clean(Colors::RGB(1.0, 1.0, 1.0, 1.0));
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//std::cout << cameraPosition.toString() << ", " << placeCameraLookingAt.toString() << ", " << cameraVerticalOffset.toString() << std::endl;
	//lookAt(cameraPosition, placeCameraLookingAt, cameraVerticalOffset);
	//Engine3D* e = Engine3DLoader::getEngine();
	//e->glBegin(GL_LINES)->glVertex3f(0, 0, -5)->glVertex3f(2, 2, -5)->glEnd();
	glRotatef(_cameraangle, 0.0f, 1.0f, 0.0f);
	glTranslatef(0.0f, 0.0f, -10.0f);

	glPushMatrix();
	glTranslatef(5.0f, -1.0f, 0.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(_angle, 1.0f, 3.0f, 2.0f); //rotating object continuously by 2 degree

	glBegin(GL_QUADS);
	chessBoard.draw();
	glEnd();

	glPopMatrix();
	//glFlush();
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
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
	//glOrtho(0.0, width, 0.0, height, -100, 100);
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

}

