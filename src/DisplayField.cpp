//
// Created by Lenovo T50s on 14.05.2020.
//

#include <iomanip>
#include <iostream>
#include "DisplayField.h"

using namespace std;

DisplayField::DisplayField(int width, int height) : _width(width), _height(height) {
    field = vector<vector<char>>(width, vector<char>(height));
    this->initialize();
}

void DisplayField::initialize() {
    for (int row = 0; row < _height; row++) {
        for (int column = 0; column < _width; column++) {
            field[row][column] = ' ';
        }
    }
}

void DisplayField::display() {
    cout << '+' << setfill('-') << setw(_width + 1) << "+" << endl;
    for (int row = 0; row < _height; row++) {
        cout << ":";
        for (int column = 0; column < _width; column++) {
            cout << field[row][column];
        }
        cout << ":" << endl;
    }
    cout << '+' << setfill('-') << setw(_width + 1) << "+" << endl;
}

void DisplayField::update(Humanoid &humanoid) {
    cout<<humanoid.getxPosition()<<"--"<<humanoid.getyPosition()<<endl;
   field[humanoid.getxPosition()][humanoid.getyPosition()] = humanoid.getName();

}
