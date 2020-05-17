//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_GRILLE_H
#define POO2LABO4_2020_GRILLE_H

#include "Humanoid.h"

enum ValeurGrille {vide, Humanoid };
class Grille {
public:
    Grille(int largeurGrille, int hauteurGrille);
    void displayGrille(int largeur, int hauteur);
private:
    int _largeurGrille;
    int _hauteurGrille;
    ValeurGrille* grille;
};


#endif //POO2LABO4_2020_GRILLE_H
