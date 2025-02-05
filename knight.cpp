#include "game.h"
#include "board.h"
#include "knight.h"

const int DY[] = {2, 2, 1, 1, -1, -1, -2, -2};
const int DX[] = {1, -1, 2, -2, 2, -2, 1, -1};

Knight::Knight(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(KNIGHT));
    setScore(KNIGHT_POINTS);
}

bool Knight::isMoveValid(int y, int x) {
    Board* board = getBoard();
    for (int d = 0; d < 8; d++) {
        if (y == getY() + DY[d] && x == getX() + DX[d]) {
            Piece* targ = board->get(getY() + DY[d], getX() + DX[d]);
            if (targ == EMPTY || targ->getColor() != this->getColor()) {
                return true;
            }
        }
    }
    
    return false;
}