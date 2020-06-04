/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : main.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Programme de simulation d'une séance de chasse de buffy, dans laquelle
                elle chasse des vampires qui eux chassent des humains qui est cours
                aléatoirement sur la map.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "GameManager.h"

int main() {
    GameManager gm;
    gm.start();
    return 0;
}
