//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_FIELD_H
#define POO2LABO4_2020_FIELD_H


#include "Grille.h"
#include <list>
#include <limits>
class Humanoid;
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

    /**
     * Méthode qui agit selon la commande de l'utilisateur
     * @param cmd commande de l'utilisateur
     */
    void handleCommand(const string &cmd);


    /**
     * Méthode d'affichage du menu
     */
    static void showMenu();


    /**
     *
     * @param msg
     * @param borneInf
     * @param borneSup
     * @param val
     * @return
     */
   void readControl (string msg, const int borneInf, const int borneSup, int &val);

    /**
     * Méthode qui lance le debut du jeu;
     */
    void startGame();
    void createHumanoid(int nbreVampire, int nbrHuman);
    void loadListHumanoidGrid();
    bool content (Humanoid* humanoid);
    Humanoid& findNearestHumanoid(Humanoid* humanoid);
    double distanceBetweenHumanoid(const Humanoid* humanoidfirst, const Humanoid* humanoidsecond);

private:
    unsigned turn = 0;
    Grille* grid;
    list <Humanoid*> _humanoids;
    static const char QUIT='q', STATTISTIQUE= 's', NEXT= 'n';

};


#endif //POO2LABO4_2020_FIELD_H
