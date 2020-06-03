#include <iostream>
#include "Grille.h"
#include "Field.h"

int main() {

   // Grille* grille = new Grille(50, 25);
    //grille->displayGrille();
    Field* field = new Field();
    field->startGame();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
