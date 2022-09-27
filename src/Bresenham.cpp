//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Bresenham.h"

///CONSTRUCTOR
Bresenham::Bresenham(){}
///DESTRUCTOR
Bresenham::~Bresenham(){}

///ALGORITMO DE BRESENHAM
//Metodo de rasterizado entre dos puntos con valores enteros
void Bresenham::Bresenbased(OLinea arista){
    RPunto a,b;
    a = arista.getP1();
    b = arista.getP2();
    OMatrices x0 = a.getX();
    OMatrices y0 = a.getY();
    OMatrices x1 = b.getX();
    OMatrices y1 = b.getY();
    int ax = x0.getVal();
    int ay = y0.getVal();
    int bx = x1.getVal();
    int by = y1.getVal();
    int x, y, p, dx, dy, incE, incNE, stepx, stepy;

    dx = (bx - ax);
    dy = (by - ay);
    //Determinar que punto usar para empezar, cual para terminar
    if (dy < 0) {
        dy = -dy; stepy = -1;
      }
    else
      stepy = 1;
    if (dx < 0) {
        dx = -dx; stepx = -1;
      }
    else
      stepx = 1;
    x = ax;
    y = ay;

    glBegin(GL_POINTS);
        glVertex2i(ax,ay);
    glEnd();
     //Se cicla hasta llegar al extremo de la línea
      if(dx>dy){
        p = 2*dy - dx;
        incE = 2*dy;
        incNE = 2*(dy-dx);
        while (x != bx){
          x = x + stepx;
          if (p < 0){
            p = p + incE;
          }
          else {
            y = y + stepy;
            p = p + incNE;
          }
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        }
      }
      else{
        p = 2*dx - dy;
        incE = 2*dx;
        incNE = 2*(dx-dy);
        while (y != by){
          y = y + stepy;
          if (p < 0){
            p = p + incE;
          }
          else {
            x = x + stepx;
            p = p + incNE;
          }
        glBegin(GL_POINTS);
            glVertex2i(x,y);
        glEnd();
        }
      }
}

