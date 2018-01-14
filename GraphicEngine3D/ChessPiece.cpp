#include "ChessPiece.h"
#include "glut.h"
//#include "ChessBoard.h"

ChessPiece::ChessPiece()
{
}

ChessPiece::ChessPiece(CHESS_ROW r, CHESS_COLUMN col, Colors::RGB c, ChessBoard* chessBoard) {
	init(r, col, c, chessBoard);
}

void ChessPiece::init(CHESS_ROW r, CHESS_COLUMN col, Colors::RGB c, ChessBoard* chessBoard) {
	this->row = r;
	this->column = col;
	this->color = c;
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