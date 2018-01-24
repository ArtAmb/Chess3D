#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
}

ChessBoard::~ChessBoard()
{
}

ChessBoard::ChessBoard(Point3D startPoint, float cubeL, float cubeW, float cubeH)
{
    this->startPoint = startPoint;
    setCubeSizes(cubeL, cubeW, cubeH);
}

void ChessBoard::initBoard()
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            Rectangle3D cube(startPoint.move(i * cubeL, j * cubeW, 0), cubeL, cubeW, cubeH);
            board[i][j] = ChessBoardField((CHESS_ROW)i, (CHESS_COLUMN)j, cube);
        }
    }
}

void ChessBoard::disableEnPassantPawns()
{
    if (enPassantPawns.size() == 0)
        return;

    for (int i = 0; i < enPassantPawns.size(); )
    {
        if (!enPassantPawns[i]->isEnPasantAvailable())
        {
            enPassantPawns[i]->enableEnPasant();
        }
        else
        {
            enPassantPawns[i]->disableEnPasant();
            enPassantPawns.erase(enPassantPawns.begin() + i);
            continue;
        }
        ++i;
    }

}

void ChessBoard::checkKing(King * king)
{
}

bool isFieldInVector(SimpleChessField field, std::vector<SimpleChessField> vector)
{
    for (int i = 0; i < vector.size(); ++i)
    {
        if (vector[i] == field)
            return true;
    }
    return false;
}

CHESS_GAME_STATE ChessBoard::checkIfGameEnd()
{
    std::vector<SimpleChessField> whiteMoves;
    std::vector<SimpleChessField> blackMoves;
    for (int i = 0; i < 32; ++i)
    {
        if (pieces[i]->getColor() == WHITE)
        {
            std::vector<SimpleChessField> tmp = pieces[i]->getPossibleMoves();
            whiteMoves.insert(whiteMoves.end(),tmp.begin(), tmp.end());
        }
        else
        {
            std::vector<SimpleChessField> tmp = pieces[i]->getPossibleMoves();
            blackMoves.insert(blackMoves.end(), tmp.begin(), tmp.end());
        }
    }

    bool isWhiteKingChecked = isFieldInVector(kings[WHITE]->getSimpleField(), blackMoves);
    bool isBlackKingChecked = isFieldInVector(kings[BLACK]->getSimpleField(), whiteMoves);

    if (isWhiteKingChecked && whiteMoves.empty())
        return WINNER_BLACK;
    if (isBlackKingChecked && blackMoves.empty())
        return WINNER_WHITE;
    if (!isWhiteKingChecked && whiteMoves.empty())
        return STALEMATE;
    if (!isBlackKingChecked && blackMoves.empty())
        return STALEMATE;

    return CONTINIUE;
}

void ChessBoard::endGame(CHESS_GAME_STATE gameState)
{
    state = gameState;
    switch (gameState)
    {
    case WINNER_BLACK:

        std::cout << "CHECKMATE!!! WINNER: BLACK"<< std::endl;
        break;

    case WINNER_WHITE:

        std::cout << "CHECKMATE!!! WINNER: WHITE" << std::endl;
        break;

    case STALEMATE:

        std::cout << "STALEMATE!" << std::endl;
        break;

    default:

        break;
    }
}
CHESS_GAME_STATE ChessBoard::getGameState()
{
    return state;
}
PLAYER_COLOR ChessBoard::getCurrPlayer()
{
    return currPlayer;
}

void ChessBoard::tryToKillEnPassantPawn(SimpleChessField field)
{
    if (enPassantPawns.size() == 0)
        return;

    for (int i = 0; i < enPassantPawns.size(); ++i)
    {
        if (enPassantPawns[i]->isEnPasantAvailable() && enPassantPawns[i]->getOldField() == field)
        {
            enPassantPawns[i]->die();
        }
    }
}

void ChessBoard::setKing(King * king)
{
    kings[king->getColor()] = king;
}

