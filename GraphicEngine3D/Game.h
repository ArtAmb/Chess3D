#pragma once
#include "Engine3D.h"
#include "ChessBoard.h"
#include "Camera.h"

enum PLAYER_COLOR { WHITE, BLACK };
enum CHESS_PIECES { PAWN, KNIGHT, TOWER, BISHOP, QUEEN, KING };

class FieldSelector {
	CHESS_ROW row;
	CHESS_COLUMN column;
public:
	FieldSelector() {};
	FieldSelector(CHESS_ROW row, CHESS_COLUMN column) : row(row), column(column) {};
	void move(int x, int y);
	CHESS_ROW getRow() { return row; }
	CHESS_COLUMN getColumn() { return column; };

	void absoluteMove(CHESS_ROW x, CHESS_COLUMN y);
};

class Game
{
	static Engine3D* engine;

	static const int numberOfPieceTypes = 6;
    Colors::RGB whiteColor = Colors::RED;
    Colors::RGB blackColor = Colors::BLUE;

	int piecesDiplayList[2][numberOfPieceTypes];

	FieldSelector fieldSelector;

	void moveSelector(int x, int y) {
		fieldSelector.move(x, y);
	}

	float lx = 0.0f, ly = 0.0f, lz = -1.0f;
	float deltaAngleX = 0.0f;
	float deltaAngleY = 0.0f;
	float deltaMove = 0;
	int xOrigin = -1, yOrigin = -1;
	float _angle = 0.0;
	float _cameraangle = 30.0;
	// XZ position of the camera
	float x = 7.5f, y = 7.0f, z = 30.0f;
		// angle of rotation for the camera direction
	float angleX = 0.0f;
	float angleY = 0.0f;
	const static int numberOfAllOnePlayerPieces = 16;
	ChessPiece* pieces[2][numberOfAllOnePlayerPieces];
	void computePos(float deltaMove);

	float veticalDelta = 0;

	Camera* camera;

	ChessBoard* chessBoard;
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

