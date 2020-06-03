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
    Field();

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

    /**
     * Méthode qui permet de trouver l'humanoïde, instance d'une classe donnée, le  plus
     * proche d'un humanoïde donné.
     * @param humanoid
     * @return
     */
    Humanoid& humanoidNeighbor(Humanoid& humanoid)const ;


    list<Humanoid*> getListHumanoid();
    bool content (Humanoid* humanoid);
    Humanoid& findNearestHumanoid(Humanoid* humanoid);
    Humanoid& findNearestVampire(Humanoid* humanoid);
    Humanoid& findClosestHuman(Humanoid* humanoid);

    double distanceBetweenHumanoid(const Humanoid* humanoidfirst, const Humanoid* humanoidsecond);

private:
    unsigned turn = 0;
    std::list <Humanoid*> _humanoids;
    static const char QUIT='q', STATTISTIQUE= 's', NEXT= 'n';

};


#endif //POO2LABO4_2020_FIELD_H
