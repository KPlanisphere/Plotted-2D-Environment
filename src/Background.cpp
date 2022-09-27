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
#include "KeyGlazz.h"
#include "Background.h"

///CONSTRUCTOR
Background::Background(){}
///DESTRUCTOR
Background::~Background(){}

///GLOBALES
extern ControlV CVBG[20];
extern int band[50];

void Background::BG1(int in){
    //Llamado al algoritmo de Bresenham
    Bresenham lineshow;
    //Figuras
    OLinea linea;
    Circulo O;
    Cuadrado N;
    Triangulo A;
    KeyGlazz K;
    Figuras F;
    switch(in){
    case 1:
        ///Mesa
        glColor3f(0.2, 0.0, 0.7);
        CVBG[0].setDT(270,20);
        CVBG[0].setDS(2.8,1.6);
        O.drawCirculo(CVBG[0]);
        CVBG[0].setDT(270,20);
        CVBG[0].setDS(3.6,2.4);
        O.drawCirculo(CVBG[0]);
        linea.setLinea(-270,57,-275,80);
        lineshow.Bresenbased(linea);
        linea.setLinea(-260,57,-255,80);
        lineshow.Bresenbased(linea);
        linea.setLinea(-158,-10,-134,-5);
        lineshow.Bresenbased(linea);
        linea.setLinea(-156,-20,-132,-25);
        lineshow.Bresenbased(linea);
        linea.setLinea(-405,-5,-382,-10);
        lineshow.Bresenbased(linea);
        linea.setLinea(-407,-25,-384,-20);
        lineshow.Bresenbased(linea);
        linea.setLinea(-275,-97,-280,-120);
        lineshow.Bresenbased(linea);
        linea.setLinea(-255,-97,-250,-120);
        lineshow.Bresenbased(linea);

        //vasos mesa
        CVBG[0].setDS(-0.2,-0.2);
        CVBG[0].setDT(190,30);
        F.drawVaso(CVBG[0]);

        CVBG[0].setDT(210,10);
        F.drawVaso(CVBG[0]);

        CVBG[0].setDT(360,40);
        F.drawVaso(CVBG[0]);

        //platos
        glColor3f(1,1,1);
        CVBG[0].setDS(-0.2,-0.4);
        CVBG[0].setDtheta(0.2);
        CVBG[0].setDT(260,-30);
        N.drawCuadrado(CVBG[0]);
        CVBG[0].setDtheta(-0.2);
        CVBG[0].setDT(280,70);
        N.drawCuadrado(CVBG[0]);
        CVBG[0].setDtheta(0);

        //Contorno boton
        glColor3f(0.5, 0.5, 0.0);
        CVBG[0].setDT(269,15);
        CVBG[0].setDS(0.1,-0.2);
        N.drawCuadrado(CVBG[0]);
        CVBG[0].setDT(269,19);
        CVBG[0].setDS(0.4,0.1);
        N.drawCuadrado(CVBG[0]);
        //Boton
        glColor3f(1.0, 0.0, 0.0);
        CVBG[0].setDT(270,15);
        CVBG[0].setDS(-0.5,-0.6);
        O.drawCirculo(CVBG[0]);
        linea.setLinea(-284,-15,-284,-25);
        lineshow.Bresenbased(linea);
        linea.setLinea(-255,-15,-255,-25);
        lineshow.Bresenbased(linea);
        glColor3f(1.0, 1.0, 1.0);

        //Paredes
        glPointSize(2.0);
        linea.setLinea(100,220,200,140);
        lineshow.Bresenbased(linea);
        linea.setLinea(200,140,200,50);
        lineshow.Bresenbased(linea);
        linea.setLinea(200,50,300,50);
        lineshow.Bresenbased(linea);
        linea.setLinea(300,50,300,200);
        lineshow.Bresenbased(linea);
        linea.setLinea(300,200,500,200);
        lineshow.Bresenbased(linea);

        linea.setLinea(90,220,195,135);
        lineshow.Bresenbased(linea);
        linea.setLinea(195,135,195,45);
        lineshow.Bresenbased(linea);
        linea.setLinea(195,45,305,45);
        lineshow.Bresenbased(linea);
        linea.setLinea(305,45,305,195);
        lineshow.Bresenbased(linea);
        linea.setLinea(305,195,500,195);
        lineshow.Bresenbased(linea);

        linea.setLinea(10,220,195,76);
        lineshow.Bresenbased(linea);
        linea.setLinea(195,45,195,-10);
        lineshow.Bresenbased(linea);
        linea.setLinea(195,-10,305,-10);
        lineshow.Bresenbased(linea);
        linea.setLinea(305,-10,305,140);
        lineshow.Bresenbased(linea);
        linea.setLinea(305,140,500,140);
        lineshow.Bresenbased(linea);

        //Paredes inferiores
        linea.setLinea(195,-220,195,-130);
        lineshow.Bresenbased(linea);
        linea.setLinea(195,-130,305,-130);
        lineshow.Bresenbased(linea);
        linea.setLinea(305,-130,405,-220);
        lineshow.Bresenbased(linea);

        linea.setLinea(200,-220,200,-135);
        lineshow.Bresenbased(linea);
        linea.setLinea(200,-135,305,-135);
        lineshow.Bresenbased(linea);
        linea.setLinea(305,-135,400,-220);
        lineshow.Bresenbased(linea);

        ///Decoracion de paredes
        glPointSize(1.0);
        //Pared central
        CVBG[0].setDT(-248,-18);
        CVBG[0].setDS(1,-0.5);
        N.drawCuadrado(CVBG[0]);
        //Circulos: Pared central
        glColor3f(1.0,0.0,0.0);
        CVBG[0].setDT(-248,-19);
        CVBG[0].setDS(-0.8,-0.8);
        O.drawCirculo(CVBG[0]);
        glColor3f(0.0,1.0,0.0);
        CVBG[0].setDT(-228,-19);
        CVBG[0].setDS(-0.8,-0.8);
        O.drawCirculo(CVBG[0]);
        glColor3f(0.0,0.0,1.0);
        CVBG[0].setDT(-268,-19);
        CVBG[0].setDS(-0.8,-0.8);
        O.drawCirculo(CVBG[0]);

        //Pared derecha
        //lineas gruesas
        glPointSize(5.0);
        glColor3f(1.0, 1.0, 1.0);
        linea.setLinea(350,168,500,168);
        lineshow.Bresenbased(linea);
        linea.setLinea(320,153,500,153);
        lineshow.Bresenbased(linea);
        linea.setLinea(380,183,500,183);
        lineshow.Bresenbased(linea);
        //keyglazz
        glPointSize(1.0);
        CVBG[0].setDT(-330,-173);
        CVBG[0].setDS(0.2,0.2);
        K.drawKeyGlazz(CVBG[0]);

        ///DECORACION SUELO
        //Cuadrado moviendose
        if(band[5] == 0){
            CVBG[4].setDT(-350,-100);
            band[5] = 1;
        }
        else{
            if(band[6] == 0){
                CVBG[4].setDT(CVBG[4].getDtx() - 10,-100);
                if(CVBG[4].getDtx() < -455){
                    band[6] = 1;
                }
            }
            else{
                CVBG[4].setDT(CVBG[4].getDtx() + 10,-100);
                if(CVBG[4].getDtx() > -350){
                    band[6] = 0;
                }
            }
        }
        N.drawCuadrado(CVBG[4]);
        linea.setLinea(320,80,500,80);
        lineshow.Bresenbased(linea);

        glPointSize(3.0);
        linea.setLinea(320,70,500,70);
        lineshow.Bresenbased(linea);
        glPointSize(1.0);


        //Circulo estirandose
        glColor3f(0.3,0.3,0.9);
        if(band[4] == 0){
            CVBG[5].setDT(-400,-10);
            CVBG[5].setDS(-0.5,-1);
            band[4] = 1;
        }
        else{
            if(band[7] == 0){
                CVBG[5].setDS(CVBG[5].getDsx() - 0.05,CVBG[5].getDsy() - 0.05);
                if(CVBG[5].getDsx() < -0.5){
                    band[7] = 1;
                }
            }
            else{
                CVBG[5].setDS(CVBG[5].getDsx() + 0.05,CVBG[5].getDsy() + 0.05);
                if(CVBG[5].getDsx() > 0){
                    band[7] = 0;
                }
            }
        }
        O.drawCirculo(CVBG[5]);

        glColor3f(1,1,1);
        CVBG[0].setDT(-400,-10);
        CVBG[0].setDS(1,0);
        N.drawCuadrado(CVBG[0]);
        CVBG[0].setDT(-400,-5);
        CVBG[0].setDS(1.4,0.4);
        N.drawCuadrado(CVBG[0]);

        //ventana
        glColor3f(1.0,1.0,1.0);
        linea.setLinea(100,200,150,160);
        lineshow.Bresenbased(linea);
        linea.setLinea(100,160,150,120);
        lineshow.Bresenbased(linea);
        linea.setLinea(100,200,100,160);
        lineshow.Bresenbased(linea);
        linea.setLinea(150,160,150,120);
        lineshow.Bresenbased(linea);
        //Estrellas
        CVBG[3].setDS(-0.8,-0.8);
        CVBG[3].setDT(-110,-180);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(-110,-180+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);
        //Estrellitas
        glPointSize(3.0);
        glBegin(GL_POINTS);
            glVertex2i(130,160);
            glVertex2i(140,140);
        glEnd();
        glPointSize(1.0);


        //Escotilla
        glColor3f(1.0,0.0,0.0);
        glPointSize(2.0);
        CVBG[2].setDT(-130,140);
        CVBG[2].setDS(0.1,-0.1);
        N.drawCuadrado(CVBG[2]);
        glColor3f(1.0,1.0,1.0);
        glPointSize(1.0);
        CVBG[1].setDT(-130,140);
        CVBG[1].setDS(0,-0.2);
        N.drawCuadrado(CVBG[1]);

        //lineas escotilla
        linea.setLinea(120,-140,140,-140);
        lineshow.Bresenbased(linea);
        linea.setLinea(120,-135,140,-135);
        lineshow.Bresenbased(linea);
        linea.setLinea(120,-145,140,-145);
        lineshow.Bresenbased(linea);

        break;
    case 2:
        //Estrellas
        glColor3f(1.0,1.0,1.0);
        CVBG[3].setDS(-0.8,-0.8);

        CVBG[3].setDT(120,90);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(121,90+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);

        CVBG[3].setDT(400,150);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(400,150+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);

        CVBG[3].setDT(-400,-150);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(-400,-150+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);

        CVBG[3].setDT(-330,-90);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(-330,-90+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);

        CVBG[3].setDT(-390,170);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(-390,170+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);

        CVBG[3].setDT(270,-170);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(270,-170+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);

        CVBG[3].setDT(450,-50);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(450,-50+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);

        CVBG[3].setDT(-170,110);
        CVBG[3].setDtheta(0);
        A.drawTriangulo(CVBG[3]);
        CVBG[3].setDT(-170,110+4);
        CVBG[3].setDtheta(3.141);
        A.drawTriangulo(CVBG[3]);

        //Estrellitas
        glPointSize(3.0);
        glBegin(GL_POINTS);
            glVertex2i(10,-150);
            glVertex2i(-10,150);
            glVertex2i(370,-80);
            glVertex2i(-290,110);
            glVertex2i(-330,-90);
            glVertex2i(190,90);
        glEnd();
        break;
    }
}
