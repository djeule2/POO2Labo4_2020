//
// Created by claudealves on 03.06.20.
//

#ifndef POO2LABO4_2020_MOVE_H
#define POO2LABO4_2020_MOVE_H


#include "Action.h"

class Move : public Action {

public:
    explicit Move(Humanoid *target, int xDestination, int yDestination);

    void execute(Field &field) override;

private :
    int xDestination;
    int yDestination;
};


#endif //POO2LABO4_2020_MOVE_H
