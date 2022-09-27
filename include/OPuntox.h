//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <vector>

#ifndef OPUNTOX_H
#define OPUNTOX_H

#include "OMatrices.h"
#include "RPunto.h"

class OPuntox{
    public:
        OPuntox(int,int); //Constructor
        virtual ~OPuntox(); //Desctructor
        OPuntox multMatriz(OPuntox,OPuntox); //Multiplica dos matrices de 3x3
        OPuntox multMatrizPoints(RPunto,OPuntox); //Multiplica 3x3 con 3x1 (puntos de entrada)
        //getter
        OMatrices getComp(int,int);
        int getFilNum();
        int getColNum();
        //setter
        void setComp(int,int,OMatrices);
    private:
        int n,m; //n = filas, m = columnas
        std::vector< std::vector<OMatrices> > matriz; //definicion de matriz (con vector de vectores)
};

#endif // OPUNTOX_H
