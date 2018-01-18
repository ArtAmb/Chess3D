#include "Engine3D.h"
#include "Knight.h"
#include "ChessBoard.h"

Knight::~Knight()
{
}

Knight::Knight(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard) {
	init(r, col, listId, chessBoard);
}

bool Knight::checkNextMove(ChessBoardField field) {

	return true;
}
void Knight::move(ChessBoardField field) {

}

void Knight::highlightPossibleMoves() {

}

void Knight::drawKnight(Colors::RGB color) {
	Engine3DLoader::getEngine()->glColor3c(color);
	glScalef(0.25f, 0.25f, 0.25f);
	glutSolidTorus(0.2f, 1.0f, 100, 200);
	int howMany = 7;
	float delta = 0.1;
	drawChessPhillar(howMany, delta);
	glTranslatef(0, 0, -delta);
	glutSolidSphere(0.7, 100, 100);
}
