//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_HUMANOID_H
#define POO2LABO4_2020_HUMANOID_H

#include "Action.h"

class Field;

class Humanoid {
private:
    char _name;
    int _xPosition;
    int _yPosition;
    bool _isAlive = true;
    std::pair<int, int> _destination;
    Action *action;
public:
    Humanoid(char name, int x, int y);

    virtual char getName() const;

    virtual int getxPosition() const;

    virtual int getyPosition() const;

    virtual void setxPosition(int x);

    virtual void setyPosition(int y);

    virtual bool isAlive();

    virtual void setAction(Field &field) = 0;

    virtual void executeAction(Field &field) = 0;

    virtual void kill();

};


#endif //POO2LABO4_2020_HUMANOID_H
