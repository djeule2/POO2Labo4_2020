/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Field.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui représente le champs ou des Humanoïdes font des actions

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
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
    /**
     * Constructeur de Field.
     * @param width
     * @param height
     * @param vampires
     * @param humans
     */
    explicit Field(int width, int height, int vampires, int humans);

    /**
     * Méthode qui permet pour chaque humanoïde de gérer un tour de simulation.
     * @return
     */
    int nexTurn();

    /**
     * Méthode qui permet l'ajout d'un Humanoïde au champ.
     * @param humanoid
     */
    void addHumanoid(Humanoid *humanoid);

    /**
     * Méthode qui permet la création d'un nombre donné de vampires et d'humains ainsi que d'un entité de Buffy.
     * @param nbreVampire
     * @param nbrHuman
     */
    void createHumanoids(int nbreVampire, int nbrHuman);

    /**
     * Méthode qui permet de récupérer les humanoïde actuellement présents sur le champs.
     * @return list d'humanoïdes
     */
    list<Humanoid *> getListHumanoid();

    /**
     * Méthode qui permet de trouver l'humanoïde le plus proche selon son nom(type).
     * @param humanoid
     * @return un pointeur vers l'humanoïde le plus proche
     */
    Humanoid *findClosestBeing(Humanoid *humanoid, char);

    /**
     * Méthode qui permet de reset l'état du champs.
     */
    void reset();

    /**
     * Méthode qui permet clear le champs.
     */
    void clear();

    /**
     * Méthode qui permet d'avoir la largeur du champs.
     * @return in de la largeur
     */
    int getWidth();

    /**
     * Mthode qui permet d'avoir la hauteur du champs.
     * @return int de la hauteur
     */
    int getHeight();

    /**
     * Méthode qui permet de savoir l'était du champs.
     *  -  0 si il y a toujours des vampires et des humains.
     *  - -1 si iil n'y a plus d'humain sur le champs.
     *  -  1 si il n'y a plus de vampire et encore des humains.
     * @return
     */
    int isGameOver();

    /**
     * Méthode qui permet d'avoir la distance entre deux Humanoïdes.
     * @param first
     * @param second
     * @return la ddistance en double.
     */
    double distanceBetweenHumanoid(const Humanoid *first, const Humanoid *second);

private:
    int height;
    int width;
    int vampires;
    int humans;
    unsigned turn = 0;
    std::list<Humanoid *> _humanoids;
};

#endif
