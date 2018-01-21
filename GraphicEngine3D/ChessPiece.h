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
	void highlightField(SimpleChessField field);
	void resetPossibleMoves();
	void tryToFillPossibleMoves();
	virtual void fillPossibleMoves() = 0;
	bool beingProcessed = false;
	void stopProcesing(ChessBoardField* field, ChessPiece* tmpPiece);
	ChessBoard* chessBoard;
	CHESS_ROW row;
	CHESS_COLUMN column;
	CHESS_ROW newRow;
	CHESS_COLUMN newColumn;
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
	bool isBeingProcessed() { return beingProcessed; }
	void startProcessing() { beingProcessed = true; }
	void stopProcessing() { beingProcessed = false; }
	SimpleChessField getNewField() { return SimpleChessField(newRow, newColumn); }
	void setNewField(CHESS_ROW r, CHESS_COLUMN col) { newRow = r; newColumn = col; }
public:
	ChessPiece();
	ChessPiece(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor);

	std::vector<SimpleChessField> getPossibleMovesIncludingKing();
	std::vector<SimpleChessField> getPossibleMoves();
	bool checkNextMove(ChessBoardField field);
	bool tryToMove(ChessBoardField* field);
	SimpleChessField getSimpleField();
	void highlightPossibleMoves();
	void reset();
	virtual void draw();

	void die();
	void setAlive(bool isAlive) { alive = isAlive; }
	PLAYER_COLOR getColor() {
		return chessColor;
	}

	bool isAlive() {
		return alive;
	}

	virtual ~ChessPiece();
};

