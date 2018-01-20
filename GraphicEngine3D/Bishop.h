#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
    Bishop(CHESS_ROW, CHESS_COLUMN, int, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	void fillPossibleMoves();
    virtual ~Bishop();
    static void drawBishop(Colors::RGB color);
protected:

private:
};

