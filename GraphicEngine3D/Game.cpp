#include <iostream>
#include "Engine3DAdapter.h"
#include "Game.h"
#include "Point3D.h"
#include "Rectangle3D.h"
#include "ChessBoard.h"
#include <vector>
#include <glut.h>
#include "AssimpLoader.h"
#include "ChessEnums.h"
#include "Pawn.h"
#include <cmath>

#define M_PI 3.14159265358979323846
Engine3D* Game::engine;

Game::Game()
{
	engine = Engine3DLoader::getEngine();
	camera = new Camera(Point3D(x, y, z), Point3D(x, y, z), Point3D(0.0, 1.0f, 0.0));
	chessBoard = new ChessBoard(Point3D(0.0f, 0.0f, 0.0f), 1, 1, 0.2);

	Colors::RGB whiteColor = Colors::RED;
	Colors::RGB blackColor = Colors::BLUE;
	pieces[WHITE][0] = new Pawn(R_2, C_A, whiteColor, chessBoard);
	pieces[WHITE][1] = new Pawn(R_2, C_B, whiteColor, chessBoard);
	pieces[WHITE][2] = new Pawn(R_2, C_C, whiteColor, chessBoard);
	pieces[WHITE][3] = new Pawn(R_2, C_D, whiteColor, chessBoard);
	pieces[WHITE][4] = new Pawn(R_2, C_E, whiteColor, chessBoard);
	pieces[WHITE][5] = new Pawn(R_2, C_F, whiteColor, chessBoard);
	pieces[WHITE][6] = new Pawn(R_2, C_G, whiteColor, chessBoard);
	pieces[WHITE][7] = new Pawn(R_2, C_H, whiteColor, chessBoard);

	pieces[BLACK][0] = new Pawn(R_7, C_A, blackColor, chessBoard);
	pieces[BLACK][1] = new Pawn(R_7, C_B, blackColor, chessBoard);
	pieces[BLACK][2] = new Pawn(R_7, C_C, blackColor, chessBoard);
	pieces[BLACK][3] = new Pawn(R_7, C_D, blackColor, chessBoard);
	pieces[BLACK][4] = new Pawn(R_7, C_E, blackColor, chessBoard);
	pieces[BLACK][5] = new Pawn(R_7, C_F, blackColor, chessBoard);
	pieces[BLACK][6] = new Pawn(R_7, C_G, blackColor, chessBoard);
	pieces[BLACK][7] = new Pawn(R_7, C_H, blackColor, chessBoard);

}


void Game::drawChessPieces() {

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < numberOfAllOnePlayerPieces; ++j) {
			if (pieces[i][j]->isAlive()) {
				glPushMatrix();
				pieces[i][j]->draw();
				glPopMatrix();

			}
		}
	}
}

Game::~Game()
{
	delete camera;
	delete chessBoard;
}


void Game::timerFunc(int value)
{
	_angle += 2.0f;
	if (_angle > 360.f)
	{
		_angle -= 360;
	}
	glutPostRedisplay();
	Engine3DLoader::getEngine()->setTimer(25, Engine3DAdapter::timerFunc, 0);
}


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
		camera->getPosition()->moveMyself(-0.1f, 0, 0);
		break;
	case GLUT_KEY_RIGHT:
		camera->getPosition()->moveMyself(0.1f, 0, 0);
		break;
	}
}



void Game::computePos(float deltaMove) {
	float deltaX = deltaMove * lx * 0.1f;
	float deltaY = deltaMove * ly * 0.1f;
	float deltaZ = deltaMove * lz * 0.1f;
	camera->getPosition()->moveMyself(deltaX, deltaY, deltaZ);
	camera->getPlaceCameraLookingAt()->moveMyself(deltaX, deltaY, deltaZ);
}

void drawChessPhillar(int howMany, float delta) {
	float radius = delta*howMany;
	float z = 0.1;
	for (int i = 0; i < howMany; ++i) {
		glTranslatef(0, 0, -i*delta);
		glutSolidTorus(radius, radius, 100, 200);
		radius -= delta;
		z += 0.1;
	}
}

void Game::settingMatrixProperly() {
	glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(90, 1.0f, 0, 0);
}

void Game::displayFunc() {
	Engine3DLoader::getEngine()->clean(Colors::WHITE);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	if (deltaMove)
		computePos(deltaMove);
	if (veticalDelta)
		camera->getPlaceCameraLookingAt()->moveMyself(0, veticalDelta * 0.1, 0);

	camera->lookAtWithOffset(Point3D::getEmptyPoint(), Point3D(lx, ly, lz), Point3D::getEmptyPoint());

	//Engine3D* e = Engine3DLoader::getEngine();
	//e->glBegin(GL_LINES)->glVertex3f(0, 0, -5)->glVertex3f(2, 2, -5)->glEnd();
	
	//engine->displayText(-2, 0, Colors::RED, "cameraPosition: " + camera->getPosition()->toString());
	//engine->displayText(-2, 0.1, Colors::RED, "placeCameraLookingAt: " + camera->getPlaceCameraLookingAt()->toString());
	//engine->displayText(-2, 0.2, Colors::RED, "cameraVerticalOffset: " + camera->getVerticalOffset()->toString());
	
	//glRotatef(_cameraangle, 0.0f, 1.0f, 0.0f);
	settingMatrixProperly();
	glPushMatrix();

	glBegin(GL_QUADS);
	chessBoard->draw();
	glEnd();
	glPopMatrix();

	drawChessPieces();
	
	/*glPushMatrix();
	settingMatrixProperly();
	engine->glColor(Colors::RED);
	//chessBoard->getField(C_E, R_6)->translateToFieldCenter(Point3D(0, 0, 0));
	//drawPawn();
	glPopMatrix();*/
	//Engine3DLoader::getEngine()->drawLoadedModels();


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

