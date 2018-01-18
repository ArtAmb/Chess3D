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
	int listId;
	bool alive = true;
	static void drawChessPhillar(int howMany, float delta);
	static void drawRookPhillar(float radius, int howMany, float translationDelta);
	void init(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard);
public:
	ChessPiece();
	ChessPiece(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard);


	virtual bool checkNextMove(ChessBoardField field) = 0;
	virtual void move(ChessBoardField field) = 0;

	virtual void highlightPossibleMoves() = 0;

	virtual void draw();

	void die() {
		alive = false;
	}

	bool isAlive() {
		return alive;
	}

	virtual ~ChessPiece();
};

