//
// Created by Lenovo T50s on 03.06.2020.
//

#include "GameManager.h"
#include "Stats.h"

GameManager::GameManager() {}

GameManager::~GameManager(){
    delete field;
    delete display;
}

void GameManager::initializeGame() {
    readControl("Largeur DisplayField", DisplayField::BORNE_INF, DisplayField::BORNE_SUP, width);
    readControl("Hauteur DisplayField", DisplayField::BORNE_INF, DisplayField::BORNE_SUP, height);
    readControl("Nombres humains", 0, width * height - 1, human);
    readControl("Nombres Vampires", 0, width * height - human - 1, vambire);
    field = new Field(width, height, vambire, human);
}

void GameManager::updateDisplay() {
    list<Humanoid*>humanoids = field->getListHumanoid();
    display->initialize();
    for (list<Humanoid*>::iterator it = humanoids.begin();
         it != humanoids.end(); ++it) {
         display->update(**it);
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
            field->nexTurn();
            updateDisplay();
            display->display();
            break;
        case STATTISTIQUE:
            cout << Stats::produceStats(10000, field) << endl;
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
        cout << turn << ">";
        showMenu();
        getline (std::cin, commande);

        handleCommand(commande);

    } while (commande.at(0) != QUIT);
}
