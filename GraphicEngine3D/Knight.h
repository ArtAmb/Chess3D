#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
    public:
    Knight(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	void fillLPatternMoves(int deltaRow, int deltaColumn);
	void fillPossibleMoves();
	static void drawKnight(Colors::RGB color);
	static void drawRotatingKnight(Colors::RGB color, int angle);
    virtual ~Knight();
    protected:

    private:
};

