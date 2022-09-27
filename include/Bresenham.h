//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#ifndef BRESENHAM_H
#define BRESENHAM_H

#include "OLinea.h"

class Bresenham{
    public:
        Bresenham(); //Constructor
        virtual ~Bresenham(); //Destructor
        void Bresenbased(OLinea); //x0,y0,x1,y1
};

#endif // BRESENHAM_H
