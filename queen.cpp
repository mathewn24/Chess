#include "game.h"
#include "board.h"
#include "queen.h"

using namespace std;

Queen::Queen(Color color, int y, int x, Board* board) : Piece(color, y, x, board) {
    setLabel(letter(QUEEN));
    setScore(QUEEN_POINTS);
}

bool Queen::isMoveValid(int y, int x) {
    Board* board = getBoard();
    int y1 = getY(); // Get y of source position.
    int x1 = getX(); // Get x of source postion.

    int absx = abs(x-x1); // Horizontal distance.
    int absy = abs(y-y1); // Vertical distance.

    // Check if the move is horizonal or vertical like a rook.
    if (y == y1 || x == x1) {
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
                return false; // Path is blocked.
            }
        }  

    // Check if the move is diagonal like a bishop.    
    } else if (absx == absy) {
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
                return false; // Path is blocked.
            }
        }
    
    // If neither conditions are met, then the move is invalid.    
    } else {
        return false;
    }

    // Check the destination.
    Piece* targ = board->get(y, x);
    if (targ == EMPTY || targ->getColor() != this->getColor()){
        return true; // Destination is empty or contains an opponent's piece.
    }
    
    return false; // Destination contains piece of the same color.
}