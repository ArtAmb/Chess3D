#pragma once
#include "ChessPiece.h";

class Queen : public ChessPiece
{
public:
	Queen(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	bool checkNextMove(ChessBoardField field);
	void move(ChessBoardField field);

	void highlightPossibleMoves();

	//void draw();
	static void drawQueen(Colors::RGB color);


	Queen();
	~Queen();
};

