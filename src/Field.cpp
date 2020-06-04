//
// Created by Lenovo T50s on 14.05.2020.
//

#include <cmath>
#include "Field.h"
#include "Utils.h"

Field::Field(int width, int height) : width(width), height(height){}


int Field::nexTurn(){
    cout << "nextTurn setActions" << endl;
    // Déterminer les prochaines actions
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        (*it)->setAction(*this);
    }
    cout << "nextTurn executeActions" << endl;
    // Executer les actions
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        (*it)->executeAction(*this);
    }
    cout << "nextTurn kill things" << endl;
    // Enlever les humanoides tués
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); ) {
        cout << (*it)->isAlive() << endl;
        if (!(*it)->isAlive()) {
            cout << "nextTurn suppression du pointeur" << endl;
            delete *it; // destruction de l’humanoide référencé
            cout << "nextTurn suppression de la liste" << endl;
            it = _humanoids.erase(it); // suppression de l’élément dans la liste
        } else
            ++it;
    }

    cout << "endTurn" << endl;
    return turn++;
}

void Field::addHumanoid(Humanoid* humanoid){
    _humanoids.push_back(humanoid);
}

list <Humanoid*> Field::getListHumanoid(){

    return _humanoids;

}

bool Field::content (Humanoid* humanoid){
    bool result = false;
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); ++it ){
        if(*it == humanoid){
            result = true;
        }
    }
    return result;

}

double Field::distanceBetweenHumanoid( const Humanoid* humanoidfirst, const Humanoid* humanoidsecond) {
    return sqrt(pow((humanoidfirst->getxPosition()-humanoidsecond->getxPosition()), 2)+
            pow((humanoidfirst->getyPosition()-humanoidsecond->getyPosition()),2 ));
}

Humanoid* Field::findClosestBeing(Humanoid *humanoid, char name) {
    Humanoid* closestHuman = nullptr;
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); ++it ){
        if(!closestHuman) {
            if((*it)->getName() == name) {
                closestHuman = *it;
            }
        } else {
            if((*it)->getName() == name
               && distanceBetweenHumanoid(humanoid, *it) < distanceBetweenHumanoid(humanoid, closestHuman)) {
                closestHuman = *it;
            }
        }
    }
    cout << " fin boucle for" << endl;
    return closestHuman;
}

void Field::reset() {
    for(list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++) {
        (*it)->setPosition(Utils::getRandomNumber(0, width), Utils::getRandomNumber(0, height));
    }

}

int Field::getWidth() {
    return width;
}

int Field::getHeight() {
    return height;
}
