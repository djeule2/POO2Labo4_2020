/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Vampire.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui représente un vampire qui cherche a vampiriser tous les
                humains qui ne sont pas Buffy sur la map.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_VAMPIRE_H
#define POO2LABO4_2020_VAMPIRE_H

#include "Humanoid.h"

class Vampire : public Humanoid {
public:
    /**
     * Constructeur de vampire.
     * @param x
     * @param y
     */
    Vampire(int x, int y);

    /**
     * Méthode qui permet de set l'action que va faire le vampire.
     * @param field sur lequel procèder à l'action.
     */
    void setAction(Field &field) override;

    /**
     * Méthode qui permet d'exécuter l'action du vampire.
     * @param field champs sur leuql appliquer l'action.
     */
    void executeAction(Field &field) override;
};

#endif
