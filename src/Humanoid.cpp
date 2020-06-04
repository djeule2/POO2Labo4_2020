/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo4 -Buffy
 Fichier     : Humanoid.cpp
 Auteur(s)   : Alves Claude-André, Olivier Djeuzlezeck
 Date        : 03.06.2020

 But         : Fichier d'implémentation de la classe Humanoid.

 Remarque(s) : -

 Compilateur : gcc 7.4.0
 -----------------------------------------------------------------------------------
 */
#include "Humanoid.h"
#include "Utils.h"
#include "Move.h"

Humanoid::Humanoid(char name, int x, int y) : name(name), xPosition(x), yPosition(y), action(nullptr), dead(true) {
}

char Humanoid::getName() const {
    return name;
}

int Humanoid::getxPosition() const {
    return xPosition;
}

int Humanoid::getyPosition() const {
    return yPosition;
}

void Humanoid::setPosition(int x, int y) {
    xPosition = x;
    yPosition = y;
}

bool Humanoid::isAlive() {
    return dead;
}

void Humanoid::kill() {
    dead = false;
}

Action *Humanoid::moveToSomeone(Humanoid *target) {
    int xMove = this->xPosition > target->getxPosition() ? -1 : this->xPosition == target->getxPosition() ? 0 : 1;
    int yMove = this->yPosition > target->getyPosition() ? -1 : this->yPosition == target->getyPosition() ? 0 : 1;
    return new Move(this, xPosition + xMove, yPosition + yMove);
}

Action *Humanoid::moveRandom(int width, int height) {
    int xMove = Utils::getRandomNumber(-1, 1);
    int yMove = Utils::getRandomNumber(-1, 1);
    xMove = xPosition + xMove >= width || xPosition + xMove < 0 ? xPosition - xMove : xPosition + xMove;
    yMove = yPosition + yMove >= height || yPosition + yMove < 0 ? yPosition - yMove : yPosition + yMove;
    return new Move(this, xMove, yMove);
}
