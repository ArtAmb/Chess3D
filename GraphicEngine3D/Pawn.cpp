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

void Pawn::move(ChessBoardField* field) {
	if (firstMoveAvailable) {
		firstMoveAvailable = false;
	}	
	if ((row - field->getRow()) % 2 == 0) {
		int deltaRow = (chessColor == WHITE ? 1 : -1);
		oldColumn = column;
		oldRow = CHESS_ROW(row + deltaRow);
		chessBoard->addEnPassantPawns(this);
	}
	ChessPiece::move(field);
	chessBoard->tryToKillEnPassantPawn(field->toSimpleField());
}

void Pawn::fillPossibleMovesForPawn(int deltaRow)
{
	if(chessBoard->getField(column, row + deltaRow) && chessBoard->getField(column, row + deltaRow)->isEmpty())
		addToPossibleMoves(chessBoard->getField(column, row + deltaRow));

	if (firstMoveAvailable && chessBoard->getField(column, row + deltaRow)->isEmpty() && chessBoard->getField(column, row + 2*deltaRow)->isEmpty())
		addToPossibleMoves(chessBoard->getField(column, row + 2*deltaRow));

	if (chessBoard->getField(column - 1, row + deltaRow) && !chessBoard->getField(column - 1, row + deltaRow)->isEmpty() && !chessBoard->getField(column - 1, row + deltaRow)->checkPieceColor(chessColor))
		addToPossibleMoves(chessBoard->getField(column - 1, row + deltaRow));
	if (chessBoard->getField(column + 1, row + deltaRow) && !chessBoard->getField(column + 1, row + deltaRow)->isEmpty() && !chessBoard->getField(column + 1, row + deltaRow)->checkPieceColor(chessColor))
		addToPossibleMoves(chessBoard->getField(column + 1, row + deltaRow));

	fillPossibleMovesForEnPasant(1, deltaRow);
	fillPossibleMovesForEnPasant(-1, deltaRow);
}

void Pawn::fillPossibleMovesForEnPasant(int deltaColumn, int deltaRow) {
	if (chessBoard->getField(column + deltaColumn, row + deltaRow) && !chessBoard->getField(column + deltaColumn, row)->isEmpty()) {
		if (dynamic_cast<Pawn*>(chessBoard->getField(column + deltaColumn, row)->getPiece()) != NULL)
			if (dynamic_cast<Pawn*>(chessBoard->getField(column + deltaColumn, row)->getPiece())->isEnPasantAvailable())
				addToPossibleMoves(chessBoard->getField(column + deltaColumn, row + deltaRow));
	}
}

void Pawn::fillPossibleMoves()
{
	if (chessColor == BLACK) {
		fillPossibleMovesForPawn(-1);
	}
	if (chessColor == WHITE) {
		fillPossibleMovesForPawn(1);
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
