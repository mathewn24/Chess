#include "game.h"
#include "board.h"
#include "rook.h"

using namespace std;

Rook::Rook(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(ROOK));
    setScore(ROOK_POINTS);
}

bool Rook::isMoveValid(int y, int x) {
    Board* board = getBoard();

    return false;
}