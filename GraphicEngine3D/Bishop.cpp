#include "Bishop.h"
#include "ChessBoard.h"


Bishop::Bishop(CHESS_ROW r, CHESS_COLUMN col, int listId, ChessBoard* chessBoard)
{
    init(r, col, listId, chessBoard);
}

Bishop::~Bishop()
{
    //dtor
}

bool Bishop::checkNextMove(ChessBoardField field)
{
	return false;
}
void Bishop::move(ChessBoardField field)
{
}

void drawChessBishopPhillar(int howMany, float delta, float transalteDelta){
    float radius = howMany*delta;
    float z = 0.1;
	for (int i = 0; i < howMany; ++i) {
		glTranslatef(0, 0, transalteDelta);
		glutSolidTorus(radius, radius, 100, 200);
		radius -= delta;

    }

}

void Bishop::drawBishop(Colors::RGB color){
    Engine3DLoader::getEngine()->glColor3c(color);
	glScalef(0.25f, 0.25f, 0.25f);
	glutSolidTorus(0.2f, 1.0f, 100, 200);
	int howMany = 7;
	float delta = 0.08;
	float transalteDelta = -0.5;
	drawChessBishopPhillar(howMany, delta, transalteDelta);
	glTranslatef(0, 0, -transalteDelta);
	glutSolidSphere(0.7, 100, 100);
}

void Bishop::highlightPossibleMoves()
{
}
