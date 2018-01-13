#include <iostream>
#include "Game.h"
#include "Point3D.h"
#include "Rectangle3D.h"
#include "ChessBoard.h"
#include <vector>
#include <glut.h>
#include "AssimpLoader.h"
#include "ChessEnums.h"
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
// XZ position of the camera
float x = 7.5f, y = 7.0f, z = 30.0f;
void Game::timerFunc(int value)
{
	_angle += 2.0f;
	if (_angle > 360.f)
	{
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, timerFunc, 0);
}

//Point3D cameraPosition(0, 0, 3.0);
float veticalDelta = 0;
Point3D cameraPosition(x, y, z);//(727.987000, -0.000885009998, -1539.59998);//
void Game::keyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
	case 'w':
		veticalDelta = 0.5;
		//cameraPosition.moveMyself(0,0,0.01f);
	 break;
	case 's':
		veticalDelta = -0.5;
		//cameraPosition.moveMyself(0, 0, 0.01f);
		break;


	case 27:
		exit(0);
	}
}

// angle of rotation for the camera direction
float angleX = 0.0f;
float angleY = 0.0f;

// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
float deltaAngleX = 0.0f;
float deltaAngleY = 0.0f;
float deltaMove = 0;
int xOrigin = -1, yOrigin = -1;

void Game::mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngleX = (x - xOrigin) * 0.001f;
		deltaAngleY = (y - yOrigin) * 0.001f;
		// update camera's direction
		lx = sin(angleX + deltaAngleX);
		ly = sin(angleY + deltaAngleY);
		lz = -cos(angleX + deltaAngleX);
	}
}

void Game::mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angleX += deltaAngleX;
			angleY += deltaAngleY;
			xOrigin = -1;
			yOrigin = -1;
		}
		else {// state = GLUT_DOWN
			xOrigin = x;
			yOrigin = y;
		}
	}
}

void Game::releaseKey(unsigned char key, int x, int y) {

	switch (key) {
	case 'w':
	case 's': veticalDelta = 0; break;
	}
}

void Game::releaseSpecialKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN: deltaMove = 0; break;
	}
}

void Game::specialKeyboard(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		//cameraPosition.moveMyself(0, 0.1f, 0);
		deltaMove = 0.5f;
		break;
	case GLUT_KEY_DOWN:
		//cameraPosition.moveMyself(0, -0.1f, 0);
		deltaMove = -0.5f;
		break;
	case GLUT_KEY_LEFT:
		cameraPosition.moveMyself(-0.1f, 0, 0);
		break;
	case GLUT_KEY_RIGHT:
		cameraPosition.moveMyself(0.1f, 0, 0);
		break;
	}
}
void lookAt(Point3D cameraPosition, Point3D placeCameraLookingAt, Point3D cameraVerticalOffset) {
	//	std::cout << cameraPosition.toString() << ", " << placeCameraLookingAt.toString() << ", " << cameraVerticalOffset.toString() << std::endl;
	gluLookAt(cameraPosition.getX(), cameraPosition.getY(), cameraPosition.getZ(),
		placeCameraLookingAt.getX(), placeCameraLookingAt.getY(), placeCameraLookingAt.getZ(),
		cameraVerticalOffset.getX(), cameraVerticalOffset.getY(), cameraVerticalOffset.getZ());

}

void displayText(float x, float y, Colors::RGB color, std::string string) {
	glColor3f(color.getR(), color.getG(), color.getB());
	glRasterPos2f(x, y);
	for (unsigned int i = 0; i < string.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
	}
}
//Rectangle3D board(Point3D(50, 50, 50), 80, 40, 20);
ChessBoard chessBoard(Point3D(0.0f, 0.0f, 0.0f), 1, 1, 0.2);
Point3D placeCameraLookingAt(x, y, z);//(727.987000, -0.000885009998, -1539.59998);
Point3D cameraVerticalOffset(0.0, 1.0f, 0.0);


void computePos(float deltaMove) {
	float deltaX = deltaMove * lx * 0.1f;
	float deltaY = deltaMove * ly * 0.1f;
	float deltaZ = deltaMove * lz * 0.1f;
	cameraPosition.moveMyself(deltaX, deltaY, deltaZ);
	placeCameraLookingAt.moveMyself(deltaX, deltaY, deltaZ);
}

void Game::displayFunc() {
	Engine3DLoader::getEngine()->clean(Colors::WHITE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	if (deltaMove)
		computePos(deltaMove);
	if (veticalDelta)
		placeCameraLookingAt.moveMyself(0, veticalDelta * 0.1, 0);

	lookAt(cameraPosition, placeCameraLookingAt.move(lx, ly, lz), cameraVerticalOffset);

	//Engine3D* e = Engine3DLoader::getEngine();
	//e->glBegin(GL_LINES)->glVertex3f(0, 0, -5)->glVertex3f(2, 2, -5)->glEnd();
	displayText(-2, 0, Colors::RED, "cameraPosition: " + cameraPosition.toString());
	displayText(-2, 0.1, Colors::RED, "placeCameraLookingAt: " + placeCameraLookingAt.toString());
	displayText(-2, 0.2, Colors::RED, "cameraVerticalOffset: " + cameraVerticalOffset.toString());
	//glRotatef(_cameraangle, 0.0f, 1.0f, 0.0f);
	glPushMatrix();
    glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(90, 1.0f, 0, 0);
	glBegin(GL_QUADS);
	chessBoard.draw();
	glEnd();
	
	/*glBegin(GL_POINT);
	glColor3f(Colors::BLUE.getR(), Colors::BLUE.getG(), Colors::BLUE.getB());
	chessBoard.getField(C_E, R_6)->translateToFieldCenter(Point3D(0,0,0));
	//glVertex3fv(chessBoard.getField(C_E, R_6)->getCube().getStartPoint().toVector());
	glEnd(); */
	glColor3f(Colors::RED.getR(), Colors::RED.getG(), Colors::RED.getB());
	//glTranslatef(5.0f, -1.0f, 0.0f);
	chessBoard.getField(C_E, R_6)->translateToFieldCenter(Point3D(0, 0, 0));
	glScalef(0.25f, 0.25f, 0.25f);
	glutSolidTorus(0.2f, 1.0f,100,200);
	//Engine3DLoader::getEngine()->drawLoadedModels();
	
	glPopMatrix();

	//glFlush();
	glutSwapBuffers();
}
void Game::reshapeFunc(int width, int height) {

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);


}

