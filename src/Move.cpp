//
// Created by claudealves on 03.06.20.
//

#include "Move.h"

Move::Move(Humanoid* target, int xDestination, int yDestination) : Action(target),
                                                                   xDestination(xDestination),
                                                                   yDestination(yDestination) {
}

void Move::execute(Field &field) {
    target->setPosition(xDestination, yDestination);
}
