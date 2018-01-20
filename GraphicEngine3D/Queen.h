#pragma once
#include "ChessPiece.h";

class Queen : public ChessPiece
{
public:
	Queen(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	void fillPossibleMoves();
	//void draw();
	static void drawQueen(Colors::RGB color);


	Queen();
	~Queen();
};

