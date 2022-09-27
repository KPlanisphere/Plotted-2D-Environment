//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <vector>
#ifndef FIGURAS_H
#define FIGURAS_H
#include "Bresenham.h"
#include "ControlV.h"

class Figuras{
    public:
        Figuras(); //Constructor
        ~Figuras(); //Destructor
        //FIGURAS
        void drawAmongUsMuerto(ControlV,float,float,float);
        void drawAmongUs(ControlV,float,float,float);
        void drawVaso(ControlV);
        void drawCaja(ControlV);
};
#endif // FIGURAS_H
