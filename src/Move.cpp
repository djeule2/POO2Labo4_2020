/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Move.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe Move.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Move.h"

Move::Move(Humanoid *target, int xDestination, int yDestination) : Action(target),
                                                                   xDestination(xDestination),
                                                                   yDestination(yDestination) {}

void Move::execute(Field &field) {
    target->setPosition(xDestination, yDestination);
}
