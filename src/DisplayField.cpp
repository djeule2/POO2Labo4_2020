/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : DisplayField.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe d'implémentation de DisplayField.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include <iomanip>
#include <iostream>
#include "DisplayField.h"

using namespace std;

DisplayField::DisplayField(int width, int height) : width(width), height(height) {
    field = vector<vector<char>>(height, vector<char>(width));
    this->initialize();
}

void DisplayField::initialize() {
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            field[row][column] = ' ';
        }
    }
}

void DisplayField::display() {
    cout << '+' << setfill('-') << setw(width + 1) << "+" << endl;
    for (int row = 0; row < height; row++) {
        cout << ":";
        for (int column = 0; column < width; column++) {
            cout << field[row][column];
        }
        cout << ":" << endl;
    }
    cout << '+' << setfill('-') << setw(width + 1) << "+" << endl;
}

void DisplayField::update(Humanoid &humanoid) {
    field[humanoid.getyPosition()][humanoid.getxPosition()] = humanoid.getName();
}
