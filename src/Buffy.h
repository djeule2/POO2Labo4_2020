//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_BUFFY_H
#define POO2LABO4_2020_BUFFY_H


#include "Humanoid.h"

class Buffy : public Humanoid {
private:
    Action * secondAction;
public:
    Buffy(int x, int y);
    void setAction(Field& field) override;
    void executeAction(Field& field) override;


};


#endif //POO2LABO4_2020_BUFFY_H
