//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_HUMAIN_H
#define POO2LABO4_2020_HUMAIN_H


#include "Humanoid.h"


class Humain: public Humanoid {
private:
public:
    Humain( int x, int y);
    void setAction(Field& field);
    void executeAction(Field& field);


};


#endif //POO2LABO4_2020_HUMAIN_H
