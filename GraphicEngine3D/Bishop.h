#pragma once
#include "ChessPiece.h"

class Bishop : public ChessPiece
{
public:
    Bishop(CHESS_ROW, CHESS_COLUMN, int, ChessBoard* chessBoard);

    bool checkNextMove(ChessBoardField field);
    void move(ChessBoardField field);

    void highlightPossibleMoves();
    virtual ~Bishop();
    static void drawBishop(Colors::RGB color);
protected:

private:
};

