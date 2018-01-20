#pragma once
#include "ChessPiece.h";

class Pawn : public ChessPiece
{
	bool firstMoveAvailable = true;
	bool enPasantAvailable = false;
public:
	Pawn(CHESS_ROW , CHESS_COLUMN, int, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	bool checkNextMove(ChessBoardField field);
	void move(ChessBoardField field);

	void highlightPossibleMoves();

	//void draw();
	static void drawPawn(Colors::RGB color);
	bool isFirstMoveAvailable() { return firstMoveAvailable; }
	bool isEnPasantAvailable() { return enPasantAvailable; }

	Pawn();
	~Pawn();
};

