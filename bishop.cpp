#include "game.h"
#include "board.h"
#include "bishop.h"

Bishop::Bishop(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(BISHOP));
    setScore(BISHOP_POINTS);
}

bool Bishop::isMoveValid(int y, int x) {
    Board* board = getBoard();
    int y1 = getY(); // Get y of source.
    int x1 = getX(); // Get x of source.
    int absy = abs(y-y1);
    int absx = abs(x-x1);

    // Check if the move is diagonal.
    if (absx != absy) {
        return false;
    }

    // Check if the path is blocked.
    // Get the direction of a single step forward.
    int dx = (x-x1)/absx;
    int dy = (y-y1)/absy;    

    // Check if the path is clear for the k values between the two points.
    for (int k = 1; k < absx; k++) {
        int checkX = x1 + k*dx;
        int checkY = y1 + k*dy;
        Piece* pathPiece = board->get(checkY, checkX);
        if (pathPiece != EMPTY) {
            return false;
        }
    }
    
    // Check the destination.
    Piece* targ = board->get(y, x);
    if (targ == EMPTY || targ->getColor() != this->getColor()){
        return true; // Destination is empty or contains an opponent's piece.
    }
        
    return false;
}