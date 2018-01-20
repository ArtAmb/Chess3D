#include "ChessBoard.h"

ChessBoard::ChessBoard() {
}

ChessBoard::~ChessBoard() {
}

ChessBoard::ChessBoard(Point3D startPoint, float cubeL, float cubeW, float cubeH) {
	this->startPoint = startPoint;
	setCubeSizes(cubeL, cubeW, cubeH);
}

void ChessBoard::initBoard() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			Rectangle3D cube(startPoint.move(i * cubeL, j * cubeW, 0), cubeL, cubeW, cubeH);
			board[i][j] = ChessBoardField((CHESS_ROW)i, (CHESS_COLUMN)j, cube);
		}
	}
}

void ChessBoard::disableEnPassantPawns()
{
	if (enPassantPawns.size() == 0)
		return;

	for (int i = 0; i < enPassantPawns.size(); ) {
		if (!enPassantPawns[i]->isEnPasantAvailable()) {
			enPassantPawns[i]->enableEnPasant();
		}
		else {
			enPassantPawns[i]->disableEnPasant();
			enPassantPawns.erase(enPassantPawns.begin() + i);
			continue;
		}
		++i;
	}

}

void ChessBoard::tryToKillEnPassantPawn(SimpleChessField field) {
	if (enPassantPawns.size() == 0)
		return;

	for (int i = 0; i < enPassantPawns.size(); ++i) {
		if (enPassantPawns[i]->isEnPasantAvailable() && enPassantPawns[i]->getOldField() == field) {
			enPassantPawns[i]->die();
		}
	}
}

void ChessBoard::addEnPassantPawns(Pawn * pawn)
{
	enPassantPawns.push_back(pawn);
}

void ChessBoard::setCubeSizes(float l, float w, float h) {
	cubeL = l;
	cubeW = w;
	cubeH = h;

	boardH = cubeH * BOARD_SIZE;
	boardW = cubeW * BOARD_SIZE;
	boardL = cubeL;
	initBoard();
}

void ChessBoard::setBoardSizes(float l, float w, float h) {
	boardL = l;
	boardW = w;
	boardH = h;

	cubeH = boardH / BOARD_SIZE;
	cubeW = boardW / BOARD_SIZE;
	cubeL = boardL;
	initBoard();
}

bool ChessBoardField::isPossibleToMoveHere(PLAYER_COLOR color) {
	return isEmpty() || !checkPieceColor(color);
}

bool ChessBoardField::checkPieceColor(PLAYER_COLOR chessColor) {
	if (isEmpty()) return false;
	return getPiece()->getColor() == chessColor;
}

void ChessBoardField::draw(Colors::RGB color) {
	if (highlighted)
		boardCube.draw(color, highlightColor);
	else
		boardCube.draw(color);
}

void ChessBoard::draw() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			board[i][j].draw(i % 2 == j % 2 ? Colors::BLACK : Colors::GRAY);
		}
	}
}

ChessBoardField* ChessBoard::getField(CHESS_COLUMN c, CHESS_ROW r) {
	return &board[r][c];
}

ChessBoardField* ChessBoard::getField(int column, int row) {
	if (column < 0 || column >= BOARD_SIZE || row < 0 || row >= BOARD_SIZE)
		return NULL;
	return &board[row][column];
}

ChessBoardField * ChessBoard::getField(SimpleChessField field) {
	return getField(field.getColumn(), field.getRow());
}

void ChessBoard::unlightAllFields() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			board[i][j].stopHighliting();
		}
	}
}

void ChessBoard::highlightFields(FieldSelector fieldSelector) {
	ChessBoardField* field = &board[fieldSelector.getRow()][fieldSelector.getColumn()];

	if (fieldSelector.getSavedPiece() != NULL) {
		fieldSelector.getSavedPiece()->highlightPossibleMoves();
	}
	field->highlight(Colors::YELLOW);
}
void ChessBoard::updateCurrentPlayer(bool isChangeNeeded) {
	if (isChangeNeeded) {
		currPlayer = (currPlayer == WHITE ? BLACK : WHITE);
		disableEnPassantPawns();
	}

}
void ChessBoard::selectField(FieldSelector* fieldSelector) {
	ChessBoardField* field = getField(fieldSelector->getColumn(), fieldSelector->getRow());

	if (fieldSelector->isSelected()) {
		updateCurrentPlayer(fieldSelector->getSavedPiece()->tryToMove(field));
		fieldSelector->unselect();
		return;
	}

	if (!fieldSelector->isSelected()) {
		if (field->getPiece() != NULL && field->getPiece()->getColor() == currPlayer) {
			fieldSelector->select(field->getPiece());
			return;
		}
		if (field->getPiece() == NULL) {
			return;
		}
	}



}
