//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_FIELD_H
#define POO2LABO4_2020_FIELD_H


#include "DisplayField.h"
#include <list>
#include <limits>
#include "Humanoid.h"
class Humanoid;

using namespace std;
class Field {
public:
    explicit Field(int width, int height);

    /**
     *cette méthode permet pour chaque humanoïde de gérer un tour de simulation
     * @return
     */
    int nexTurn();

    /**
     *
     * @param humanoid
     */
    void addHumanoid(Humanoid* humanoid);

    list<Humanoid*> getListHumanoid();
    bool content (Humanoid* humanoid);
    Humanoid* findClosestBeing(Humanoid* humanoid, char);
    void reset();
    int getWidth();
    int getHeight();

    double distanceBetweenHumanoid(const Humanoid* first, const Humanoid* second);

private:
    int height;
    int width;
    unsigned turn = 0;
    std::list <Humanoid*> _humanoids;
    static const char QUIT='q', STATTISTIQUE= 's', NEXT= 'n';

};


#endif //POO2LABO4_2020_FIELD_H
