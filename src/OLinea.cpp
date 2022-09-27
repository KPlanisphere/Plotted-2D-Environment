//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include "OLinea.h"

///CONSTRUCTOR
OLinea::OLinea(){}

///DESTRUCTOR
OLinea::~OLinea(){}

///DIVERSOS
//SETLINEA
//Determinamos el inicio y fin de una linea
void OLinea::setLinea(OMatrices x1,OMatrices y1,OMatrices x2,OMatrices y2){
    //Asignacion de valores...
    //Para punto 1 (p1)
    p1.setX(x1);
    p1.setY(y1);
    //Para punto 2 (p2)
    p2.setX(x2);
    p2.setY(y2);
}
///GETTERS PUNTOS
//Punto 1
RPunto OLinea::getP1(){
    return p1;
}
//Punto 2
RPunto OLinea::getP2(){
    return p2;
}
