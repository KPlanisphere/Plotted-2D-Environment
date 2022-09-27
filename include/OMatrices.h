//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>

#ifndef OMATRICES_H
#define OMATRICES_H

class OMatrices{
    public:
        //Constructores
        OMatrices();
        OMatrices(float x);
        virtual ~OMatrices(); //Destructor
        //Getter
        float getVal();
        //Setter
        void setVal(float);
    private:
        float val;
};

#endif // OMATRICES_H
