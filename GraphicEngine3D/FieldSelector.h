#pragma once
#include "ChessEnums.h"
class FieldSelector {
	CHESS_ROW row;
	CHESS_COLUMN column;
	bool isSelected;
public:
	FieldSelector() {};
	FieldSelector(CHESS_ROW row, CHESS_COLUMN column) : row(row), column(column) {};
	void move(int x, int y);
	CHESS_ROW getRow() { return row; }
	CHESS_COLUMN getColumn() { return column; };
    void select(){ isSelected = true; }
    void unselect(){ isSelected = false; }
	void absoluteMove(CHESS_ROW x, CHESS_COLUMN y);
};

