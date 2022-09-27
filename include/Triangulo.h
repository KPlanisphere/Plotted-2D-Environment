//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <vector>
#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Bresenham.h"
#include "ControlV.h"

class Triangulo{
    public:
        Triangulo(); //Constructor
        ~Triangulo(); //Destructor
        void drawTriangulo(ControlV);
};
#endif // TRIANGULO_H
