//
// Created by Lenovo T50s on 14.05.2020.
//

#ifndef POO2LABO4_2020_HUMANOID_H
#define POO2LABO4_2020_HUMANOID_H


#include "Field.h"

class Humanoid {
private:
    char  _name;
    int _xPosition;
    int _yPosition;
public:
    Humanoid(char name, int x, int y);
    virtual char getName()const = 0;
    virtual int getxPosition()const;
    virtual int getyPosition()const;
    virtual void setxPosition(int x);
    virtual void setyPosition(int y);
    virtual void setAction(Field& field)=0;
    virtual void executeAction(Field& field)=0;
    virtual bool bool isAlive()=0;


};


#endif //POO2LABO4_2020_HUMANOID_H
