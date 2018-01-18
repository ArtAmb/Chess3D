#include "Rook.h"
#include "ChessBoard.h"



Rook::Rook(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard)
{
    init(r, col, listId, chessBoard);
}

bool Rook::checkNextMove(ChessBoardField field)
{
    return false;
}
void Rook::move(ChessBoardField field)
{
}

void Rook::highlightPossibleMoves()
{
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
