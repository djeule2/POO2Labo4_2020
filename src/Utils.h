/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Utils.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui propose des outils utilitaires.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_UTILS_H
#define POO2LABO4_2020_UTILS_H

using namespace std;

class Utils {
public :
    /**
     * Méthode qui permet d'avoir un int aléatoire entre deux bornes.
     * @param from borne inférieure.
     * @param to borne supérieure.
     * @return un nombre aléatoire.
     */
    static int getRandomNumber(int from, int to);
};

#endif
