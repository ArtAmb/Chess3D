#pragma once

enum  CHESS_COLUMN { C_A = 0, C_B, C_C, C_D, C_E, C_F, C_G, C_H };
enum  CHESS_ROW { R_1 = 0, R_2, R_3, R_4, R_5, R_6, R_7, R_8 };


class ChessBoardField {
private:
	CHESS_ROW x;
	CHESS_COLUMN y;

public:
	ChessBoardField(CHESS_ROW x, CHESS_COLUMN y) {
		this->x = x;
		this->y = y;
	}

	int getRow() {
		return x;
	}


	int getColumn() {
		return y;
	}

};


class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();
};

