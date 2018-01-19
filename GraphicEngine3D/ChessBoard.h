#pragma once
#include "ChessPiece.h"
#include "Rectangle3D.h"
#include <iostream>
#include "ChessEnums.h"
#include "GlutHeader.h"
#include "Engine3D.h"

class ChessBoardField {
private:
	CHESS_ROW x;
	CHESS_COLUMN y;
	ChessPiece* piece = NULL;
	Rectangle3D boardCube;
	bool isHighlighted = false;
public:
	~ChessBoardField() {

	}
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

	void highlight() {
		isHighlighted = true;
	}

	void stopHighliting() {
		isHighlighted = false;
	}

	int getColumn() {
		return y;
	}

	void translateToFieldCenter(Point3D point) {
		boardCube.translateToTopCenterOfTopField(point);
		//highlight();
	}

	void draw(Colors::RGB color);

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

	Point3D getStartPoint() { return startPoint; }


	ChessBoardField* getField(CHESS_COLUMN c, CHESS_ROW r);
	void setCubeSizes(float l, float w, float h);
	void setBoardSizes(float l, float w, float h);

	void draw();
};

