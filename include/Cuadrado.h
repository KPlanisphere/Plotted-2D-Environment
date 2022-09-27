//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <vector>
#ifndef CUADRADO_H
#define CUADRADO_H
#include "Bresenham.h"
#include "ControlV.h"
class Cuadrado{
    public:
        Cuadrado(); //Constructor
        ~Cuadrado(); //Destructor
        //Figuras
        void drawCuadrado(ControlV CV);
};
#endif // CUADRADO_H
