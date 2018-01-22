#pragma once
#include "ChessPiece.h"
#include "Rectangle3D.h"
#include <iostream>
#include "ChessEnums.h"
#include "GlutHeader.h"
#include "Engine3D.h"
#include "FieldSelector.h"
#include "SimpleChessField.h"
#include "Pawn.h"
#include "King.h"
class ChessBoardField {
private:
	CHESS_ROW x;
	CHESS_COLUMN y;
	ChessPiece* piece = NULL;
	Rectangle3D boardCube;
	bool highlighted = false;
	Colors::RGB highlightColor = Colors::GREEN;
public:
	~ChessBoardField() {

	}
	Rectangle3D getCube() { return boardCube; }
	ChessBoardField() {}

	ChessBoardField(CHESS_ROW x, CHESS_COLUMN y, Rectangle3D boardCube) {
		this->x = x;
		this->y = y;
		this->boardCube = boardCube;
	}

	SimpleChessField toSimpleField() { return SimpleChessField(x, y); }
	bool isPossibleToMoveHere(PLAYER_COLOR color);
	bool checkPieceColor(PLAYER_COLOR chessColor);

	void highlight() {
		highlightColor = Colors::GREEN;
		highlighted = true;
	}

	void highlight(Colors::RGB color) {
		highlightColor = color;
		highlighted = true;
	}

	void stopHighliting() {
		highlighted = false;
	}

	bool isHighlighted() {
		return highlighted;
	}

	CHESS_COLUMN getColumn() {
		return y;
	}

	CHESS_ROW getRow() {
		return x;
	}

	bool isEmpty() {
		return piece == NULL;
	}

	void empty() {
		piece = NULL;
	}

	void setPiece(ChessPiece* piece) { this->piece = piece; }
    ChessPiece* getPiece(){ return piece; }

	void translateToFieldCenter(Point3D point) {
		boardCube.translateToTopCenterOfTopField(point);
	}

	void draw(Colors::RGB color);
};

class ChessBoard {
	std::vector<Pawn*> enPassantPawns;
	PLAYER_COLOR currPlayer = WHITE;
	const static int BOARD_SIZE = 8;
	ChessBoardField board[BOARD_SIZE][BOARD_SIZE];
	ChessPiece* pieces[32];
	Point3D startPoint;
	float cubeL, cubeW, cubeH;
	float boardL, boardW, boardH;
	void initBoard();
	void disableEnPassantPawns();
	King* kings[2];
	void checkKing(King* king);
	King* checkedKing = NULL;
	CHESS_GAME_STATE checkIfGameEnd();
	void endGame(CHESS_GAME_STATE gameState);
	CHESS_GAME_STATE state = CONTINIUE;

public:
    CHESS_GAME_STATE getGameState();
    PLAYER_COLOR getCurrPlayer();
	void setKing(King* king);

	void setPieces();
	void addEnPassantPawns(Pawn* pawn);
	void tryToKillEnPassantPawn(SimpleChessField field);
	ChessBoard();
	ChessBoard(Point3D, float cubeL, float cubeW, float cubeH);
	~ChessBoard();

	King* getCheckedKing() { return checkedKing; }
	bool checkIfKingIsInCheck(PLAYER_COLOR color);
	Point3D getStartPoint() { return startPoint; }
	void updateCurrentPlayer(bool isChangeNeeded);

	ChessBoardField* getField(CHESS_COLUMN c, CHESS_ROW r);
	ChessBoardField* getField(int column, int row);
	ChessBoardField* getField(SimpleChessField field);

	void setCubeSizes(float l, float w, float h);
	void setBoardSizes(float l, float w, float h);
	void unlightAllFields();
	void highlightFields(FieldSelector fieldSelector);
	void selectField(FieldSelector* fieldSelector);

	void draw();
};

