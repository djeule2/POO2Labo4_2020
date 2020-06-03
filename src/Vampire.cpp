//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Vampire.h"

Vampire::Vampire(int x, int y): Humanoid('v', x, y){
}
void Vampire::setAction(Field& field){
    //get the nearest human
    //if he's further than sqrt(2) -> chase him
    //else if closer than sqrt(2) try to Vamp the nearest human
    //else (sleep waiting buffy kills him)
}
void Vampire::executeAction(Field& field){

}


