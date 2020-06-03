//
// Created by claudealves on 03.06.20.
//

#ifndef POO2LABO4_2020_VAMP_H
#define POO2LABO4_2020_VAMP_H


#include "Action.h"
#include "Humain.h"

class vamp : public Action {
public :
    explicit vamp(Humanoid * target);
    void execute(Field & field) override;
};


#endif //POO2LABO4_2020_VAMP_H
