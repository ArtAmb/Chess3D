#include "Engine3D.h"
#include "Knight.h"
#include "ChessBoard.h"

Knight::~Knight()
{
}

Knight::Knight(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard, PLAYER_COLOR chessColor) {
	init(r, col, listId, chessBoard, chessColor);
}

bool Knight::checkNextMove(ChessBoardField field) {

	return true;
}
void Knight::move(ChessBoardField field) {

}

void Knight::highlightPossibleMoves() {

}

void Knight::drawKnight(Colors::RGB color) {
    Engine3DLoader::getEngine()->glColor3c(color);
    glScalef(0.25f, 0.25f, 0.25f);
	glutSolidTorus(0.4f, 1.2f, 100, 200);
    ChessPiece::drawKnightPhillar(0.6f, 15, -0.3);
    glTranslatef(0.5,0,-0.5);
    glRotated(90, 0, 1, 0 );
	ChessPiece::drawKnightPhillar(0.4f, 10, -0.3);

    glRotated( 90, 0,1,0 );
    glTranslatef(-1.2,0.2,0.4);
    glutSolidCone(0.3, 0.8, 10,10 );

    glTranslatef(0,-0.4,0);
    glutSolidCone(0.3, 0.8, 10,10 );

    glTranslatef(1.3,0.2,-0.35);
    glutSolidSphere(0.4,100,200);

    glTranslatef(-1.45,0,-0.1);
    glutSolidSphere(0.7,100,200);



}
void Knight::drawRotatingKnight(Colors::RGB color, int angle) {
	 Engine3DLoader::getEngine()->glColor3c(color);
     glRotated( angle, 0,0,1 );
     Knight::drawKnight(color);
}
