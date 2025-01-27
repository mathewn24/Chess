#include "game.h"
#include "board.h"
#include "queen.h"

Queen::Queen(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(QUEEN));
    setScore(QUEEN_POINTS);
}

bool Queen::isMoveValid(int y, int x) {
    Board* board = getBoard();

    return false;
}