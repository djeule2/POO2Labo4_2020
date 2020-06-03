//
// Created by claudealves on 03.06.20.
//

#ifndef POO2LABO4_2020_WAIT_H
#define POO2LABO4_2020_WAIT_H


#include "Action.h"

class Wait : public Action {
public :
    explicit Wait(Humanoid *target);

    void execute(Field &field) override;
};


#endif //POO2LABO4_2020_WAIT_H
