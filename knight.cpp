#include "game.h"
#include "board.h"
#include "knight.h"

using namespace std;

const int DY[] = {1, -1, 2, -2, 2, -2, 1, -1};
const int DX[] = {2, 2, 1, 1, -1, -1, -2, -2};

Knight::Knight(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(KNIGHT));
    setScore(KNIGHT_POINTS);
}

bool Knight::isMoveValid(int y, int x) {
    Board* board = getBoard();

    return false;
}