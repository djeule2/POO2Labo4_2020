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
    action = new Move(this,
                      _xPosition + Utils::getRandomNumber(-1, 1),
                      _yPosition + Utils::getRandomNumber(-1, 1));
}

void Human::executeAction(Field &field) {
    action->execute(field);
}


