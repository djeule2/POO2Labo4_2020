//
// Created by claudealves on 03.06.20.
//

#ifndef POO2LABO4_2020_KILL_H
#define POO2LABO4_2020_KILL_H


#include "Action.h"

class kill : public Action {
    explicit kill(Humanoid *target);
    void execute(Field &field) override;
};


#endif //POO2LABO4_2020_KILL_H
