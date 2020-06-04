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
    explicit Field(int width, int height, int vampires, int humans);

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

    void createHumanoids(int nbreVampire, int nbrHuman);
    list<Humanoid*> getListHumanoid();
    bool content (Humanoid* humanoid);
    Humanoid* findClosestBeing(Humanoid* humanoid, char);
    void reset();
    void clear();
    int getWidth();
    int getHeight();
    int isGameOver();

    double distanceBetweenHumanoid(const Humanoid* first, const Humanoid* second);

private:
    int height;
    int width;
    int vampires;
    int humans;
    unsigned turn = 0;
    std::list <Humanoid*> _humanoids;
    static const char QUIT='q', STATTISTIQUE= 's', NEXT= 'n';

};


#endif //POO2LABO4_2020_FIELD_H
