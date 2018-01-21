#pragma once
#include "Engine3D.h"
#include "ChessBoard.h"
#include "Camera.h"
#include "FieldSelector.h"
#include "ChessEnums.h"


class Game
{
	static Engine3D* engine;

	static const int numberOfPieceTypes = 6;
    Colors::RGB whiteColor = Colors::RED;
    Colors::RGB blackColor = Colors::BLUE;

    FieldSelector fieldSelector;

	void moveSelector(int x, int y) {
		fieldSelector.move(x, y);
	}

	int piecesDiplayList[2][numberOfPieceTypes];
	float lx = -0.0119997f, ly = -0.549696f, lz = -0.999928f;
	float deltaAngleX = 0.0f;
	float deltaAngleY = 0.0f;
	float deltaMove = 0;
	int xOrigin = -1, yOrigin = -1;
	float _angle = 0.0;
	float _cameraangle = 30.0;
	// XZ position of the camera
	//float x = -7.5f, y = 7.0f, z = 30.0f;
	float x = -7.92386f, y = 11.4153f, z = 26.6328f;
	float angleX = -0.012f;
	float angleY = 0.566f;
	const static int numberOfAllOnePlayerPieces = 16;
	ChessPiece* pieces[2][numberOfAllOnePlayerPieces];
	void computePos(float deltaMove);

	float veticalDelta = 0;

	Camera* camera;
	
	ChessBoard* chessBoard;

	bool isIntroPlaying = true;
	void playIntro();
	void stopIntro();
public:
	void keyboardFunc(unsigned char key, int x, int y);
	void specialKeyboard(int key, int x, int y);
	void settingMatrixProperly();
	void displayFunc();
	void reshapeFunc(int w, int h);
	void timerFunc(int value);
	void mouseButton(int button, int state, int x, int y);
	void mouseMove(int x, int y);
	void releaseKey(unsigned char key, int x, int y);
	void releaseSpecialKey(int key, int x, int y);

	Game();
	void loadDisplayLists();
	void drawChessPieces();
	~Game();
};

