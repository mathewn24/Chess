#include <iostream>
#include <cctype>
#include "game.h"
#include "board.h"
#include "pawn.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"

using namespace std;

Board::Board(Game* game) : game(game), cells() {  // initalize cells' elements to nullptr
    configure();
}

/* Set up the initial game board */
void Board::configure() {
    // modify this function body to set up the initial board properly;
    // add kings, queens, bishops, knights, rooks at correct positions

    for (int j = 0; j < W; j++) {
        cells[1][j] = new Pawn(BLACK, 1, j, this);
        cells[6][j] = new Pawn(WHITE, 6, j, this);
    }

    // Add black pieces.
    cells[0][4] = new King(BLACK, 0, 4, this);
    cells[0][3] = new Queen(BLACK, 0, 3, this);
    cells[0][2] = new Bishop(BLACK, 0, 2, this);
    cells[0][5] = new Bishop(BLACK, 0, 5, this);
    cells[0][1] = new Knight(BLACK, 0, 1, this);
    cells[0][6] = new Knight(BLACK, 0, 6, this);
    cells[0][0] = new Rook(BLACK, 0, 0, this);
    cells[0][7] = new Rook(BLACK, 0, 7, this);
    
    // Add white pieces.
    cells[7][4] = new King(WHITE, 7, 4, this);
    cells[7][3] = new Queen(WHITE, 7, 3, this);
    cells[7][2] = new Bishop(WHITE, 7, 2, this);
    cells[7][5] = new Bishop(WHITE, 7, 5, this);
    cells[7][1] = new Knight(WHITE, 7, 1, this);
    cells[7][6] = new Knight(WHITE, 7, 6, this);
    cells[7][0] = new Rook(WHITE, 7, 0, this);
    cells[7][7] = new Rook(WHITE, 7, 7, this);

    // Add the created pieces to each player's list of pieces.
    Player* wht = game->getWhite();
    Player* blk = game->getBlack();

    for (int k = 0; k < W; k++) {
        wht->addPiece(cells[7][k]);
        blk->addPiece(cells[0][k]);
    }
    
}

bool Board::isEmpty(int y, int x) {
    if (cells[y][x] == EMPTY)
        return true;
    return false;
}

Piece* Board::get(int y, int x){
    if (0 <= y && y < H && 0 <= x && x < W)
        return cells[y][x];
    return OUT_BOUND; // out of bound
}

void Board::put(int y, int x, Piece* p){
    cells[y][x] = p;
    if (p != EMPTY) {
        p->setY(y);
        p->setX(x);
    }
}

void Board::print() {
    cout << "    A   B   C   D   E   F   G   H  " << endl;
    cout << "  ---------------------------------" << endl;
    for (int i = 0; i < H; i++) {
        cout << i + 1;
        for (int j = 0; j < W; j++) {
            cout << " | ";
            if (isEmpty(i, j))
                cout << " ";
            else {
                if (cells[i][j]->getColor() == WHITE)
                    cout << (char)tolower(cells[i][j]->getLabel().at(0));
                else
                    cout << cells[i][j]->getLabel();
            }
        }
        cout << " | " << endl;
        cout << "  ---------------------------------" << endl;
    }
}

bool Board::move(int y1, int x1, int y2, int x2) {
    // (y1, x1) is source and (y2, x2) is destination
    // check against following invalid cases:
    
    // The source is an empty cell or if source and destination are the same position.
    if (isEmpty(y1,x1) || y1 == y2 && x1 == x2) {
        return false;
    } 
    
    // The destination is out of bound of the board (hint: use OUT_BOUND).
    if (get(y2, x2) == OUT_BOUND) {
        return false;
    }

    // The source piece is not of same color of current turn of the game.
    Piece* p = get(y1, x1);
    if (p->getColor() != game->getTurn()) {
        return false;
    }
    
    // Piece-specific validation
    if (p->isMoveValid(y2, x2) == false)
        return false;
    
    p->move(y2, x2);
    return true;
}

Game* Board::getGame() const {
    return game;
}
