//#include "ChessPiece.h"
#include "ChessBoard.h"


ChessPiece::ChessPiece()
{
}

ChessPiece::ChessPiece(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor) {
	init(r, col, listId, chessBoard, chessColor);
}

std::vector<SimpleChessField> ChessPiece::getPossibleMovesIncludingKing()
{
	if (!isBeingProcessed()) {
		resetPossibleMoves();
		fillPossibleMoves();
	}
	return possibleMoves;
}

std::vector<SimpleChessField> ChessPiece::getPossibleMoves() {
	resetPossibleMoves();
	tryToFillPossibleMoves();

	return possibleMoves;
}

bool ChessPiece::checkNextMove(ChessBoardField field)
{
	tryToFillPossibleMoves();
	SimpleChessField simpleField = field.toSimpleField();
	for (int i = 0; i < possibleMoves.size(); ++i) {
		if (possibleMoves[i] == simpleField)
			return true;
	}
	return false;
}

bool ChessPiece::tryToMove(ChessBoardField * field)
{
	if (checkNextMove(*field)) {
		move(field);
		return true;
	}
	return false;
}

SimpleChessField ChessPiece::getSimpleField()
{
	if (isBeingProcessed())
		return getNewField();

	return SimpleChessField(row, column);
}

void ChessPiece::move(ChessBoardField* field)
{
	if (field->getPiece() != NULL) {
		field->getPiece()->die();
	}
	chessBoard->getField(column, row)->empty();
	column = field->getColumn();
	row = field->getRow();
	field->setPiece(this);

}

void ChessPiece::highlightPossibleMoves()
{
	tryToFillPossibleMoves();
	for (int i = 0; i < possibleMoves.size(); ++i) {
		highlightField(possibleMoves[i]);
	}
}

void ChessPiece::reset()
{
	resetPossibleMoves();
}

void ChessPiece::draw()
{
	chessBoard->getField(column, row)->translateToFieldCenter(Point3D(0, 0, 0));
	glRotated(-90, 0, 0, 1);
	glCallList(listId);
}

void ChessPiece::die()
{
	alive = false;
	reset();
	chessBoard->getField(column, row)->empty();
}

void ChessPiece::init(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor) {
	this->row = r;
	this->column = col;
	this->listId = listId;
	this->chessBoard = chessBoard;
	this->chessColor = chessColor;
	this->chessBoard->getField(col, r)->setPiece(this);
}

ChessPiece::~ChessPiece()
{
}

void ChessPiece::fillPossibleMovesFieldSeries(int deltaRow, int deltaColumn) {
	for (int i = 1; ; i++) {
		if (chessBoard->getField(column + i*deltaColumn, row + i*deltaRow) && chessBoard->getField(column + i*deltaColumn, row + i*deltaRow)->isPossibleToMoveHere(chessColor)) {
			addToPossibleMoves(chessBoard->getField(column + i*deltaColumn, row + i*deltaRow));
			if (chessBoard->getField(column + i*deltaColumn, row + i*deltaRow)->getPiece() != NULL && !chessBoard->getField(column + i*deltaColumn, row + i*deltaRow)->checkPieceColor(chessColor))
				break;
		}
		else break;
	}
}

void ChessPiece::fillPossibleMovesForRook() {
	fillPossibleMovesFieldSeries(1, 0);
	fillPossibleMovesFieldSeries(-1, 0);
	fillPossibleMovesFieldSeries(0, 1);
	fillPossibleMovesFieldSeries(0, -1);
}

void ChessPiece::fillPossibleMovesForBishop() {
	fillPossibleMovesFieldSeries(1, 1);
	fillPossibleMovesFieldSeries(-1, -1);
	fillPossibleMovesFieldSeries(-1, 1);
	fillPossibleMovesFieldSeries(1, -1);
}

void ChessPiece::addToPossibleMoves(ChessBoardField* field)
{
	if (field == NULL)
		return;
	possibleMoves.push_back(field->toSimpleField());
}

void ChessPiece::highlightField(SimpleChessField field)
{
	ChessBoardField* chessBoardField = chessBoard->getField(field);
	if (chessBoardField->getPiece() != NULL)
		chessBoardField->highlight(Colors::RED);
	else
		chessBoardField->highlight();
}

void ChessPiece::resetPossibleMoves()
{
	possibleMoves.clear();
}

void ChessPiece::tryToFillPossibleMoves()
{
	resetPossibleMoves();
	if (!isAlive())
		return;
	fillPossibleMoves();
	for (int i = 0; i < possibleMoves.size(); ) {
		ChessBoardField* field = chessBoard->getField(possibleMoves[i]);
		ChessBoardField* myField = chessBoard->getField(column, row);
		ChessPiece* tmpPiece = field->getPiece();

		startProcessing();
		setAlive(false);
		myField->setPiece(NULL);
		if (tmpPiece != NULL)
			tmpPiece->setAlive(false);
		field->setPiece(this);
		setNewField(field->getRow(), field->getColumn());
		if (chessBoard->checkIfKingIsInCheck(getColor())) {
			possibleMoves.erase(possibleMoves.begin() + i);
			stopProcesing(field, tmpPiece);
			continue;
		}
		stopProcesing(field, tmpPiece);
		++i;
	}
}

void ChessPiece::stopProcesing(ChessBoardField* field, ChessPiece* tmpPiece)
{
	field->setPiece(tmpPiece);
	if (tmpPiece != NULL)
		tmpPiece->setAlive(true);
	setAlive(true);
	ChessBoardField* myField = chessBoard->getField(column, row);
	myField->setPiece(this);
	stopProcessing();
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
		glTranslatef(0.0, 0, translationDelta);
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

void ChessPiece::drawKnightPhillar(float radius, int howMany, float translationDelta)
{
	int half = howMany / 2;
	for (int i = 0; i < half; ++i)
	{
		glTranslatef(0.05, 0, translationDelta);
		glutSolidTorus(radius, radius, 100, 200);
		radius -= 0.05;
	}


}
