/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : GameManager.h
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Classe qui permet la gestion des menus et tous ce qui en a atrait.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#ifndef POO2LABO4_2020_GAMEMANAGER_H
#define POO2LABO4_2020_GAMEMANAGER_H

#include "Field.h"

class GameManager {
public:
    /**
     * Constructeur de GameManager.
     */
    GameManager();

    /**
     * Destructeur de GameManager.
     */
    ~GameManager();

    /**
     * Méthode qui permet de lancer le jeu.
     */
    void start();

private:
    /**
     * Méthode qui permet l'initialisation du jeu.
     */
    void initializeGame();

    /**
     * Méthode qui permet de mettre à jour le display.
     */
    void updateDisplay();

    /**
     * Méthode qui permet le contrôle d'une saisie.
     * @param msg
     * @param borneInf
     * @param borneSup
     * @param val
     */
    void readControl(const string msg, const int borneInf, const int borneSup, int &val);

    /**
     * Méthode d'affichage du menu.
     */
    void showMenu();

    /**
     * Méthode qui permet de gêrer une commande.
     * @param cmd commande à gêrer.
     */
    void handleCommand(const string &cmd);

    /**
     * Méthode qui regarde si la parti en cours est toujours en cours perdu ou gagnée par buffy
     */
    void gameOver();

    int width;
    int height;
    int vambire;
    int human;
    Field *field;
    DisplayField *display;
    static const char QUIT = 'q', STATTISTIQUE = 's', NEXT = 'n', ENTER = '\n';
};

#endif
