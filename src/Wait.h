/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Wait.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe de type Action qui permet l'attente ( elle ne fait rien mais
                pourrait avoir un effet sur la cible de l'attente ou autre).

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_WAIT_H
#define POO2LABO4_2020_WAIT_H

#include "Action.h"

class Wait : public Action {
public :
    /**
     * Constructeur d'attente.
     * @param target cible qui attent.
     */
    explicit Wait(Humanoid *target);

    /**
     * Méthode qui permet l'exécution de l'attente.
     * @param field
     */
    void execute(Field &field) override;
};

#endif
