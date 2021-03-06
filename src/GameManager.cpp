/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : GameManager.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe GameManager.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "GameManager.h"
#include "Stats.h"

GameManager::GameManager() {}

GameManager::~GameManager() {
    delete field;
    delete display;
}

void GameManager::initializeGame() {
    readControl("la largeur du champs", DisplayField::BORNE_INF, DisplayField::BORNE_SUP, width);
    readControl("la hauteur du champs", DisplayField::BORNE_INF, DisplayField::BORNE_SUP, height);
    readControl("le nombres de humains", 0, width * height - 1, human);
    readControl("le nombres de Vampires", 0, width * height - human - 1, vambire);
    field = new Field(width, height, vambire, human);
}

void GameManager::updateDisplay() {
    list<Humanoid *> humanoids = field->getListHumanoid();
    display->initialize();
    for (list<Humanoid *>::iterator it = humanoids.begin();
         it != humanoids.end(); ++it) {
        display->update(**it);
    }
}

void GameManager::showMenu() {
    cout << QUIT << ">quit :";
    cout << STATTISTIQUE << ">tatistcs :";
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
        case ENTER:
        case NEXT:
            field->nexTurn();
            updateDisplay();
            display->display();
            gameOver();
            break;
        case STATTISTIQUE:
            cout << Stats::produceStats(10000, new Field(width, height, vambire, human)) << endl;
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
    display = new DisplayField(width, height);
    field->createHumanoids(vambire, human);
    updateDisplay();
    display->display();

    do {
        cout << field->getTurn() << ">";
        showMenu();
        getline(std::cin, commande);
        if(!commande.size()) {
            commande = ENTER;
        }
        handleCommand(commande);

    } while (commande.at(0) != QUIT);
}

void GameManager::gameOver() {
    switch (field->isGameOver()) {
        case -1:
            field->reset();
            cout << "Les vampires ont tués tous les humains :(" << endl;
            break;
        case 1:
            field->reset();
            cout << "Buffy a vaincu les vampires fastoche!" << endl;
            break;
        default:
            break;
    }

}
