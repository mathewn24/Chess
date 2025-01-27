#include <iostream>
#include "machine.h"
#include "board.h"
#include <ctime>

using namespace std;

const int TRIALS = 4096;    // 64 x 64

Machine::Machine(string name, Color color) : Player(name, color) {
    // randomize the seed
    srand(static_cast<unsigned int>(time(nullptr)));
}

// a sample machine that makes random but valid moves
void Machine::makeMove(Board* board) {
    for (int i = 0; i < 10 * getPieceCount(); i++) {
        int j = rand() % getPieceCount();
        Piece* p = getPiece(j);
        int y1 = p->getY();
        int x1 = p->getX();
        
        // write a loop to repeat below at most TRIALS times:
        int attempts = 0;
        int y2, x2;
        bool valid = false;

        while((attempts < TRIALS) and (!valid)) {
            // - generate random integers y2 and x2 in range of [0, H) and [0, W) respectively
            y2 = rand() % 8;
            x2 = rand() % 8;
            // - call board's move(y1, x1, y2, x2)
            valid = board->move(y1, x1, y2, x2);
            // - once a valid move is returned, print the from and to cell addresses 
            if (valid) {
                std::cout << "Random coordinates picked: ";
                std::cout << char(y2 + 'A') << x2+1 << std::endl;
            }
            attempts += 1;
        }
        
        //   and exit this function
        if (valid)
            break;
    }
}
