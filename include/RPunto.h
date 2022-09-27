//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>

#ifndef RPUNTO_H
#define RPUNTO_H

#include "OMatrices.h"

class RPunto{
    public:
        RPunto(); //Contructor
        ~RPunto(); //Destructor
        //Setter
        void setXY(OMatrices,OMatrices);
        void setX(OMatrices);
        void setY(OMatrices);
        //Getter
        OMatrices getX();
        OMatrices getY();

    private:
        OMatrices x,y;
};

#endif // RPUNTO_H
