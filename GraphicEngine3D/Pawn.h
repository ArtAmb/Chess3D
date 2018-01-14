#pragma once
#include "ChessPiece.h";

class Pawn : public ChessPiece
{
public:
	Pawn(CHESS_ROW , CHESS_COLUMN, Colors::RGB, ChessBoard* chessBoard);

	bool checkNextMove(ChessBoardField field);
	void move(ChessBoardField field);

	void highlightPossibleMoves();

	void draw();

	Pawn();
	~Pawn();
};

