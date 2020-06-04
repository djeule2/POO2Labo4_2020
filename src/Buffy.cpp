/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Buffy.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe Buffy.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Buffy.h"
#include "Kill.h"
#include <cmath>

Buffy::Buffy(int x, int y) : Humanoid('B', x, y), secondAction(nullptr) {
}

void Buffy::setAction(Field &field) {
    Humanoid *target = field.findClosestBeing(this, 'v');
    if (!action) {
        delete action;
    }
    if (!secondAction) {
        delete secondAction;
    }

    if (!target) {
        action = moveRandom(field.getWidth(), field.getHeight());
        secondAction = moveRandom(field.getWidth(), field.getHeight());
    } else if (field.distanceBetweenHumanoid(this, target) > sqrt(8)) {
        action = moveToSomeone(target);
        secondAction = moveToSomeone(target);
    } else {
        action = moveToSomeone(target);
        secondAction = new Kill(target);
    }
    //get the nearest vampire
    //if he's further than 2sqrt(2) chase after him
    //else if closer than 2sqrt(2) Kill him
    //else (game supposed to be finished)
}

void Buffy::executeAction(Field &field) {
    if (action && secondAction) {
        action->execute(field);
        // Buffy est très forte elle a deux actions
        secondAction->execute(field);
    }
}
