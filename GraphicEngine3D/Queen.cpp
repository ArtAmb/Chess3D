#include "Engine3D.h"
#include "Queen.h"
#include "ChessBoard.h"

Queen::Queen()
{
}

Queen::~Queen()
{
}

Queen::Queen(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor) {
	init(r, col, listId, chessBoard, chessColor);
}

bool Queen::checkNextMove(ChessBoardField field) {

	return true;
}
void Queen::move(ChessBoardField field) {

}

void Queen::highlightPossibleMoves() {

}

void Queen::drawQueen(Colors::RGB color) {
	Engine3DLoader::getEngine()->glColor3c(color);

	glScalef(0.25f, 0.25f, 0.25f);
	glutSolidTorus(0.2f, 1.0f, 100, 200);
	ChessPiece::drawRookPhillar(0.5, 14, -0.3);
	glTranslatef(0,0,-0.6);
	glutSolidSphere(0.35, 100, 100);
}
