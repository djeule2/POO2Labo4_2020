//
// Created by Lenovo T50s on 14.05.2020.
//

#include <cmath>
#include "Field.h"
#include "Buffy.h"
#include "Human.h"
#include "Vampire.h"

Field::Field(){}


int Field::nexTurn(){
    // Déterminer les prochaines actions
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++)
        (*it)->setAction(*this);
    // Executer les actions
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); it++)
        (*it)->executeAction(*this);
    // Enlever les humanoides tués
    for (list<Humanoid*>::iterator it = _humanoids.begin(); it != _humanoids.end(); )
        if (!(*it)->isAlive()) {
            it = _humanoids.erase(it); // suppression de l’élément dans la liste
            delete *it; // destruction de l’humanoide référencé
        }
        else
            ++it;
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
    for (_List_iterator<Humanoid *> it = _humanoids.begin(); it != _humanoids.end(); ++it ){
        if(*it == humanoid){
            result = true;
        }
    }
    return result;

}

double Field::distanceBetweenHumanoid( const Humanoid* humanoidfirst, const Humanoid* humanoidsecond) {
    double result;
    result = sqrt(pow((humanoidfirst->getxPosition()-humanoidsecond->getxPosition()), 2)+
            pow((humanoidfirst->getyPosition()-humanoidsecond->getyPosition()),2 ));
    return result;
}

Humanoid* Field::findNearestHumanoid(Humanoid* humanoid){
    double shortdistance=distanceBetweenHumanoid(humanoid, _humanoids.front());
    double distance;
    Humanoid* tempHumanoid ;

    for (_List_iterator<Humanoid *> it = _humanoids.begin(); it != _humanoids.end(); ++it ){
        distance = distanceBetweenHumanoid(humanoid, *it);
        if(distance<=shortdistance) {
            shortdistance = distance;
            tempHumanoid = *it;
        }

    }
    return tempHumanoid;
}

Humanoid* Field::findNearestVampire(Humanoid *humanoid) {
    int first=0 ;
    double shortdistance;
    double distance;
    Humanoid* tempHumanoid = nullptr ;

    for (_List_iterator<Humanoid *> it = _humanoids.begin(); it != _humanoids.end(); ++it ){
        if((*it)->getName()=='v') {
            if(first==0){
                shortdistance=distanceBetweenHumanoid(humanoid, *it);
                tempHumanoid = *it;
                first++;
            } else if(distance<=shortdistance) {
                shortdistance = distance;
                tempHumanoid = *it;
            }
        }
    }
    return tempHumanoid;
}

Humanoid* Field::findClosestHuman(Humanoid *humanoid) {
    int first=0 ;
    double shortdistance;
    double distance;
    Humanoid* tempHumanoid = nullptr ;

    for (_List_iterator<Humanoid *> it = _humanoids.begin(); it != _humanoids.end(); ++it ){
        if((*it)->getName()=='h') {
            if(first==0){
                shortdistance=distanceBetweenHumanoid(humanoid, *it);
                tempHumanoid = *it;
                first++;
            } else if(distance<=shortdistance) {
                    shortdistance = distance;
                    tempHumanoid = *it;
                }
            }
        }
    return tempHumanoid;
}
