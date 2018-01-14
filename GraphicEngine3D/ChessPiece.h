#pragma once
#include "ChessEnums.h"
#include "RGB.h"

class ChessBoard;
class ChessBoardField;
class ChessPiece
{
protected:
	ChessBoard* chessBoard;
	CHESS_ROW row;
	CHESS_COLUMN column;
	Colors::RGB color;
	bool alive = true;
	void drawChessPhillar(int howMany, float delta);
	void init(CHESS_ROW r, CHESS_COLUMN col, Colors::RGB c, ChessBoard* chessBoard);
public:
	ChessPiece();
	ChessPiece(CHESS_ROW r, CHESS_COLUMN col, Colors::RGB color, ChessBoard* chessBoard);


	virtual bool checkNextMove(ChessBoardField field) = 0;
	virtual void move(ChessBoardField field) = 0;

	virtual void highlightPossibleMoves() = 0;

	virtual void draw() = 0;

	void die() {
		alive = false;
	}

	bool isAlive() {
		return alive;
	}

	virtual ~ChessPiece();
};

