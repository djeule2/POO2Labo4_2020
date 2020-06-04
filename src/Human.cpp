//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Human.h"
#include "Utils.h"
#include "Move.h"

using namespace std;

Human::Human(int x, int y) : Humanoid('h', x, y) {
}

void Human::setAction(Field &field) {
    if (!action) {
        delete action;
    }
    action = moveRandom(field.getWidth(), field.getHeight());
}

void Human::executeAction(Field &field) {
    if(action) {
        action->execute(field);
    }
}


