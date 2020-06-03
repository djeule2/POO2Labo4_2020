//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_HUMAN_H
#define POO2LABO4_2020_HUMAN_H


#include "Humanoid.h"


class Human: public Humanoid {
private:
public:
    Human(int x, int y);
    void setAction(Field& field) override;
    void executeAction(Field& field) override;
};


#endif //POO2LABO4_2020_HUMAN_H
