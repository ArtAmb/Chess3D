#include <iostream>
#include "Engine3DAdapter.h"
#include "Game.h"
#include "Point3D.h"
#include "Rectangle3D.h"
#include "ChessBoard.h"
#include <vector>
#include "GlutHeader.h"
#include "ChessEnums.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include <cmath>

#define M_PI 3.14159265358979323846
Engine3D* Game::engine;

Game::Game()
{
	engine = Engine3DLoader::getEngine();
	camera = new Camera(Point3D(x, y, z), Point3D(x, y, z), Point3D(0.0, 1.0f, 0.0));
	chessBoard = new ChessBoard(Point3D(0.0f, 0.0f, 0.0f), 1, 1, 0.2);
	loadDisplayLists();
	fieldSelector.absoluteMove(CHESS_ROW::R_5, CHESS_COLUMN::C_D);
	for (int i = 0; i < 8; ++i) {
		pieces[WHITE][i] = new Pawn(R_2, (CHESS_COLUMN)i, piecesDiplayList[WHITE][PAWN], chessBoard);
	}

	for (int i = 0; i < 8; ++i) {
		pieces[BLACK][i] = new Pawn(R_7, (CHESS_COLUMN)i, piecesDiplayList[BLACK][PAWN], chessBoard);
	}

	pieces[WHITE][8] = new Bishop(R_1, C_C, piecesDiplayList[WHITE][BISHOP], chessBoard);
	pieces[WHITE][9] = new Bishop(R_1, C_F, piecesDiplayList[WHITE][BISHOP], chessBoard);

	pieces[BLACK][8] = new Bishop(R_8, C_C, piecesDiplayList[BLACK][BISHOP], chessBoard);
	pieces[BLACK][9] = new Bishop(R_8, C_F, piecesDiplayList[BLACK][BISHOP], chessBoard);

	pieces[WHITE][10] = new Rook(R_1, C_A, piecesDiplayList[WHITE][TOWER], chessBoard);
	pieces[WHITE][11] = new Rook(R_1, C_H, piecesDiplayList[WHITE][TOWER], chessBoard);

	pieces[BLACK][10] = new Rook(R_8, C_A, piecesDiplayList[BLACK][TOWER], chessBoard);
	pieces[BLACK][11] = new Rook(R_8, C_H, piecesDiplayList[BLACK][TOWER], chessBoard);

	pieces[WHITE][12] = new Knight(R_1, C_B, piecesDiplayList[WHITE][KNIGHT], chessBoard);
	pieces[WHITE][13] = new Knight(R_1, C_G, piecesDiplayList[WHITE][KNIGHT], chessBoard);

	pieces[BLACK][12] = new Knight(R_8, C_B, piecesDiplayList[BLACK][KNIGHT], chessBoard);
	pieces[BLACK][13] = new Knight(R_8, C_G, piecesDiplayList[BLACK][KNIGHT], chessBoard);

	pieces[WHITE][14] = new Queen(R_1, C_D, piecesDiplayList[WHITE][QUEEN], chessBoard);
	pieces[BLACK][14] = new Queen(R_8, C_D, piecesDiplayList[BLACK][QUEEN], chessBoard);

	pieces[WHITE][15] = new King(R_1, C_E, piecesDiplayList[WHITE][KING], chessBoard);
	pieces[BLACK][15] = new King(R_8, C_E, piecesDiplayList[BLACK][KING], chessBoard);
}

