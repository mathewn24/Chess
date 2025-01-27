#include "game.h"
#include "board.h"
#include "knight.h"

Knight::Knight(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(KNIGHT));
    setScore(KNIGHT_POINTS);
}

bool Knight::isMoveValid(int y, int x) {
    Board* board = getBoard();

    return false;
}