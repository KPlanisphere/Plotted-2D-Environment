//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <vector>

#ifndef KEYGLAZZ_H
#define KEYGLAZZ_H

#include "Bresenham.h"
#include "ControlV.h"

class KeyGlazz{
    public:
        KeyGlazz(); //Constructor
        ~KeyGlazz(); //Destructor
        void drawKeyGlazz(ControlV);
};

#endif // KEYGLAZZ_H
