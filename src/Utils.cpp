/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Utils.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : fichier d'implémentation de la classe Utils.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include <random>
#include <chrono>
#include "Utils.h"

int Utils::getRandomNumber(int from, int to) {
    // https://blog.alphorm.com/les-fonctions-aleatoires-en-c-11/
    static default_random_engine randGenerator(std::chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> distribution(from, to);
    return distribution(randGenerator);
}
