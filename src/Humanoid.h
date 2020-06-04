/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Humanoid.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe abstraite qui représente une entité qui peuple un Field.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_HUMANOID_H
#define POO2LABO4_2020_HUMANOID_H

#include "Action.h"

class Field;

class Move;

class Action;

class Humanoid {
protected:
    char name;
    int xPosition;
    int yPosition;
    bool dead;
    Action *action;

    /**
     * Méthode qui permet de créer une Action de déplacement vers un autre Humanoide.
     * @param target vers qui se déplacer
     * @return une Action
     */
    Action *moveToSomeone(Humanoid *target);

    /**
     * Méthode qui permet de créer une Action avec un déplacement aléatoire.
     * @param width borne horizontale du champs
     * @param height borne verticale du champs
     * @return une Action
     */
    Action *moveRandom(int width, int height);

public:
    /**
     * Constructeur d'humanoide.
     * @param name
     * @param x
     * @param y
     */
    Humanoid(char name, int x, int y);

    /**
     * Méthode qui permet d'avoir le nom (type) de l'humanoide.
     * @return le nom
     */
    virtual char getName() const;

    /**
     * Méthode qui permet la position en x de l'humanoide.
     * @return coord x
     */
    virtual int getxPosition() const;

    /**
     * Méthode qui permet la position en y de l'humanoide.
     * @return coord y
     */
    virtual int getyPosition() const;

    /**
     * Méthode qui permet de changer la position de l'humanoide.
     * @param x
     * @param y
     */
    virtual void setPosition(int x, int y);

    /**
     * Méthode qui permet de savoir si l'humanoide est en vie.
     * @return l'état de vie de l'humanoide
     */
    virtual bool isAlive();

    /**
     * Méthode qui permet de set l'action de l'humanoide.
     * @param field champs sur lequel appliquer l'action
     */
    virtual void setAction(Field &field) = 0;

    /**
     * Méthode qui permet d'exécuter l'action de l'humanoide.
     * @param field champs sur lequel appliquer l'action
     */
    virtual void executeAction(Field &field) = 0;

    /**
     * Méthode qui permet de "tuer" l'humanoide
     */
    virtual void kill();
};

#endif
