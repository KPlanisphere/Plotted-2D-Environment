//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <vector>
#ifndef CIRCULO_H
#define CIRCULO_H
#include "Bresenham.h"
#include "ControlV.h"

class Circulo{
    public:
        Circulo(); //Constructor
        ~Circulo(); //Destructor
        void drawCirculo(ControlV);
};
#endif // CIRCULO_H
