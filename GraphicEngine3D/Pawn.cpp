#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}

Pawn::Pawn(CHESS_ROW r, CHESS_COLUMN col, Colors::RGB color, ChessBoard* chessBoard) {
	init(r, col, color, chessBoard);
}

bool Pawn::checkNextMove(ChessBoardField field) {

	return true;
}
void Pawn::move(ChessBoardField field) {

}

void Pawn::highlightPossibleMoves() {

}

void Pawn::draw() {
	chessBoard->getField(column, row)->translateToFieldCenter(Point3D(0, 0, 0));
	glColor3fv(color.toVector());
	glScalef(0.25f, 0.25f, 0.25f);
	glutSolidTorus(0.2f, 1.0f, 100, 200);
	int howMany = 7;
	float delta = 0.1;
	drawChessPhillar(howMany, delta);
	glTranslatef(0, 0, -delta);
	glutSolidSphere(0.7, 100, 100);
}