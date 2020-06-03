//
// Created by Lenovo T50s on 03.06.2020.
//

#include "GameManager.h"
#include "GameManager.h"
#include "Buffy.h"
#include "Humain.h"
#include "Vampire.h"
#include "Utils.h"

GameManager::GameManager() {
    _field = new Field();
    initializeGame();
    _grille = new Grille(_largeurGrille, _hauteurGrille);
    createHumanoid(_nbrVambire, _nbrHumain);
    loadListHumanoidGrid();
    _grille->displayGrille();
}

void GameManager::initializeGame() {
    readControl("Largeur Grille", Grille::BORNE_INF, Grille::BORNE_SUP, _largeurGrille);
    readControl("Hauteur Grille", Grille::BORNE_INF, Grille::BORNE_SUP, _hauteurGrille);
    readControl("Nombres humains", 0, _largeurGrille * _hauteurGrille - 1, _nbrHumain);
    readControl("Nombres Vampires", 0, _largeurGrille * _hauteurGrille - _nbrHumain - 1, _nbrVambire);
}

void GameManager::createHumanoid(int nbreVampire, int nbrHuman) {
    //creation du Buffy
    _field->addHumanoid(new Buffy(Utils::getRandomNumber(0, _largeurGrille),
                                  Utils::getRandomNumber(0, _hauteurGrille)));
    for (int i = 0; i < nbrHuman; i++) {
        //creation de Humain
        _field->addHumanoid(new Humain(Utils::getRandomNumber(0, _largeurGrille),
                                       Utils::getRandomNumber(0, _hauteurGrille)));
    }
    for (int j = 0; j < nbreVampire; j++) {
        //creation Vampire
        _field->addHumanoid(new Vampire(Utils::getRandomNumber(0, _largeurGrille),
                                        Utils::getRandomNumber(0, _hauteurGrille)));
    }
}

void GameManager::loadListHumanoidGrid() {
    for (_List_iterator<Humanoid *> it = _field->getListHumanoid().begin();
         it != _field->getListHumanoid().end(); ++it) {
        _grille->updateGrid(**it);
    }
}


void GameManager::setGameOver(bool gameOver) {
    _gameOver = gameOver;
}

bool GameManager::isGameOver() {
    return _gameOver;
}

int GameManager::getLageurGrille() {
    return _largeurGrille;
}

int GameManager::getHauteurGrille() {
    return _hauteurGrille;
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
}

void GameManager::handleCommand(const string &cmd) {
    switch (cmd.at(0)) {
        case NEXT:
            break;
        case STATTISTIQUE:
            break;
        case QUIT:
            break;
        default:
            cout << "commande invalide" << endl;
            break;
    }

}

void GameManager::startGame() {
    string commande;

    do {
        cout << turn << ">";
        getline(cin, commande);

        handleCommand(commande);
    } while (commande.at(0) != QUIT);
}
