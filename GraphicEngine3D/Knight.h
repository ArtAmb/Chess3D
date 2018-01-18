#pragma once
#include "ChessPiece.h"

class Knight : public ChessPiece
{
    public:
    Knight(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard);

	bool checkNextMove(ChessBoardField field);
	void move(ChessBoardField field);

	void highlightPossibleMoves();

	//void draw();
	static void drawKnight(Colors::RGB color);
    virtual ~Knight();
    protected:

    private:
};

