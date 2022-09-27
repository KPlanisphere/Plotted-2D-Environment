//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>

#include "RPunto.h"

///CONSTRUCTOR
RPunto::RPunto(){
    x = y = 0;
}

///DESTRUCTOR
RPunto::~RPunto(){}

///SETTERS
void RPunto::setXY(OMatrices in,OMatrices in2){
    x = in;
    y = in2;
}
void RPunto::setX(OMatrices in){
    x = in;
}

void RPunto::setY(OMatrices in){
    y = in;
}

///GETTERS
OMatrices RPunto::getX(){
    return x;
}

OMatrices RPunto::getY(){
    return y;
}
