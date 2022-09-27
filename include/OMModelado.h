//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <vector>
#ifndef OMMODELADO_H
#define OMMODELADO_H
#include "OMatrices.h"
#include "OPuntox.h"

class OMModelado{
    public:
        OMModelado(); //Constructor
        virtual ~OMModelado(); //Destructor
        //Diversos ([T'OPT])
        OPuntox traslation(float,float);
        OPuntox rotation(float, OPuntox);
        OPuntox scaling(float,float,OPuntox);
        OPuntox traslationInversa(float,float,OPuntox);
};
#endif // OMMODELADO_H
