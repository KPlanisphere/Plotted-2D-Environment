//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#ifndef MODELADOC_H
#define MODELADOC_H
#include "OMatrices.h"
#include "OPuntox.h"
#include "OMModelado.h"

class ModeladoC{
    public:
        ModeladoC(); //Constructor
        virtual ~ModeladoC(); //Destructor
        OPuntox modeladoCreation(float,float,float,float,float,int); //Creacion de matriz de modelado
};
#endif // MODELADOC_H
