//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iomanip>
#include <stdlib.h>

#include "ModeladoC.h"
#include "Bresenham.h"
#include "ControlV.h"
#include "Stage.h"

#include "Cuadrado.h"
#include "Triangulo.h"
#include "Circulo.h"
#include "KeyGlazz.h"
#include "Figuras.h"
#include "Background.h"

///GLOBALES
extern ControlV CV[20];
extern int band[50],supercont;
extern float red;

///CONSTRUCTOR
Stage::Stage(){}

///DESTRUCTOR
Stage::~Stage(){}

///ESCENARIO
void Stage::Theater(){
    //Llamado al algoritmo de Bresenham
    Bresenham lineshow;
    //Llamado a las funciones de figuras
    Background fondo;
    //Figuras
    OLinea linea;
    Cuadrado N;
    Triangulo A;
    Circulo O;
    KeyGlazz K;
    Figuras F;

///BACKGROUND GENERAL
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    linea.setLinea(-500,220,500,220);
    lineshow.Bresenbased(linea);
    linea.setLinea(-500,-220,500,-220);
    lineshow.Bresenbased(linea);

    //Marca de agua xd
    CV[20].setDT(475,-190);
    CV[20].setDS(1,1);
    K.drawKeyGlazz(CV[20]);

    //Alerta
    glPointSize(19.0);
    glColor3f(red, 0.0, 0.0);
    linea.setLinea(-500,230,500,230);
    lineshow.Bresenbased(linea);
    linea.setLinea(-500,-230,500,-230);
    lineshow.Bresenbased(linea);
    glColor3f(1.0, 1.0, 1.0);

    glPointSize(1.0);

///  - - -  A C T O   U N O  - - -

    if(supercont < 330){ //330
        //Alerta barra superior e inferior
        if(supercont > 250 && supercont < 330){
            if(band[8] < 1){
                red = red + 0.1;
                if(red > 1){
                    band[8] = 1;
                }
            }
            else{
                red = red - 0.1;
                if(red < 0){
                    band[8] = 0;
                }
            }
        }
        ///BACKGROUND
        fondo.BG1(1);
        /// FIGURA 1
        CV[1].setDT(100,60);
        CV[1].setDS(10,10);
        F.drawAmongUs(CV[1],1,0,0);
        /// FIGURA 2
        //CV[1].setDT(350,-120);
        CV[5].setDS(10,10);
        F.drawAmongUs(CV[5],1,0,1);

        if(band[9] == 0){
            CV[5].setDT(500,-120);
            band[9] = 1;
        }
        else{
            if(band[10] == 0){
                CV[5].setDT(CV[5].getDtx() - 2,-120);
                if(CV[5].getDtx() < 260){
                    band[10] = 1;
                }
            }
        }

        /// FIGURA 3
        //El among que muere
        if(supercont > 250){
            CV[1].setDT(-100,-30);
            CV[1].setDS(10,10);
            F.drawAmongUsMuerto(CV[1],1,1,0);

            //Signo admiracion
            CV[1].setDT(105,0);
            CV[1].setDS(-0.7,-0.7);
            glColor3f(1.0,0.0,0.0);
            O.drawCirculo(CV[1]);

            CV[1].setDT(105,-40);
            CV[1].setDS(-0.6,0.2);
            N.drawCuadrado(CV[1]);

        }
        else{
            CV[1].setDT(-100,-30);
            CV[1].setDS(10,10);
            F.drawAmongUs(CV[1],1,1,0);
        }
        /// FIGURA 4
        //Asesino
        CV[2].setDS(10,10);
        CV[2].setDtheta(0);
        F.drawAmongUs(CV[2],0,1,0);
        //Punto inicial
        if(band[0] == 0){
            CV[2].setDT(-400,90);
            band[0] = 1;
        }
        else{
            //Movimiento en x
            if(band[1] == 0){
                CV[2].setDT(CV[2].getDtx() + 3,90);
                if(CV[2].getDtx() > -60){
                    band[1] = 1;
                }
            }
            //Movimiento en y
            else if(band[1] == 1){
                CV[2].setDT(CV[2].getDtx(),CV[2].getDty() - 1);
                if(CV[2].getDty() < -30){
                    band[1] = 2;
                }
            }
        }
        //Cajungas
        glColor3f(1.0,1.0,1.0);
        CV[3].setDT(200,-150);
        CV[3].setDS(10,10);
        F.drawCaja(CV[3]);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 18,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 18);
        lineshow.Bresenbased(linea);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 15,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 15);
        lineshow.Bresenbased(linea);
        CV[4].setDT(CV[3].getDtx() + 7,CV[3].getDty() + 6);
        CV[4].setDS(-0.9,-0.9);
        O.drawCirculo(CV[4]);

        CV[3].setDT(150,-150);
        CV[3].setDS(10,10);
        F.drawCaja(CV[3]);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 18,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 18);
        lineshow.Bresenbased(linea);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 15,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 15);
        lineshow.Bresenbased(linea);
        CV[4].setDT(CV[3].getDtx() + 7,CV[3].getDty() + 6);
        CV[4].setDS(-0.9,-0.9);
        O.drawCirculo(CV[4]);

        CV[3].setDT(100,-150);
        CV[3].setDS(10,10);
        F.drawCaja(CV[3]);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 18,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 18);
        lineshow.Bresenbased(linea);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 15,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 15);
        lineshow.Bresenbased(linea);
        CV[4].setDT(CV[3].getDtx() + 7,CV[3].getDty() + 6);
        CV[4].setDS(-0.9,-0.9);
        O.drawCirculo(CV[4]);

        CV[3].setDT(450,180);
        CV[3].setDS(10,10);
        F.drawCaja(CV[3]);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 18,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 18);
        lineshow.Bresenbased(linea);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 15,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 15);
        lineshow.Bresenbased(linea);
        CV[4].setDT(CV[3].getDtx() + 7,CV[3].getDty() + 6);
        CV[4].setDS(-0.9,-0.9);
        O.drawCirculo(CV[4]);

        CV[3].setDT(40,180);
        CV[3].setDS(10,10);
        F.drawCaja(CV[3]);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 18,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 18);
        lineshow.Bresenbased(linea);
        linea.setLinea(-CV[3].getDtx() -20,-CV[3].getDty() + 10 - 15,-CV[3].getDtx() -2 ,-CV[3].getDty() + 1 - 15);
        lineshow.Bresenbased(linea);
        CV[4].setDT(CV[3].getDtx() + 7,CV[3].getDty() + 6);
        CV[4].setDS(-0.9,-0.9);
        O.drawCirculo(CV[4]);
    }
    else{

///  - - -  A C T O   D O S  - - -

        ///BACKGROUND
        fondo.BG1(2);
        red = 0; //Barra superior e inferior de color negro
        glPointSize(1.0);
        //Amongus rodando y trasladandose de izquierda a derecha
        CV[2].setDtheta(CV[2].getDtheta()+0.1);
        F.drawAmongUs(CV[2],0,1,0);
        if(band[2] == 0){
            CV[2].setDT(500,0);
            band[2] = 1;
        }
        else{
            if(band[3] == 0){
                CV[2].setDT(CV[2].getDtx() - 5,0);
                if(CV[2].getDtx() < -530){
                    band[3] = 1;
                }
            }
        }
        //Nombre del jugador
        glColor3f(1.0,1.0,1.0);
        glPointSize(3.0);
        CV[1].setDT(0,50);
        if(CV[1].getDsx() < 5)
        CV[1].setDS(CV[1].getDsx() + 0.1,-0.9);
        N.drawCuadrado(CV[1]);

        //Reset
        if(supercont > 600){
            supercont = 0;
            band[0] = 0;
            band[1] = 0;
            band[2] = 0;
            band[3] = 0;
            band[4] = 0;
            band[5] = 0;
            band[6] = 0;
            band[7] = 0;
            band[8] = 0;
        }
    }
}
