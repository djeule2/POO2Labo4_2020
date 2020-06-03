//
// Created by Lenovo T50s on 03.06.2020.
//
#ifndef POO2LABO4_2020_GAMEMANAGER_H
#define POO2LABO4_2020_GAMEMANAGER_H


#include "Field.h"

class GameManager {
public:
    GameManager();
    void initializeGame();
    void startGame();
    void createHumanoid(int nbreVampire, int nbrHuman);
    void loadListHumanoidGrid();
    void readControl (const string msg, const int borneInf, const int borneSup, int &val);
    void showMenu();
    void handleCommand(const string &cmd);
    bool isGameOver();
    void setGameOver(bool gameOver);
    int getLageurGrille();
    int getHauteurGrille();

private:
    int _largeurGrille ;
    int _hauteurGrille;
    int _nbrVambire;
    int _nbrHumain;
    unsigned turn = 0;
    Field * _field;
    Grille* _grille;
    bool _gameOver;
    static const char QUIT='q', STATTISTIQUE= 's', NEXT= 'n';
};


#endif //POO2LABO4_2020_GAMEMANAGER_H