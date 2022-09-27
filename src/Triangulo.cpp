//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iomanip>
#include <stdlib.h>
#include <vector>

#include "OMatrices.h"
#include "OPuntox.h"
#include "OMModelado.h"
#include "ModeladoC.h"
#include "Bresenham.h"
#include "ControlV.h"
#include "Triangulo.h"

///CONSTRUCTOR
Triangulo::Triangulo(){}
///DESTRUCTOR
Triangulo::~Triangulo(){}

///DIBUJAR POLIGONO: TRIANGULO
//void Triangulo::drawTriangulo(float Dtx,float Dty,float Dsx,float Dsy,float Dtheta){
void Triangulo::drawTriangulo(ControlV CV){

    //Puntos a usar
    RPunto p[3];
    p[0].setX(-20); p[0].setY(-20);
    p[1].setX(20); p[1].setY(-20);
    p[2].setX(0); p[2].setY(20);

    //Linea bresenham
    OLinea arista;
    //Variables donde se guardaran los puntos
    OMatrices TP1,TP2,TP3,TP4;
    //Llamado a la creacion de matriz de modelado
    ModeladoC op = ModeladoC();
    //Llamado al algoritmo de Bresenham
    Bresenham line = Bresenham();
    //Matriz de puntos
    OPuntox points = OPuntox(3,1);
    //Matriz de modelado
    OPuntox MModelado = OPuntox(3,3);

    //Creacion de matriz de modelado
    MModelado = op.modeladoCreation(0+CV.getDtx(),0+CV.getDty(),1+CV.getDsx(),1+CV.getDsy(),0+CV.getDtheta(),CV.getTrasInvStatus());

    points = points.multMatrizPoints(p[0],MModelado); //Mult. la matriz de modelado con el punto (ax,ay)
    for(int i = 0; i < 3;i++){
        TP1 = points.getComp(0,0);  //TP1 = ax
        TP2 = points.getComp(1,0);  //TP2 = ay
        if(i == 2){
            points = points.multMatrizPoints(p[0],MModelado); //Mult. la matriz de modelado con el punto (bx,by)
        }
        else{
            points = points.multMatrizPoints(p[i+1],MModelado); //Mult. la matriz de modelado con el punto (bx,by)
        }
        TP3 = points.getComp(0,0);  //TP3 = bx
        TP4 = points.getComp(1,0);  //TP4 = by
        arista.setLinea(TP1.getVal(),TP2.getVal(),TP3.getVal(),TP4.getVal()); //Creacion de la linea
        line.Bresenbased(arista); //Bresenham (A a B)
    }
}
