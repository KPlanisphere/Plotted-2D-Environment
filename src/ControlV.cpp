//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include "ModeladoC.h"
#include "ControlV.h"

///CONSTRUCTOR
ControlV::ControlV(){
    Dtx = Dty = 0;
    Dsx = Dsy = 0;
    Dtheta = 0;
    on_off = 0;
}

///DESTRUCTOR
ControlV::~ControlV(){}

///SETTERS
void ControlV::setDT(float in1,float in2){
    Dtx = in1;
    Dty = in2;
}

void ControlV::setDS(float in1,float in2){
    Dsx = in1;
    Dsy = in2;
}

void ControlV::setDtheta(float in){
    Dtheta = in;
}

void ControlV::setTrasInvStatus(int in){
    on_off = in;
}

///GETTERS
float ControlV::getDtx(){
    return Dtx;
}
float ControlV::getDty(){
    return Dty;
}
float ControlV::getDsx(){
    return Dsx;
}
float ControlV::getDsy(){
    return Dsy;
}
float ControlV::getDtheta(){
    return Dtheta;
}
int ControlV::getTrasInvStatus(){
    return on_off;
}
