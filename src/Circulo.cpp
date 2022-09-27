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
#include <cmath> //Operaciones circulo

#include "OMatrices.h"
#include "OPuntox.h"
#include "OMModelado.h"
#include "ModeladoC.h"
#include "Bresenham.h"
#include "Circulo.h"
#include "ControlV.h"

///Variables globales
extern int first;
extern float angulo,rad;

///CONSTRUCTOR
Circulo::Circulo(){}
///DESTRUCTOR
Circulo::~Circulo(){}

///DIBUJAR POLIGONO: CIRCULO
void Circulo::drawCirculo(ControlV CV){
    //Puntos a usar
    RPunto a,b,temp;
    float rpolar,diff;
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

    //MUESTRA GRAFICA
    diff = 360/90;
    for (int i=0;i<90;i++){
        rpolar = 30;
        temp.setX(rpolar*cos(rad));
        temp.setY(rpolar*sin(rad));

        //IMPRESION DE RECTAS
        if(first == 1){//PRIMER PUNTO
            a.setX(temp.getX());
            a.setY(temp.getY());
            b.setX(temp.getX());
            b.setY(temp.getY());
            first = 0;
        }
        else{//DEMAS PUNTOS
            a.setX(b.getX());
            a.setY(b.getY());
            b.setX(temp.getX());
            b.setY(temp.getY());
            if(i > 0){
                points = points.multMatrizPoints(a,MModelado); //Mult. la matriz de modelado con el punto (ax,ay)
                TP1 = points.getComp(0,0);  //TP1 = x0
                TP2 = points.getComp(1,0);  //TP2 = y0
                points = points.multMatrizPoints(b,MModelado); //Mult. la matriz de modelado con el punto (bx,by)
                TP3 = points.getComp(0,0);  //TP3 = x1
                TP4 = points.getComp(1,0);  //TP2 = y1
                arista.setLinea(TP1.getVal(),TP2.getVal(),TP3.getVal(),TP4.getVal()); //Creacion de la linea
                line.Bresenbased(arista); //Bresenham (A a B)
            }
        }
        //Grados a radianes
        angulo = angulo + diff;
        rad = angulo*(M_PI/180);
    }
}
