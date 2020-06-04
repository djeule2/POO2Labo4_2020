/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Vampire.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe Vampire.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Vampire.h"
#include "Wait.h"
#include "Vamp.h"
#include <cmath>

Vampire::Vampire(int x, int y) : Humanoid('v', x, y) {}

void Vampire::setAction(Field &field) {
    Humanoid *target = field.findClosestBeing(this, 'h');
    if (!action) {
        delete action;
    }
    if (!target) {
        action = new Wait(this);
    } else if (field.distanceBetweenHumanoid(this, target) > sqrt(2)) {
        action = moveToSomeone(target);
    } else {
        action = new Vamp(target);
    }
    //get the nearest human
    //(sleep waiting buffy kills him)
    //if he's further than sqrt(2) -> chase him
    //else if closer than sqrt(2) try to Vamp the nearest human
}

void Vampire::executeAction(Field &field) {
    if (action) {
        action->execute(field);
    }
}


