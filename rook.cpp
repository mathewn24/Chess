#include "game.h"
#include "board.h"
#include "rook.h"

Rook::Rook(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(ROOK));
    setScore(ROOK_POINTS);
}

bool Rook::isMoveValid(int y, int x) {
    Board* board = getBoard();
    int y1 = getY(); // Get y of source.
    int x1 = getX(); // Get x of source.
    int absx = abs(x-x1);
    int absy = abs(y-y1);
    
    // Check is at least one of the coordinates stayed the same.
    if (absx && absy) {
        return false;
    }

    // Determine the direction of movement
    int dy = 0, dx = 0;
    if (absx != 0) {
        dx = (x-x1)/absx;
    } else if (absy != 0) {
        dy = (y-y1)/absy;
    }

    // Calculate the number of steps needed depending on the direction.
    int steps = (dx != 0) ? absx : absy;

    // Check if the path is clear for the k values between the two points.
    for (int k = 1; k < steps; k++) {
        int checkX = x1 + k*dx;
        int checkY = y1 + k*dy;
        Piece* pathPiece = board->get(checkY, checkX);
        if (pathPiece != EMPTY) {
            return false;
        }
    }    

    // Check the destination.
    Piece* targ = board->get(y, x);
    if (targ == EMPTY || targ->getColor() != this->getColor()) {
        return true; // Destination is empty or contains an opponent's piece.
    }
    
    return false;
}