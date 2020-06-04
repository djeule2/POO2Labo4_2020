//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Buffy.h"
#include "Kill.h"
#include <cmath>

Buffy::Buffy(int x, int y) : Humanoid('B', x, y), secondAction(nullptr) {
}

void Buffy::setAction(Field &field) {
    cout << "Buffy setAction" << endl;
    Humanoid* target = field.findNearestVampire(this);
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
        cout << "Buffy buffy se déplace vers quelqu'un" << endl;
        action = moveToSomeone(target);
        cout << "Buffy buffy se déplace vers quelqu'un" << endl;
        secondAction = moveToSomeone(target);
    } else {
        cout << "Buffy buffy se déplace vers quelqu'un" << endl;
        action = moveToSomeone(target);
        cout << "Buffy buffy tue" << endl;
        secondAction = new Kill(target);
    }
    //get the nearest vampire
    //if he's further than 2sqrt(2) chase after him
    //else if closer than 2sqrt(2) Kill him
    //else (game supposed to be finished)
}

void Buffy::executeAction(Field &field) {
    cout << "Buffy executeAction" << endl;
    action->execute(field);
    // Buffy est très forte elle a deux actions
    secondAction->execute(field);
}
