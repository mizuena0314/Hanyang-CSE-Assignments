#include "number.h"

int Square::getSquare(){ // Implemented to return the square of the number specified by setNumber()
        return getNumber()*getNumber();
}

int Cube::getCube(){ // Implemented to return the cube of the number specified by setNumber()
        return getSquare()*getNumber();
}
