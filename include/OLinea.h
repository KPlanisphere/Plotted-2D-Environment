//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#ifndef OLINEA_H
#define OLINEA_H
#include "RPunto.h"

class OLinea{
    public:
        OLinea(); //Constructor
        ~OLinea(); //Destructor
        void setLinea(OMatrices,OMatrices,OMatrices,OMatrices);
        RPunto getP1();
        RPunto getP2();
    private:
        RPunto p1,p2;
};
#endif // OLINEA_H
