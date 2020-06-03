//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Vampire.h"
#include "Wait.h"
#include "Vamp.h"
#include <cmath>

Vampire::Vampire(int x, int y) : Humanoid('v', x, y) {}

void Vampire::setAction(Field &field) {
    Humanoid *target = field.findClosestHuman(this);
    if (!action) {
        delete action;
    }
    if (!target) {
        action = new Wait(this);
    } else if (field.distanceBetweenHumanoid(this, target) > sqrt(2)) {
        action = moveToSomeone(target);
    } else {
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


