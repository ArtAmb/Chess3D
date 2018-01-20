#pragma once
#include "ChessEnums.h"
#include "RGB.h"
#include <vector>
#include "SimpleChessField.h"
class ChessBoard;
class ChessBoardField;

class ChessPiece
{
protected:
	void fillPossibleMovesFieldSeries(int deltaRow, int deltaColumn);
	void fillPossibleMovesForRook();
	void fillPossibleMovesForBishop();
	void addToPossibleMoves(ChessBoardField* field);
	void resetPossibleMoves();
	void tryToFillPossibleMoves();
	virtual void fillPossibleMoves() = 0;

	ChessBoard* chessBoard;
	CHESS_ROW row;
	CHESS_COLUMN column;
	Colors::RGB color;
	PLAYER_COLOR chessColor;
	std::vector<SimpleChessField> possibleMoves;
	int listId;
	bool alive = true;
	static void drawChessPhillar(int howMany, float delta);
	static void drawRookPhillar(float radius, int howMany, float translationDelta);
	static void drawKnightPhillar(float radius, int howMany, float translationDelta);
	void init(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor);
	virtual void move(ChessBoardField* field);
public:
	ChessPiece();
	ChessPiece(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor);


	bool checkNextMove(ChessBoardField field);
	bool tryToMove(ChessBoardField* field);


	void highlightPossibleMoves();
	void reset();
	virtual void draw();

	void die();

	PLAYER_COLOR getColor() {
		return chessColor;
	}

	bool isAlive() {
		return alive;
	}

	virtual ~ChessPiece();
};

