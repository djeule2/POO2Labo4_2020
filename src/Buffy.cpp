//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Buffy.h"
#include "Kill.h"
#include <cmath>

Buffy::Buffy(int x, int y) : Humanoid('B', x, y), secondAction(nullptr) {
}

void Buffy::setAction(Field &field) {
    cout << "buffy en vie? : " << _isAlive << endl;
    cout << "Buffy setAction" << " coordonnees : " << _xPosition << " " << _yPosition << endl;
    Humanoid* target = field.findClosestBeing(this, 'v');
    if(!action) {
        delete action;
    }
    if(!secondAction) {
        delete secondAction;
    }

    if(!target) {
        cout << "Buffy bouge aleatoirement" << endl;
        action = moveRandom();
    } else if(field.distanceBetweenHumanoid(this, target) > sqrt(8)) {
        cout << "Buffy se déplace vers quelqu'un" << endl;
        action = moveToSomeone(target);
        cout << "Buffy se déplace vers quelqu'un" << endl;
        secondAction = moveToSomeone(target);
    } else {
        cout << "Buffy se déplace vers quelqu'un" << endl;
        action = moveToSomeone(target);
        cout << "Buffy tue" << endl;
        secondAction = new Kill(target);
    }
    //get the nearest vampire
    //if he's further than 2sqrt(2) chase after him
    //else if closer than 2sqrt(2) Kill him
    //else (game supposed to be finished)
}

void Buffy::executeAction(Field &field) {
    action->execute(field);
    // Buffy est très forte elle a deux actions
    secondAction->execute(field);
}
