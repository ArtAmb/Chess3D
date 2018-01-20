#include "Rook.h"
#include "ChessBoard.h"



Rook::Rook(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor)
{
    init(r, col, listId, chessBoard, chessColor);
}

void Rook::fillPossibleMoves()
{
	fillPossibleMovesForRook();
}

Rook::~Rook()
{
}

void Rook::drawRook(Colors::RGB color)
{
    Engine3DLoader::getEngine()->glColor3c(color);
    glScalef(0.25f, 0.25f, 0.25f);
    glutSolidTorus(0.4f, 1.2f, 100, 200);
    ChessPiece::drawRookPhillar(0.6f, 10, -0.3);
}
