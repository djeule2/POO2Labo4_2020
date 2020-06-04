//
// Created by claudealves on 04.06.20.
//

#include <sstream>
#include "Stats.h"

string Stats::produceStats(size_t simSize, Field *field) {
    size_t numberOfVictorySims = 0;
    std::ostringstream stream;
    field->reset();
    for(size_t i = 0; i < simSize; ++i) {
        field->reset();
        while(field->isGameOver() == 0) {
            field->nexTurn();
        }
        if(field->isGameOver() == 1) {
            numberOfVictorySims++;
        }
    }
    stream << (numberOfVictorySims/simSize*100);
    return stream.str();
}
