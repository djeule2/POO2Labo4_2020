/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Human.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de Human.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Human.h"

using namespace std;

Human::Human(int x, int y) : Humanoid('h', x, y) {
}

void Human::setAction(Field &field) {
    if (!action) {
        delete action;
    }
    action = moveRandom(field.getWidth(), field.getHeight());
}

void Human::executeAction(Field &field) {
    if (action) {
        action->execute(field);
    }
}


