//
// Created by Lenovo T50s on 03.06.2020.
//
#ifndef POO2LABO4_2020_GAMEMANAGER_H
#define POO2LABO4_2020_GAMEMANAGER_H


#include "Field.h"

class GameManager {
public:
    GameManager();
    ~GameManager();
    void initializeGame();
    void start();
    void updateDisplay();
    void readControl (const string msg, const int borneInf, const int borneSup, int &val);
    void showMenu();
    void handleCommand(const string &cmd);

private:
    int width ;
    int height;
    int vambire;
    int human;
    unsigned turn = 0;
    Field * field;
    DisplayField* display;
    static const char QUIT='q', STATTISTIQUE= 's', NEXT= 'n';
};


#endif //POO2LABO4_2020_GAMEMANAGER_H