void ChessBoard::setPieces()
{
    int k = -1;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            if (getField(i, j)->getPiece() != NULL)
                pieces[++k] = getField(i, j)->getPiece();
        }
    }
}

void ChessBoard::addEnPassantPawns(Pawn * pawn)
{
    enPassantPawns.push_back(pawn);
}

void ChessBoard::setCubeSizes(float l, float w, float h)
{
    cubeL = l;
    cubeW = w;
    cubeH = h;

    boardH = cubeH * BOARD_SIZE;
    boardW = cubeW * BOARD_SIZE;
    boardL = cubeL;
    initBoard();
}

void ChessBoard::setBoardSizes(float l, float w, float h)
{
    boardL = l;
    boardW = w;
    boardH = h;

    cubeH = boardH / BOARD_SIZE;
    cubeW = boardW / BOARD_SIZE;
    cubeL = boardL;
    initBoard();
}

bool ChessBoardField::isPossibleToMoveHere(PLAYER_COLOR color)
{
    return isEmpty() || !checkPieceColor(color);
}

bool ChessBoardField::checkPieceColor(PLAYER_COLOR chessColor)
{
    if (isEmpty())
        return false;
    return getPiece()->getColor() == chessColor;
}

void ChessBoardField::draw(Colors::RGB color)
{
    if (highlighted)
        boardCube.draw(color, highlightColor);
    else
        boardCube.draw(color);
}

void ChessBoard::draw()
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            board[i][j].draw(i % 2 == j % 2 ? Colors::DARKBROWN : Colors::LIGHTBROWN);
        }
    }
}

ChessBoardField* ChessBoard::getField(CHESS_COLUMN c, CHESS_ROW r)
{
    return &board[r][c];
}

ChessBoardField* ChessBoard::getField(int column, int row)
{
    if (column < 0 || column >= BOARD_SIZE || row < 0 || row >= BOARD_SIZE)
        return NULL;
    return &board[row][column];
}

ChessBoardField * ChessBoard::getField(SimpleChessField field)
{
    return getField(field.getColumn(), field.getRow());
}

void ChessBoard::unlightAllFields()
{
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {
            board[i][j].stopHighliting();
        }
    }
}

void ChessBoard::highlightFields(FieldSelector fieldSelector)
{
    ChessBoardField* field = &board[fieldSelector.getRow()][fieldSelector.getColumn()];

    if (fieldSelector.getSavedPiece() != NULL)
    {
        fieldSelector.getSavedPiece()->highlightPossibleMoves();
    }
    field->highlight(Colors::YELLOW);
}
bool ChessBoard::checkIfKingIsInCheck(PLAYER_COLOR color)
{
    for (int i = 0; i < 32; ++i)
    {
        if (!pieces[i]->isAlive())
            continue;
        std::vector<SimpleChessField> posibleMoves = pieces[i]->getPossibleMovesIncludingKing();
        for (int j = 0; j < posibleMoves.size(); ++j)
        {
            if (posibleMoves[j] == kings[color]->getSimpleField())
            {
                checkKing(kings[color]);
                return true;
            }
        }

    }

    return false;
}

void ChessBoard::updateCurrentPlayer(bool isChangeNeeded)
{
    if (isChangeNeeded)
    {
        currPlayer = (currPlayer == WHITE ? BLACK : WHITE);
        disableEnPassantPawns();
        endGame(checkIfGameEnd());
    }

}
void ChessBoard::selectField(FieldSelector* fieldSelector)
{
    ChessBoardField* field = getField(fieldSelector->getColumn(), fieldSelector->getRow());

    if (fieldSelector->isSelected())
    {
        updateCurrentPlayer(fieldSelector->getSavedPiece()->tryToMove(field));
        fieldSelector->unselect();
        return;
    }

    if (!fieldSelector->isSelected())
    {
        if (field->getPiece() != NULL && field->getPiece()->getColor() == currPlayer)
        {
            fieldSelector->select(field->getPiece());
            return;
        }
        if (field->getPiece() == NULL)
        {
            return;
        }
    }



}
