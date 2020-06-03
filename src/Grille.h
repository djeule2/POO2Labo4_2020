//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_GRILLE_H
#define POO2LABO4_2020_GRILLE_H

#include <vector>
#include <iostream>
#include "Humanoid.h"

class Humanoid;
using namespace std;
//enum ValeurGrille {vide, Humanoid };
class Grille {
public:
    Grille(int largeurGrille, int hauteurGrille);
    void initializeGrid();
    void displayGrille();
    int getLargeurGrille();
    int getHauteurGrille();
    void setLargeurGrille(int largeur);
    void setHauteurGrille(int hauteur);
    void updateGrid(Humanoid& humanoid);

    static const int BORNE_INF = 1;
    static const int BORNE_SUP = 100;
private:
    int _largeurGrille;
    int _hauteurGrille;
    vector<vector<char >> grid;

};


#endif //POO2LABO4_2020_GRILLE_H
