#include "Engine3D.h"
#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn()
{
}


Pawn::~Pawn()
{
}

Pawn::Pawn(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor) {
	init(r, col, listId, chessBoard, chessColor);
}

bool Pawn::checkNextMove(ChessBoardField field) {

	return true;
}
void Pawn::move(ChessBoardField field) {
	if (firstMoveAvailable) {
		firstMoveAvailable = false;
	}	
	if (enPasantAvailable) {
		enPasantAvailable = false;
	}
	if ((row - field.getRow()) % 2 == 0) {
		enPasantAvailable = true;
	}
}

void Pawn::highlightPossibleMoves() {
	chessBoard->getField(column, row)->highlight();

	if (chessColor == BLACK) {
		chessBoard->getField(column, row - 1)->highlight();
		if(firstMoveAvailable)
			chessBoard->getField(column, row - 1)->highlight();

		if (chessBoard->getField(column - 1, row - 1)->getPiece() != NULL)
			chessBoard->getField(column - 1, row - 1)->highlight();
		if (chessBoard->getField(column + 1, row - 1)->getPiece() != NULL)
			chessBoard->getField(column + 1, row - 1)->highlight();

		if (chessBoard->getField(column + 1, row)->getPiece() != NULL) {
			if (dynamic_cast<Pawn*>(chessBoard->getField(column + 1, row)->getPiece()) != NULL)
				if (dynamic_cast<Pawn*>(chessBoard->getField(column + 1, row)->getPiece())->isEnPasantAvailable())
					chessBoard->getField(column + 1, row - 1)->highlight();
		}

		if (chessBoard->getField(column - 1, row)->getPiece() != NULL) {
			if (dynamic_cast<Pawn*>(chessBoard->getField(column - 1, row)->getPiece()) != NULL)
				if (dynamic_cast<Pawn*>(chessBoard->getField(column - 1, row)->getPiece())->isEnPasantAvailable())
					chessBoard->getField(column - 1, row - 1)->highlight();
		}

		return;
	}
	if (chessColor == WHITE) {
		chessBoard->getField(column, row + 1)->highlight();
		if (firstMoveAvailable)
			chessBoard->getField(column, row + 1)->highlight();

		if (chessBoard->getField(column - 1, row + 1)->getPiece() != NULL)
			chessBoard->getField(column - 1, row + 1)->highlight();
		if (chessBoard->getField(column + 1, row + 1)->getPiece() != NULL)
			chessBoard->getField(column + 1, row + 1)->highlight();

		if (chessBoard->getField(column + 1, row)->getPiece() != NULL ) {
			if (dynamic_cast<Pawn*>(chessBoard->getField(column + 1, row)->getPiece()) != NULL)
				if (dynamic_cast<Pawn*>(chessBoard->getField(column + 1, row)->getPiece())->isEnPasantAvailable())
					chessBoard->getField(column + 1, row + 1)->highlight();
		}

		if (chessBoard->getField(column - 1, row)->getPiece() != NULL) {
			if (dynamic_cast<Pawn*>(chessBoard->getField(column - 1, row)->getPiece()) != NULL)
				if (dynamic_cast<Pawn*>(chessBoard->getField(column - 1, row)->getPiece())->isEnPasantAvailable())
					chessBoard->getField(column - 1, row + 1)->highlight();
		}

		return;
	}
}

void Pawn::drawPawn(Colors::RGB color) {
	Engine3DLoader::getEngine()->glColor3c(color);

	glScalef(0.25f, 0.25f, 0.25f);
	glutSolidTorus(0.2f, 1.0f, 100, 200);
	int howMany = 7;
	float delta = 0.1;
	drawChessPhillar(howMany, delta);
	glTranslatef(0, 0, -delta);
	glutSolidSphere(0.7, 100, 100);
}
