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

#include "Cuadrado.h"
#include "Triangulo.h"
#include "Circulo.h"
#include "Figuras.h"

///CONSTRUCTOR
Figuras::Figuras(){}
///DESTRUCTOR
Figuras::~Figuras(){}

///:::::::::::::::::::::::::::::::::::::::::::::::///
///DIBUJAR POLIGONO: AMONG US MUERTO
void Figuras::drawAmongUsMuerto(ControlV CV,float r,float g,float b){
    //Puntos a usar
    RPunto p[21];
    p[0].setXY(-2,-2);
    p[1].setXY(-1,-2);
    p[2].setXY(-1,-1);
    p[3].setXY(0,-1);
    p[4].setXY(0,-2);
    p[5].setXY(1,-2);
    p[6].setXY(1,0);
    p[7].setXY(0,0);
    p[8].setXY(0,1);
    p[9].setXY(0.5,1);
    p[10].setXY(1,1.5);
    p[11].setXY(0.5,2);
    p[12].setXY(0,1.5);
    p[13].setXY(-1,1.5);
    p[14].setXY(-1.5,2);
    p[15].setXY(-2,1.5);
    p[16].setXY(-1.5,1);
    p[17].setXY(-1,1);
    p[18].setXY(-1,0);
    p[19].setXY(0,0);
    p[20].setXY(-2,0);
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
    for(int i = 0; i < 21;i++){
        TP1 = points.getComp(0,0);  //TP1 = ax
        TP2 = points.getComp(1,0);  //TP2 = ay
        if(i == 20){
            points = points.multMatrizPoints(p[0],MModelado); //Mult. la matriz de modelado con el punto (bx,by)
        }
        else{
            points = points.multMatrizPoints(p[i+1],MModelado); //Mult. la matriz de modelado con el punto (bx,by)
        }
        //HUESO
        if(i >= 7 && i < 18){
            glColor3f(1.0, 1.0, 1.0);
        }
        else{
            glColor3f(r,g,b);
        }
        TP3 = points.getComp(0,0);  //TP3 = bx
        TP4 = points.getComp(1,0);  //TP4 = by
        arista.setLinea(TP1.getVal(),TP2.getVal(),TP3.getVal(),TP4.getVal()); //Creacion de la linea
        line.Bresenbased(arista); //Bresenham (A a B)
    }

}
///:::::::::::::::::::::::::::::::::::::::::::::::///
///DIBUJAR POLIGONO: AMONG US
void Figuras::drawAmongUs(ControlV CV,float r,float g,float b){
    //Puntos a usar
    RPunto p[19];
    p[0].setXY(-2,-2);
    p[1].setXY(-1,-2);
    p[2].setXY(-1,-1);
    p[3].setXY(0,-1);
    p[4].setXY(0,-2);
    p[5].setXY(1,-2);
    p[6].setXY(1,2);
    p[7].setXY(-1,2);
    p[8].setXY(-1,1);
    p[9].setXY(1,1);
    p[10].setXY(1,2);
    p[11].setXY(0,3);
    p[12].setXY(-1,3);
    p[13].setXY(-2,2);
    p[14].setXY(-2,1.5);
    p[15].setXY(-2.5,1.5);
    p[16].setXY(-2.5,-0.5);
    p[17].setXY(-2,-0.5);
    p[18].setXY(-2,1.5);
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
    for(int i = 0; i < 19;i++){
        TP1 = points.getComp(0,0);  //TP1 = ax
        TP2 = points.getComp(1,0);  //TP2 = ay
        if(i == 18){
            points = points.multMatrizPoints(p[0],MModelado); //Mult. la matriz de modelado con el punto (bx,by)
        }
        else{
            points = points.multMatrizPoints(p[i+1],MModelado); //Mult. la matriz de modelado con el punto (bx,by)
        }
        //VISOR
        if(i >= 6 && i < 10){
            glColor3f(0.0, 0.0, 1.0);
        }
        else{
            glColor3f(r,g,b);
        }
        TP3 = points.getComp(0,0);  //TP3 = bx
        TP4 = points.getComp(1,0);  //TP4 = by
        arista.setLinea(TP1.getVal(),TP2.getVal(),TP3.getVal(),TP4.getVal()); //Creacion de la linea
        line.Bresenbased(arista); //Bresenham (A a B)
    }
}
///:::::::::::::::::::::::::::::::::::::::::::::::///
///DIBUJAR POLIGONO: VASO
void Figuras::drawVaso(ControlV CV){
    //Puntos a usar
    RPunto p[4];
    p[0].setXY(-10,15);
    p[1].setXY(10,15);
    p[2].setXY(5,-10);
    p[3].setXY(-5,-10);

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

    glColor3f(1,0,0);
    points = points.multMatrizPoints(p[0],MModelado); //Mult. la matriz de modelado con el punto (ax,ay)
    for(int i = 0; i < 4;i++){
        TP1 = points.getComp(0,0);  //TP1 = ax
        TP2 = points.getComp(1,0);  //TP2 = ay
        if(i == 3){
            points = points.multMatrizPoints(p[0],MModelado); //Mult. la matriz de modelado con el punto (bx,by)
        }
        else{
            points = points.multMatrizPoints(p[i+1],MModelado); //Mult. la matriz de modelado con el punto (bx,by)
        }
        //Linea blanca
        if(i >= 0 && i < 1){
            glColor3f(1.0, 1.0, 1.0);
            glPointSize(3.0);
        }
        else{
            glColor3f(1,0,0);
            glPointSize(1.0);
        }
        TP3 = points.getComp(0,0);  //TP3 = bx
        TP4 = points.getComp(1,0);  //TP4 = by
        arista.setLinea(TP1.getVal(),TP2.getVal(),TP3.getVal(),TP4.getVal()); //Creacion de la linea
        line.Bresenbased(arista); //Bresenham (A a B)
    }
}
///:::::::::::::::::::::::::::::::::::::::::::::::///
///DIBUJAR POLIGONO: CAJA
void Figuras::drawCaja(ControlV CV){
    //Puntos a usar
    RPunto p[12];
    p[0].setXY(-2,1);
    p[1].setXY(-1,2);
    p[2].setXY(1,1);
    p[3].setXY(0,0);
    p[4].setXY(0,-2);
    p[5].setXY(1,-1);
    p[6].setXY(1,1);
    p[7].setXY(0,0);
    p[8].setXY(-2,1);
    p[9].setXY(0,0);
    p[10].setXY(0,-2);
    p[11].setXY(-2,-1);
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
    for(int i = 0; i < 12;i++){
        TP1 = points.getComp(0,0);  //TP1 = ax
        TP2 = points.getComp(1,0);  //TP2 = ay
        if(i == 11){
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


