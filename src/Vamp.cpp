/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Vamp.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe Vamp.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Vamp.h"
#include "Utils.h"
#include "Vampire.h"
#include "Humanoid.h"

void Vamp::execute(Field &field) {
    if (Utils::getRandomNumber(0, 1) == 1) {
        field.addHumanoid(new Vampire(target->getxPosition(), target->getyPosition()));
    }
    target->kill();
}

Vamp::Vamp(Humanoid *target) : Action(target) {}
