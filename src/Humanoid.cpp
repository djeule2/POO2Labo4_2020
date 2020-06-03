//
// Created by Lenovo T50s on 14.05.2020.
//

#include "Humanoid.h"
#include "Utils.h"
#include "Move.h"

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

Action* Humanoid::moveToSomeone(Humanoid *target) {
    int xMove = this->_xPosition > target->getxPosition() ? 1 : this->_xPosition == target->getxPosition() ? 0 : -1;
    int yMove = this->_yPosition > target->getyPosition() ? 1 : this->_yPosition == target->getyPosition() ? 0 : -1;
    return new Move(this, _xPosition + xMove, _yPosition + yMove);
}

Action *Humanoid::moveRandom() {
    return new Move(this,
                    _xPosition + Utils::getRandomNumber(-1, 1),
                    _yPosition + Utils::getRandomNumber(-1, 1));
}
