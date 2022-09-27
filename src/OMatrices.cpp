//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>

#include "OMatrices.h"
///Constructores
OMatrices::OMatrices(){
    val = 0.0;
}
OMatrices::OMatrices(float x){
    val = x;
}
///DESTRUCTOR
OMatrices::~OMatrices(){}

//Getter
float OMatrices::getVal(){
    return val;
}
//Setter
void OMatrices::setVal(float x){
    val = x;
}
