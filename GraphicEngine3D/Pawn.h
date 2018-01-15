#pragma once
#include "ChessPiece.h";

class Pawn : public ChessPiece
{
public:
	Pawn(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard);

	bool checkNextMove(ChessBoardField field);
	void move(ChessBoardField field);

	void highlightPossibleMoves();

	//void draw();
	static void drawPawn(Colors::RGB color);


	Pawn();
	~Pawn();
};

