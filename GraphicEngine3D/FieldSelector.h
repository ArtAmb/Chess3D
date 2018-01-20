#pragma once
#include <iostream>
#include "ChessEnums.h"
#include "ChessPiece.h"
class FieldSelector {
	CHESS_ROW row;
	CHESS_COLUMN column;
	bool isSelected;
	ChessPiece* savedPiece = NULL;
public:
	FieldSelector() {};
	FieldSelector(CHESS_ROW row, CHESS_COLUMN column) : row(row), column(column) {};
	void move(int x, int y);
	CHESS_ROW getRow() { return row; }
	CHESS_COLUMN getColumn() { return column; };
	void select() { isSelected = true; }
	void select(ChessPiece* piece) { savedPiece = piece; }
    void unselect(){ isSelected = false; savedPiece = NULL; }
	void absoluteMove(CHESS_ROW x, CHESS_COLUMN y);
	ChessPiece* getSavedPiece() { return savedPiece; }
};

