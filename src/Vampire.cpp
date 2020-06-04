//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Vampire.h"
#include "Wait.h"
#include "Vamp.h"
#include <cmath>

Vampire::Vampire(int x, int y) : Humanoid('v', x, y) {}

void Vampire::setAction(Field &field) {
    cout << "Vampire setAction" << " coordonnees : " << _xPosition << " " << _yPosition <<  endl;
    Humanoid *target = field.findClosestBeing(this, 'h');
    if (!action) {
        delete action;
    }
    if (!target) {
        cout << "Vampire attend" << endl;
        action = new Wait(this);
    } else if (field.distanceBetweenHumanoid(this, target) > sqrt(2)) {
        cout << "Vampire se déplace vers quelqu'un" << endl;
        action = moveToSomeone(target);
    } else {
        cout << "Vampire vamp quelqu'un" << endl;
        action = new Vamp(target);
    }
    //get the nearest human
    //(sleep waiting buffy kills him)
    //if he's further than sqrt(2) -> chase him
    //else if closer than sqrt(2) try to Vamp the nearest human
}

void Vampire::executeAction(Field &field) {
    action->execute(field);
}


