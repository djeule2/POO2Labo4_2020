/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : DisplayField.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui permet l'affichage d'un Field.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_DISPLAYFIELD_H
#define POO2LABO4_2020_DISPLAYFIELD_H

#include <vector>
#include <iostream>
#include "Humanoid.h"

class Humanoid;

using namespace std;

class DisplayField {
public:
    /**
     * Constructeur de DisplayField
     * @param width largeur
     * @param height hauteur
     */
    DisplayField(int width, int height);

    /**
     * Méthode qui initialize la grille vide.
     */
    void initialize();

    /**
     * Méthode qui affiche la grille.
     */
    void display();

    /**
     * Méthode qui permet d'update la grille avec un Humanïde.
     * @param humanoid
     */
    void update(Humanoid &humanoid);

    static const int BORNE_INF = 1;
    static const int BORNE_SUP = 100;
private:
    int width;
    int height;
    vector<vector<char >> field;
};

#endif
