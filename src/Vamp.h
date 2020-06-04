/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Vamp.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui permet de vampiriser un humain, la vampirisation a une chance
                sur deux d'aboutir dans le cas échéant l'humain meurt.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_VAMP_H
#define POO2LABO4_2020_VAMP_H


#include "Action.h"

class Vamp : public Action {
public :
    /**
     * Constructeur de Vamp.
     * @param target personne a vampiriser.
     */
    explicit Vamp(Humanoid *target);

    /**
     * Méthode qui permet d'exécuter la vampirisation.
     * @param field champs sur lequel appliquer la vampirisation.
     */
    void execute(Field &field) override;
};

#endif
