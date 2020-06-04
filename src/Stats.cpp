/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Stats.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe Stats.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include <sstream>
#include "Stats.h"
#include <chrono>

string Stats::produceStats(size_t simSize, Field *field) {
    size_t numberOfVictorySims = 0;
    std::ostringstream stream;
    field->reset();
    const auto start = std::chrono::system_clock::now();
    for (size_t i = 0; i < simSize; ++i) {
        field->reset();
        while (field->isGameOver() == 0) {
            field->nexTurn();
        }
        if (field->isGameOver() == 1) {
            numberOfVictorySims++;
        }
    }
    const auto stop = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = stop - start;
    stream << ((double) numberOfVictorySims / (double) simSize * 100.0) << "% temps de simulation : "
           << diff.count() << " s";
    return stream.str();
}
