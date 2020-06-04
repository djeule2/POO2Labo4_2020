/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Action.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe abstraite d'implémentation d'une action.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_ACTION_H
#define POO2LABO4_2020_ACTION_H

#include "Field.h"

class Humanoid;

class Field;

class Action {
public:
    /**
     * Méthode qui permet d'exécuter la dite action.
     * @param field sur quel champs appliquer l'action
     */
    virtual void execute(Field &field) = 0;

    /**
     * Destructeur d'action.
     */
    virtual ~Action();

protected :
    /**
     * Constructeur d'Action pour set la target de l'action.
     * @param target
     */
    explicit Action(Humanoid *target);

    Humanoid *target;
};

#endif
