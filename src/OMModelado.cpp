//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <cmath> //para las operaciones de rotación
#include "OMModelado.h"

///CONSTRUCTOR
OMModelado::OMModelado(){}
///DESTRUCTOR
OMModelado::~OMModelado(){}

///TRASLACION
//Devuelve la matriz de traslacion (OPuntox)
OPuntox OMModelado::traslation(float tx,float ty){

///                  [ 1 ][ 0 ][-tx]
///   Traslación =   [ 0 ][ 1 ][-ty]
///                  [ 0 ][ 0 ][ 1 ]

    //Matriz de rotacion (de retorno)
    OPuntox res = OPuntox(3,3);
    //Diagonal de unos
    for(int i = 0; i < 3; i++){
        for(int j = 0;j < 3;j++){
            if(i == j){
                res.setComp(i,j,1);
            }
        }
    }
    //Asignacion de componentes
    res.setComp(0,2,-1*tx);
    res.setComp(1,2,-1*ty);
    return res;
}

///ROTACION
//Devuelve la matriz de rotacion
OPuntox OMModelado::rotation(float theta, OPuntox mod){

///                [Cos(θ)][-Sen(θ)][   0  ]
///   Rotación =   [Sen(θ)][ Cos(θ)][   0  ]
///                [   0  ][   0   ][   1  ]

    //Matriz de rotacion
    OPuntox rota = OPuntox(3,3);
    //Matriz auxiliar (de retorno)
    OPuntox res = OPuntox(3,3);
    //Asignacion de componentes
    rota.setComp(0,0,cos(theta));
    rota.setComp(0,1,-1*sin(theta));
    rota.setComp(1,0,sin(theta));
    rota.setComp(1,1,cos(theta));
    rota.setComp(2,2,1);
    //Multiplicacion de matrices
    res = res.multMatriz(mod,rota);
    return res;
}

///ESCALAMIENTO
//Devuelve la matriz de escalamiento(OPuntox)
//Si sx y sy son iguales a 1 la figura no muestra escalamiento alguno
OPuntox OMModelado::scaling(float sx,float sy,OPuntox mod){

///                [sx][ 0][ 0]
///   Escalado =   [ 0][sy][ 0]
///                [ 0][ 0][ 1]

    //Matriz de escalamiento
    OPuntox scal = OPuntox(3,3);
    //Matriz auxiliar (de retorno)
    OPuntox res = OPuntox(3,3);
    //Asignacion de componentes
    scal.setComp(0,0,sx);
    scal.setComp(1,1,sy);
    scal.setComp(2,2,1);
    //Multiplicacion de matrices
    res = res.multMatriz(mod,scal);
    return res;
}

///TRASLACION INVERSA (REGRESA POSICION ORIGINAL)
//Devuelve la matriz de traslacion inversa (OPuntox)
OPuntox OMModelado::traslationInversa(float tx,float ty,OPuntox mod){

///                [ 1][ 0][tx]
///   Tras Inv =   [ 0][ 1][ty]
///                [ 0][ 0][ 1]

    //Matriz de traslacion inversa
    OPuntox trasInv = OPuntox(3,3);
    //Matriz auxiliar (de retorno)
    OPuntox res = OPuntox(3,3);
    //Asignacion de componentes
    trasInv.setComp(0,0,1);
    trasInv.setComp(1,1,1);
    trasInv.setComp(2,2,1);
    trasInv.setComp(0,2,tx);
    trasInv.setComp(1,2,ty);
    //Multiplicacion de matrices
    res = res.multMatriz(mod,trasInv);
    return res;
}
