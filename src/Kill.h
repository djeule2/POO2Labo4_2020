/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Kill.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe d'Action qui permet de tuer une cible.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_KILL_H
#define POO2LABO4_2020_KILL_H

#include "Action.h"

class Kill : public Action {
public:
    /**
     * Constructeur de Kill.
     * @param target personne a tuer.
     */
    explicit Kill(Humanoid *target);

    /**
     * Méthode d'exécution du "kill".
     * @param field champs sur lequel exécuter le "kill".
     */
    void execute(Field &field) override;
};

#endif
