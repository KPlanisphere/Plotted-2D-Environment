//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#ifndef CONTROLV_H
#define CONTROLV_H
#include "OMatrices.h"
#include "OPuntox.h"
#include "OMModelado.h"

class ControlV{
    public:
        ControlV(); //Constructor
        ~ControlV(); //Destructor
        //SETTER
        void setDT(float,float);
        void setDS(float,float);
        void setDtheta(float);
        void setTrasInvStatus(int);
        //GETTER
        float getDtx();
        float getDty();
        float getDsx();
        float getDsy();
        float getDtheta();
        int getTrasInvStatus();
    private:
        float Dtx,Dty,Dsx,Dsy,Dtheta;
        int on_off;
};
#endif // CONTROLV_H
