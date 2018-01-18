//#include "ChessPiece.h"
#include "ChessBoard.h"


ChessPiece::ChessPiece()
{
}

ChessPiece::ChessPiece(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard) {
	init(r, col, listId, chessBoard);
}

void ChessPiece::draw()
{
	chessBoard->getField(column, row)->translateToFieldCenter(Point3D(0, 0, 0));
	glCallList(listId);
}

void ChessPiece::init(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard) {
	this->row = r;
	this->column = col;
	this->listId = listId;
	this->chessBoard = chessBoard;
}

ChessPiece::~ChessPiece()
{
}

void ChessPiece::drawChessPhillar(int howMany, float delta) {
	float radius = delta*howMany;
	float z = 0.1;
	for (int i = 0; i < howMany; ++i) {
		glTranslatef(0, 0, -i*delta);
		glutSolidTorus(radius, radius, 100, 200);
		radius -= delta;
		z += 0.1;
	}
}

void ChessPiece::drawRookPhillar(float radius, int howMany, float translationDelta)
{
    int half = howMany / 2;
    for (int i = 0; i < half; ++i)
    {
        glTranslatef(0, 0, translationDelta);
        glutSolidTorus(radius, radius, 100, 200);
        radius -= 0.05;
    }
    for (int i = 0; i < half; ++i)
    {
        glTranslatef(0, 0, translationDelta);
        glutSolidTorus(radius, radius, 100, 200);
        radius += 0.05;
    }
}
