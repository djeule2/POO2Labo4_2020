/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Stats.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui permet la gestion des statistiques.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_STATS_H
#define POO2LABO4_2020_STATS_H

#include "Field.h"

class Stats {
public:
    /**
     * Méthode qui permet de produire des statistique d'après un champs et un nombre d'itérations.
     * @param simSize taille de la simulation.
     * @param field champs sur lequel appliquer la simulation.
     * @return les statistique sous al forme d'une string.
     */
    static string produceStats(size_t simSize, Field *field);
};

#endif
