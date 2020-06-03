//
// Created by claudealves on 03.06.20.
//

#include "Kill.h"

Kill::Kill(Humanoid *target) : Action(target) {

}

void Kill::execute(Field &field) {
    target->kill();
}
