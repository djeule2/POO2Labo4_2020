/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Kill.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe Kill.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Kill.h"

Kill::Kill(Humanoid *target) : Action(target) {}

void Kill::execute(Field &field) {
    target->kill();
}
