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
        int y2, x2;
        bool valid = false;

        for (int i = 0; i < TRIALS; i++) {
            // - generate random integers y2 and x2 in range of [0, H) and [0, W) respectively
            y2 = rand() % H;
            x2 = rand() % W;
            // - call board's move(y1, x1, y2, x2)
            cout << "From : (" << y1 << ", " << x1 << ") " << "To: (" << y2 << ", " << x2 << ") " << endl;
            valid = board->move(y1, x1, y2, x2);
            // - once a valid move is returned, print the from and to cell addresses
            //   and exit this function
            if (valid) {
                std::cout << "Random coordinates picked: ";
                std::cout << char(x2 + 'A') << y2+1 << std::endl;
                break;
            }
            cout << "Invalid input!" << endl;
        }
    }
}
