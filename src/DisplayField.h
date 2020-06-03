//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_DISPLAYFIELD_H
#define POO2LABO4_2020_DISPLAYFIELD_H

#include <vector>
#include <iostream>
#include "Humanoid.h"

class Humanoid;
using namespace std;
//enum ValeurGrille {vide, Humanoid };
class DisplayField {
public:
    DisplayField(int width, int height);
    void initialize();
    void display();
    void update(Humanoid& humanoid);

    static const int BORNE_INF = 1;
    static const int BORNE_SUP = 100;
private:
    int _width;
    int _height;
    vector<vector<char >> field;

};


#endif //POO2LABO4_2020_DISPLAYFIELD_H
