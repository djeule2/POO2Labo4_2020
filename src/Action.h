//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_ACTION_H
#define POO2LABO4_2020_ACTION_H


#include "Field.h"

class Humanoid;
class Field;

class Field;

class Action {
public:
    virtual void execute(Field &field) = 0;

protected :
    explicit Action(Humanoid *target) : target(target) {}
    Humanoid *target;
};


#endif //POO2LABO4_2020_ACTION_H
