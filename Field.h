//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_FIELD_H
#define POO2LABO4_2020_FIELD_H


#include "Grille.h"
#include <list>

class Field {
public:
    int nexTurn();
    Humanoid& humanoidNeighbor(Humanoid& humanoid)const ;

private:
    unsigned turn = 0
    Grille* grid;
    list <Humanoid*> humanoids;

};


#endif //POO2LABO4_2020_FIELD_H
