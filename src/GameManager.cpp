//
// Created by Lenovo T50s on 03.06.2020.
//

#include "GameManager.h"
#include "Buffy.h"
#include "Human.h"
#include "Vampire.h"
#include "Utils.h"

GameManager::GameManager() {
    _field = new Field();

}

GameManager::~GameManager(){
    delete _field;
    delete _display;
}

void GameManager::initializeGame() {
    readControl("Largeur DisplayField", DisplayField::BORNE_INF, DisplayField::BORNE_SUP, _width);
    readControl("Hauteur DisplayField", DisplayField::BORNE_INF, DisplayField::BORNE_SUP, _height);
    readControl("Nombres humains", 0, _width * _height - 1, _nbrHumain);
    readControl("Nombres Vampires", 0, _width * _height - _nbrHumain - 1, _nbrVambire);
}

void GameManager::createHumanoid(int nbreVampire, int nbrHuman) {
    //creation du Buffy
    _field->addHumanoid(new Buffy(Utils::getRandomNumber(0, _width-1),
                                  Utils::getRandomNumber(0, _height-1)));
    for (int i = 0; i < nbrHuman; i++) {
        //creation de Human
        _field->addHumanoid(new Human(Utils::getRandomNumber(0, _width-1),
                                      Utils::getRandomNumber(0, _height-1)));
    }
    for (int j = 0; j < nbreVampire; j++) {
        //creation Vampire
        _field->addHumanoid(new Vampire(Utils::getRandomNumber(0, _width-1),
                                        Utils::getRandomNumber(0, _height-1)));
    }
}

void GameManager::updateDisplay() {
    list<Humanoid*>humanoids = _field->getListHumanoid();
    for (_List_iterator<Humanoid *> it = humanoids.begin();
         it != humanoids.end(); ++it) {
         _display->update(**it);
    }
}


void GameManager::setGameOver(bool gameOver) {
    _gameOver = gameOver;
}

bool GameManager::isGameOver() {
    return _gameOver;
}

int GameManager::getLageurGrille() {
    return _width;
}

int GameManager::getHauteurGrille() {
    return _height;
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

void GameManager::start() {
    string commande;
    initializeGame();
    _display = new DisplayField(_width, _height);
    createHumanoid(_nbrVambire, _nbrHumain);
    updateDisplay();
    _display->display();

    do {
        cout << turn << ">";
        getline (std::cin, commande);

        handleCommand(commande);
    } while (commande.at(0) != QUIT);
}
