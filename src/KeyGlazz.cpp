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
#include "KeyGlazz.h"
#include "ControlV.h"

///CONSTRUCTOR
KeyGlazz::KeyGlazz(){}
///DESTRUCTOR
KeyGlazz::~KeyGlazz(){}

///DIBUJAR POLIGONO: KEYGLAZZ
void KeyGlazz::drawKeyGlazz(ControlV CV){
    //Puntos a usar
    RPunto p[16];
    p[0].setX(-8);      p[0].setY(10);
    p[1].setX(1.9);     p[1].setY(10);
    p[2].setX(7.46);    p[2].setY(3.87);
    p[3].setX(2.49);    p[3].setY(0.19);
    p[4].setX(8);       p[4].setY(-6);
    p[5].setX(5.16);    p[5].setY(-6);
    p[6].setX(0.88);    p[6].setY(-0.98);
    p[7].setX(-0.7);    p[7].setY(-2.08);
    p[8].setX(-0.7);    p[8].setY(-6);
    p[9].setX(-3);      p[9].setY(-6);
    p[10].setX(-3);     p[10].setY(5.38);
    p[11].setX(-0.64);  p[11].setY(5.38);
    p[12].setX(-0.64);  p[12].setY(-0.02);
    p[13].setX(4.61);   p[13].setY(3.96);
    p[14].setX(0.82);   p[14].setY(8.27);
    p[15].setX(-8.01);  p[15].setY(8.27);

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
    for(int i = 0; i < 16;i++){
        TP1 = points.getComp(0,0);  //TP1 = ax
        TP2 = points.getComp(1,0);  //TP2 = ay
        if(i == 15){
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
