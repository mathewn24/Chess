#include "game.h"
#include "board.h"
#include "bishop.h"

Bishop::Bishop(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(BISHOP));
    setScore(BISHOP_POINTS);
}

bool Bishop::isMoveValid(int y, int x) {
    Board* board = getBoard();

    return false;
}