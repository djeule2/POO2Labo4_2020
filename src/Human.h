/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Human.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui représente un humain, de la chair pour vampire.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_HUMAN_H
#define POO2LABO4_2020_HUMAN_H

#include "Humanoid.h"

class Human : public Humanoid {
public:
    /**
     * Constructeur de Human.
     * @param x position en x
     * @param y position en y
     */
    Human(int x, int y);

    /**
     * Méthode qui permet de set l'action d'un humain.
     * @param field
     */
    void setAction(Field &field) override;

    /**
     * Méthode qui permet d'exécuter l'action d'un humain.
     * @param field
     */
    void executeAction(Field &field) override;
};

#endif
