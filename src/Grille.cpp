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

void Grille::initializeGrid(){
    for(int row= 0; row<_hauteurGrille; row++){
        for (int column=0; column<_largeurGrille; column++){
            grid[row][column]=' ';
        }
    }
}

void Grille::displayGrille() {
    cout <<'+'<< setfill('-') << setw(_largeurGrille+1) <<"+"<< endl;
    for(int row= 0; row<_hauteurGrille; row++){
        cout<<":";
        for (int column=0; column<_largeurGrille; column++){
            cout << grid[row][column];
        }
        cout <<":"<<endl;
    }
    cout <<'+'<< setfill('-') << setw(_largeurGrille+1) <<"+"<<endl;
}

int Grille::getLargeurGrille(){
    return _largeurGrille;
}
int Grille::getHauteurGrille(){
    return _hauteurGrille;
}
void Grille::setLargeurGrille(int largeur){
    _largeurGrille=largeur;
}
void Grille::setHauteurGrille(int hauteur){
    _hauteurGrille = hauteur;
}
void Grille::updateGrid(Humanoid& humanoid){
    grid[humanoid.getxPosition()][humanoid.getyPosition()]=humanoid.getName();
}
