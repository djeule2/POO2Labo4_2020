//
// Created by Lenovo T50s on 03.06.2020.
//

#include "GameManager.h"
#include "Buffy.h"
#include "Human.h"
#include "Vampire.h"
#include "Utils.h"
#include "Stats.h"

GameManager::GameManager() {}

GameManager::~GameManager(){
    delete _field;
    delete _display;
}

void GameManager::initializeGame() {
    readControl("Largeur DisplayField", DisplayField::BORNE_INF, DisplayField::BORNE_SUP, _width);
    readControl("Hauteur DisplayField", DisplayField::BORNE_INF, DisplayField::BORNE_SUP, _height);
    readControl("Nombres humains", 0, _width * _height - 1, _nbrHumain);
    readControl("Nombres Vampires", 0, _width * _height - _nbrHumain - 1, _nbrVambire);
    _field = new Field(_width, _height, _nbrVambire, _nbrHumain);
}

void GameManager::updateDisplay() {
    list<Humanoid*>humanoids = _field->getListHumanoid();
    _display->initialize();
    for (list<Humanoid*>::iterator it = humanoids.begin();
         it != humanoids.end(); ++it) {
         _display->update(**it);
    }
}

void GameManager::showMenu() {
    cout << QUIT << ">quit :";
    cout << STATTISTIQUE << ">tatisties :";
    cout << NEXT << ">ext :";
}

void GameManager::readControl(const string msg, const int borneInf, const int borneSup, int &val) {
    cout << "Entrez " << msg << " comprise entre [" << borneInf <<
         "-" << borneSup << "]: ";
    while (!(cin >> val) || val < borneInf || val > borneSup) {
        if (cin.fail()) {
            cout << "saisie incorrecte : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "le chiffre pas dans l'intervalle [" << borneInf <<
                 " - " << borneSup << "] : ";
        }
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void GameManager::handleCommand(const string &cmd) {
    switch (cmd.at(0)) {
        case NEXT:
            _field->nexTurn();
            updateDisplay();
            _display->display();
            break;
        case STATTISTIQUE:
            cout << Stats::produceStats(10000, _field) << "%" << endl;
            break;
        case QUIT:
            break;
        default:
            cout << "commande invalide" << endl;
            break;
    }

}

void GameManager::start() {
    string commande;
    initializeGame();
    _display = new DisplayField(_width, _height);
    _field->createHumanoids(_nbrVambire, _nbrHumain);
    updateDisplay();
    _display->display();

    do {
        cout << turn << ">";
        showMenu();
        getline (std::cin, commande);

        handleCommand(commande);

    } while (commande.at(0) != QUIT);
}

void GameManager::produceStats() {

}
