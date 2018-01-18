#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece {

public:
    Rook(CHESS_ROW, CHESS_COLUMN, int, ChessBoard* chessBoard);

    bool checkNextMove(ChessBoardField field);
    void move(ChessBoardField field);

    void highlightPossibleMoves();
    virtual ~Rook();
    static void drawRook(Colors::RGB color);
protected:

};


