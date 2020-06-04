/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Buffy.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui représente un humanoïde de type Buffy chasseuse de vampires.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_BUFFY_H
#define POO2LABO4_2020_BUFFY_H

#include "Humanoid.h"

class Buffy : public Humanoid {
private:
    Action *secondAction;

public:
    /**
     * Constructeur de buffy
     * @param x
     * @param y
     */
    Buffy(int x, int y);

    /**
     * Fonction qui permet de prévoir les actions
     * @param field champs sur lequel appliquer les actions
     */
    void setAction(Field &field) override;

    /**
     * Méthode qui permet d'exécuter les actions
     * @param field champs sur lequel appliquer les actions
     */
    void executeAction(Field &field) override;
};

#endif
