#pragma once
#include "ChessPiece.h"
class Rook : public ChessPiece {

public:
    Rook(CHESS_ROW, CHESS_COLUMN, int, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	void fillPossibleMoves();
    virtual ~Rook();
    static void drawRook(Colors::RGB color);
protected:

};


