//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_VAMPIRE_H
#define POO2LABO4_2020_VAMPIRE_H


#include "Humanoid.h"

class Vampire: public Humanoid {
private:
public:
    Vampire(int x, int y);
    void setAction(Field& field);
    void executeAction(Field& field);


};


#endif //POO2LABO4_2020_VAMPIRE_H
