#include <iostream>
#include "GameManager.h"

int main() {
    GameManager gm;
    gm.initializeGame();
    gm.startGame();

    gm.start();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
