//
// Created by claudealves on 03.06.20.
//

#include "Vamp.h"
#include "Utils.h"
#include "Vampire.h"
#include "Humanoid.h"

void Vamp::execute(Field &field) {
    if(Utils::getRandomNumber(0, 1) == 1) {
        field.addHumanoid(new Vampire(target->getxPosition(), target->getyPosition()));
    }
    target->kill();
}

Vamp::Vamp(Humanoid *target) : Action(target) {
}
