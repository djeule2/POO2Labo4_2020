//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Humanoid.h"

Humanoid::Humanoid(char name, int x, int y) : _name(name), _xPosition(x), _yPosition(y), action(nullptr) {
}

char Humanoid::getName() const {
    return _name;
}

int Humanoid::getxPosition() const {
    return _xPosition;
}

int Humanoid::getyPosition() const {
    return _yPosition;
}

void Humanoid::setPosition(int x, int y) {
    _xPosition = x;
    _yPosition = y;
}

bool Humanoid::isAlive() {
    return _isAlive;
}

void Humanoid::kill() {
    _isAlive = false;
}
