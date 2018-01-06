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

void ChessBoard::draw() {
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			board[i][j].getCube().draw(i % 2 == j % 2 ? Colors::BLACK: Colors::GRAY);
		}
	}
}