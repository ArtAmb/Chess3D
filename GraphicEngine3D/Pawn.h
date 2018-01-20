#pragma once
#include "ChessPiece.h";

class Pawn : public ChessPiece
{
	bool firstMoveAvailable = true;
	bool enPasantAvailable = false;
	void fillPossibleMovesForPawn(int deltaRow);
	void fillPossibleMovesForEnPasant(int deltaColumn, int deltaRow);
	CHESS_COLUMN oldColumn;
	CHESS_ROW oldRow;
public:
	Pawn(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	void move(ChessBoardField* field);
	void fillPossibleMoves();
	static void drawPawn(Colors::RGB color);
	bool isFirstMoveAvailable() { return firstMoveAvailable; }
	bool isEnPasantAvailable() { return enPasantAvailable; }
	void disableEnPasant() { enPasantAvailable = false; }
	void enableEnPasant() { enPasantAvailable = true; }
	SimpleChessField getOldField() { return SimpleChessField(oldRow, oldColumn); }
	Pawn();
	~Pawn();
};

