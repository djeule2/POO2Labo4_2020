//
// Created by Lenovo T50s on 14.05.2020.
//

#include <cmath>
#include "Field.h"

Field::Field(){}


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
            it = _humanoids.erase(it); // suppression de l’élément dans la liste
            delete *it; // destruction de l’humanoide référencé
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

Humanoid* Field::findNearestHumanoid(Humanoid* humanoid){
    double shortdistance=distanceBetweenHumanoid(humanoid, _humanoids.front());
    double distance;
    Humanoid* tempHumanoid ;

    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); ++it ){
        distance = distanceBetweenHumanoid(humanoid, *it);
        if(distance<=shortdistance) {
            shortdistance = distance;
            tempHumanoid = *it;
        }

    }
    return tempHumanoid;
}

Humanoid* Field::findNearestVampire(Humanoid *humanoid) {
    list<Humanoid*>::iterator it = _humanoids.begin();
    Humanoid* closestVamp = *it;
    for (; it != _humanoids.end(); ++it ){
        if((*it)->getName() == 'v'
            && distanceBetweenHumanoid(humanoid, *it) < distanceBetweenHumanoid(humanoid, closestVamp)) {
            closestVamp = *it;
        }
    }
    return closestVamp;
}

Humanoid* Field::findClosestHuman(Humanoid *humanoid) {
    list<Humanoid*>::iterator it = _humanoids.begin();
    Humanoid* closestHuman = *it;
    for (; it != _humanoids.end(); ++it ){
        if((*it)->getName() == 'h'
           && distanceBetweenHumanoid(humanoid, *it) < distanceBetweenHumanoid(humanoid, closestHuman)) {
            closestHuman = *it;
        }
    }
    return closestHuman;
}
