//
// Created by Lenovo T50s on 14.05.2020.
//

#include <iomanip>
#include <iostream>
#include "Grille.h"
using namespace std;
Grille::Grille(int largeurGrille, int hauteurGrille): _largeurGrille(largeurGrille), _hauteurGrille(hauteurGrille) {
    grid=vector<vector<char>>(hauteurGrille, vector<char >(largeurGrille));
    this->initializeGrid();
}
void Grille::initializeGrid()const {

}
void Grille::displayGrille() {
    cout <<'+'<< setfill('-') << setw(_largeurGrille) <<"+"<< "\n";
    for(int row= 0; row<_hauteurGrille; row++){
        cout<<"¦";
        for (int column=0; column<_largeurGrille; column++){
            cout << grid[row][column];

        }
        cout <<"|"<<"\n";
    }
    cout <<'+'<< setfill('-') << setw(_largeurGrille) <<"+"<< "\n";

}
