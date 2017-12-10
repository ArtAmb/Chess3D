#pragma once
#include "ChessBoard.h"

class ChessPiece
{
	CHESS_ROW row;
	CHESS_COLUMN column;

public:
	ChessPiece();

	virtual bool checkNextMove(ChessBoardField field) = 0;
	virtual void move(ChessBoardField field) = 0;

	virtual ~ChessPiece();
};

