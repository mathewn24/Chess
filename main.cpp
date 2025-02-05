/*
 * By: mathewn24
 */

#include <iostream>
#include "game.h"

using namespace std;

int main() {
    cout << "Choose game mode (1, 2, 3): ";
    int mode;
    cin >> mode;
    Game game((Mode)mode);
    game.run();
    return 0;
}
