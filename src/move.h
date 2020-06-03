//
// Created by claudealves on 03.06.20.
//

#ifndef POO2LABO4_2020_MOVE_H
#define POO2LABO4_2020_MOVE_H


#include "Action.h"

class move : public Action {
    move(Humanoid* target, int xDestination, int yDestination);
    void execute(Field &field) override;
};


#endif //POO2LABO4_2020_MOVE_H
