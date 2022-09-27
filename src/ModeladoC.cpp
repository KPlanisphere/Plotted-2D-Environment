//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include "ModeladoC.h"

///CONSTRUCTOR
ModeladoC::ModeladoC(){}
///DESTRUCTOR
ModeladoC::~ModeladoC(){}

///CREACION MATRIZ DE MODELADO
//Matriz donde se guardara el resultado de la multiplicacion de todas las matrices de [T'OPT]
OPuntox ModeladoC::modeladoCreation(float tx,float ty,float sx,float sy,float theta,int on_off){
    //Llamado a operadores de modelado
    OMModelado op = OMModelado();
    //Matriz de modelado (de retorno)
    OPuntox model = OPuntox(3,3);

    ///[T'OPT]
    // T
    model = op.traslation(tx,ty);
    // OP
    model = op.rotation(theta,model);
    model = op.scaling(sx,sy,model);
    // T'
    if(on_off == 1){
      model = op.traslationInversa(tx,ty,model);
    }
    return model;
}

