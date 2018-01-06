#pragma once
#include "Rectangle3D.h"
#include <iostream>

enum  CHESS_COLUMN { C_A = 0, C_B, C_C, C_D, C_E, C_F, C_G, C_H };
enum  CHESS_ROW { R_1 = 0, R_2, R_3, R_4, R_5, R_6, R_7, R_8 };

class ChessBoardField {
private:
	CHESS_ROW x;
	CHESS_COLUMN y;

	Rectangle3D boardCube;
public:

	Rectangle3D getCube() { return boardCube; }
	ChessBoardField() {}

	ChessBoardField(CHESS_ROW x, CHESS_COLUMN y, Rectangle3D boardCube) {
		this->x = x;
		this->y = y;
		this->boardCube = boardCube;
	}

	int getRow() {
		return x;
	}


	int getColumn() {
		return y;
	}
};

class ChessBoard {
	const static int BOARD_SIZE = 8;
	ChessBoardField board[BOARD_SIZE][BOARD_SIZE];

	Point3D startPoint;
	float cubeL, cubeW, cubeH;
	float boardL, boardW, boardH;

	void initBoard();
public:
	ChessBoard();
	ChessBoard(Point3D, float cubeL, float cubeW, float cubeH);
	~ChessBoard();

	void setCubeSizes(float l, float w, float h);
	void setBoardSizes(float l, float w, float h);

	void draw();
};

