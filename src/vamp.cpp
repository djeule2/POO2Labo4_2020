//
// Created by claudealves on 03.06.20.
//

#include "vamp.h"
#include "utils.h"
#include "Vampire.h"

void vamp::execute(Field &field) {
    if(utils::getRandomNumber(0, 1) == 1) {
        field.addHumanoid((Humanoid*)new Vampire(target->getxPosition(), target->getyPosition()));
    }
    target->kill();
}

vamp::vamp(Humanoid *target) : target(target) {
}
