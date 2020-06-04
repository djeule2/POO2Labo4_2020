/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Move.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe de type Action qui permet le déplacement d'un unité.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_MOVE_H
#define POO2LABO4_2020_MOVE_H

#include "Action.h"

class Move : public Action {

public:
    /**
     * Constructeur de Move
     * @param target humanoide qui se déplace
     * @param xDestination coord x de destination
     * @param yDestination coord y de destination
     */
    explicit Move(Humanoid *target, int xDestination, int yDestination);

    /**
     * Méthode qui permet l'exécution du mouvement.
     * @param field
     */
    void execute(Field &field) override;

private :
    int xDestination;
    int yDestination;
};

#endif
