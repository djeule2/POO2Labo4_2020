//
// Created by claudealves on 03.06.20.
//

#ifndef POO2LABO4_2020_KILL_H
#define POO2LABO4_2020_KILL_H


#include "Action.h"

class Kill : public Action {
    explicit Kill(Humanoid *target);
    void execute(Field &field) override;
};


#endif //POO2LABO4_2020_KILL_H
