/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Field.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe Field.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include <cmath>
#include "Field.h"
#include "Utils.h"
#include "Human.h"
#include "Vampire.h"
#include "Buffy.h"

Field::Field(int width, int height, int vampires, int humans) : width(width), height(height), vampires(vampires),
                                                                humans(humans) {}


int Field::nexTurn() {
    // Déterminer les prochaines actions
    for (list<Humanoid *>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        (*it)->setAction(*this);
    }
    // Executer les actions
    for (list<Humanoid *>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        (*it)->executeAction(*this);
    }
    // Enlever les humanoides tués
    for (list<Humanoid *>::iterator it = _humanoids.begin(); it != _humanoids.end();) {
        if (!(*it)->isAlive()) {
            delete *it; // destruction de l’humanoide référencé
            it = _humanoids.erase(it); // suppression de l’élément dans la liste
        } else
            ++it;
    }
    return turn++;
}

void Field::addHumanoid(Humanoid *humanoid) {
    _humanoids.push_back(humanoid);
}

list<Humanoid *> Field::getListHumanoid() {
    return _humanoids;
}

double Field::distanceBetweenHumanoid(const Humanoid *humanoidfirst, const Humanoid *humanoidsecond) {
    return sqrt(pow((humanoidfirst->getxPosition() - humanoidsecond->getxPosition()), 2) +
                pow((humanoidfirst->getyPosition() - humanoidsecond->getyPosition()), 2));
}

Humanoid *Field::findClosestBeing(Humanoid *humanoid, char name) {
    Humanoid *closestHuman = nullptr;
    for (list<Humanoid *>::iterator it = _humanoids.begin(); it != _humanoids.end(); ++it) {
        if (!closestHuman) {
            if ((*it)->getName() == name) {
                closestHuman = *it;
            }
        } else {
            if ((*it)->getName() == name
                && distanceBetweenHumanoid(humanoid, *it) < distanceBetweenHumanoid(humanoid, closestHuman)) {
                closestHuman = *it;
            }
        }
    }
    return closestHuman;
}

void Field::reset() {
    clear();
    createHumanoids(vampires, humans);
    for (list<Humanoid *>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        (*it)->setPosition(Utils::getRandomNumber(0, width), Utils::getRandomNumber(0, height));
    }

}

int Field::getWidth() {
    return width;
}

int Field::getHeight() {
    return height;
}

int Field::isGameOver() {
    bool isThereAVamp = false;
    bool isThereAHuman = false;
    for (list<Humanoid *>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        if ((*it)->getName() == 'h') {
            isThereAHuman = true;
        } else if (((*it)->getName() == 'v')) {
            isThereAVamp = true;
        }
    }
    return isThereAVamp ? (isThereAHuman ? 0 : -1) : isThereAHuman ? 1 : -1;
}

void Field::clear() {
    _humanoids.clear();
}

void Field::createHumanoids(int nbreVampire, int nbrHuman) {
    for (int i = 0; i < nbrHuman; i++) {
        //creation de Human
        addHumanoid(new Human(Utils::getRandomNumber(0, width - 1),
                              Utils::getRandomNumber(0, height - 1)));
    }
    for (int j = 0; j < nbreVampire; j++) {
        //creation Vampire
        addHumanoid(new Vampire(Utils::getRandomNumber(0, width - 1),
                                Utils::getRandomNumber(0, height - 1)));
    }
    //creation du Buffy
    addHumanoid(new Buffy(Utils::getRandomNumber(0, width - 1),
                          Utils::getRandomNumber(0, height - 1)));
}
