#pragma once
#include "ChessPiece.h";

class King : public ChessPiece
{
	void fillOneFieldAroundPiece(int deltaRow, int deltaColumn);
public:
	King(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	static void drawKing(Colors::RGB color);
	void fillPossibleMoves();
	
	King();
	~King();
};