void Game::loadDisplayLists() {
	int i = 0;

	piecesDiplayList[WHITE][PAWN] = glGenLists(++i);
	glNewList(piecesDiplayList[WHITE][PAWN], GL_COMPILE);
	Pawn::drawPawn(whiteColor);
	glEndList();

	piecesDiplayList[BLACK][PAWN] = glGenLists(++i);
	glNewList(piecesDiplayList[BLACK][PAWN], GL_COMPILE);
	Pawn::drawPawn(blackColor);
	glEndList();

    piecesDiplayList[BLACK][BISHOP] = glGenLists(++i);
	glNewList(piecesDiplayList[BLACK][BISHOP], GL_COMPILE);
	Bishop::drawBishop(blackColor);
	glEndList();

	piecesDiplayList[WHITE][BISHOP] = glGenLists(++i);
	glNewList(piecesDiplayList[WHITE][BISHOP], GL_COMPILE);
	Bishop::drawBishop(whiteColor);
	glEndList();

	piecesDiplayList[WHITE][TOWER] = glGenLists(++i);
	glNewList(piecesDiplayList[WHITE][TOWER], GL_COMPILE);
	Rook::drawRook(whiteColor);
	glEndList();

	piecesDiplayList[BLACK][TOWER] = glGenLists(++i);
	glNewList(piecesDiplayList[BLACK][TOWER], GL_COMPILE);
	Rook::drawRook(blackColor);
	glEndList();

    piecesDiplayList[WHITE][KNIGHT] = glGenLists(++i);
	glNewList(piecesDiplayList[WHITE][KNIGHT], GL_COMPILE);
	Knight::drawKnight(whiteColor);
	glEndList();

	piecesDiplayList[BLACK][KNIGHT] = glGenLists(++i);
	glNewList(piecesDiplayList[BLACK][KNIGHT], GL_COMPILE);
	Knight::drawKnight(blackColor);
	glEndList();

	piecesDiplayList[WHITE][QUEEN] = glGenLists(++i);
	glNewList(piecesDiplayList[WHITE][QUEEN], GL_COMPILE);
	Queen::drawQueen(whiteColor);
	glEndList();

	piecesDiplayList[BLACK][QUEEN] = glGenLists(++i);
	glNewList(piecesDiplayList[BLACK][QUEEN], GL_COMPILE);
	Queen::drawQueen(blackColor);
	glEndList();

	piecesDiplayList[WHITE][KING] = glGenLists(++i);
	glNewList(piecesDiplayList[WHITE][KING], GL_COMPILE);
	King::drawKing(whiteColor);
	glEndList();

	piecesDiplayList[BLACK][KING] = glGenLists(++i);
	glNewList(piecesDiplayList[BLACK][KING], GL_COMPILE);
	King::drawKing(blackColor);
	glEndList();

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
		float radDegrees = 1.5707963268; //90
		// update deltaAngle
		
		deltaAngleX = (x - xOrigin) * 0.001f;
		deltaAngleY = (y - yOrigin) * 0.001f;
		// update camera's direction
		lx = sin(angleX + deltaAngleX);
		ly = -sin(angleY + deltaAngleY);
		lz = -cos(angleX + deltaAngleX);
	}
}

void Game::mouseButton(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {
		//std::cout << x << ", " << y << std::endl;
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
	case 'r': camera->reset(); angleX = 0.0f; angleY = 0.0f; lx = 0.0f, ly = 0.0f, lz = -1.0f; break;
	case 'w':
	case 's': veticalDelta = 0; break;
	}
}
float deltaHorizontal = 0;
void Game::releaseSpecialKey(int key, int x, int y) {

	switch (key) {
	case GLUT_KEY_UP:
	case GLUT_KEY_DOWN: deltaMove = 0; break;
	case GLUT_KEY_RIGHT:
	case GLUT_KEY_LEFT: deltaHorizontal = 0; break;
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
		deltaHorizontal = -0.1f;
		break;
	case GLUT_KEY_RIGHT:
		deltaHorizontal = 0.1f;
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
	if (deltaHorizontal) {
		float deltaX = deltaHorizontal * lx * 0.1f;
		float deltaY = deltaHorizontal * ly * 0.1f;
		float deltaZ = deltaHorizontal * lz * 0.1f;
		camera->getPosition()->moveMyself(deltaX, 0, 0);
		camera->getPlaceCameraLookingAt()->moveMyself(deltaX, 0, 0);
	}

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

void FieldSelector::move(int x, int y)
{
	int intX = int(this->row);
	int intY = int(this->column);

	if (intX + x > 7)
		this->row = (CHESS_ROW)7;
	else if (intX + x < 0)
		this->row = (CHESS_ROW)0;
	else
		row = (CHESS_ROW)(intX + x);

	if (intY + y > 7)
		this->column = (CHESS_COLUMN)7;
	else if (intY + y < 0)
		this->column = (CHESS_COLUMN)0;
	else
		column = (CHESS_COLUMN)(intY + y);
	
}

void FieldSelector::absoluteMove(CHESS_ROW x, CHESS_COLUMN y)
{
	this->row = x;
	this->y = y;
}
