#pragma once
#include "ChessPiece.h";

class King : public ChessPiece
{
public:
	King(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard);

	bool checkNextMove(ChessBoardField field);
	void move(ChessBoardField field);

	void highlightPossibleMoves();

	//void draw();
	static void drawKing(Colors::RGB color);


	King();
	~King();
};

