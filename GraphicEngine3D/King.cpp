#include "Engine3D.h"
#include "King.h"
#include "ChessBoard.h"

King::King()
{
}


King::~King()
{
}

void King::fillOneFieldAroundPiece(int deltaRow, int deltaColumn) {
	if (chessBoard->getField(column + deltaColumn, row + deltaRow) && chessBoard->getField(column + deltaColumn, row + deltaRow)->isPossibleToMoveHere(chessColor))
		addToPossibleMoves(chessBoard->getField(column + deltaColumn, row + deltaRow));
}

King::King(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor) {
	init(r, col, listId, chessBoard, chessColor);
}

void drawCross(){
    float size = 0.35;
    glutSolidCube(size);
    glTranslatef(0.0f, 0.0f, -size);
    glutSolidCube(size);
    glTranslatef(0.0f, 0.0f, -size);
    glutSolidCube(size);
    glTranslatef(0.0f, 0.0f, -size);
    glutSolidCube(size);

    glTranslatef(size, 0.0f, size);
    glutSolidCube(size);
    glTranslatef(-2*size, 0.0f, 0.0f);
    glutSolidCube(size);
}

void King::drawKing(Colors::RGB color) {
	Engine3DLoader::getEngine()->glColor3c(color);
	glScalef(0.25f, 0.25f, 0.25f);
	glutSolidTorus(0.2f, 1.0f, 100, 200);
	ChessPiece::drawRookPhillar(0.5, 14, -0.3);
	glTranslatef(0,0,-0.3);
	drawCross();
}

void King::fillPossibleMoves()
{
	fillOneFieldAroundPiece(1, 1);
	fillOneFieldAroundPiece(-1, -1);
	fillOneFieldAroundPiece(-1, 1);
	fillOneFieldAroundPiece(1, -1);

	fillOneFieldAroundPiece(0, 1);
	fillOneFieldAroundPiece(0, -1);
	fillOneFieldAroundPiece(1, 0);
	fillOneFieldAroundPiece(-1, 0);
}
