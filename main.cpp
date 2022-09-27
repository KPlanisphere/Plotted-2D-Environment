//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iomanip>
#include <stdlib.h>

///ORDEN ARCHIVOS
//"OMatrices"
    //"RPunto.h"
        //#include "OLinea.h"
        //#include "Bresenham.h"
    //#include "OPuntox.h"
        //#include "OMModelado.h"
            //#include "ModeladoC.h"
//#include "ControlV.h"
    //#include "Figuras.h"
    //#include "Cuadrado.h"
    //#include "Triangulo.h"
    //#include "Circulo.h"
    //#include "KeyGlazz.h"
//#include "Stage.h"
//#include "Background.h"

#include "ControlV.h"
#include "Stage.h"

GLfloat sizep;
///GLOBALES
float angulo = 0,rad = 0,red = 0;
int first = 1;
int band[50];
int supercont = 0;
ControlV CV[20];
ControlV CVBG[20];

//INIT
void init(void){
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -240, 240);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
//Todos los elementos de la bandera en ceros
void BanderaCero(int used){
    for(int i = 0; i < used;i++){
        band[i] = 0;
    }
}

//Dibuja grafica
void dibujaGrafica(){
    glClear(GL_COLOR_BUFFER_BIT);  //borra la ventana de visualizacion

    Stage show;
    show.Theater();
    supercont++;

    glFlush();
    Sleep(30);
}
//Main
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //Posicion de la ventana
    glutInitWindowPosition(150,100);
    //se establece el ancho y la altura de la ventana de visualizacion
    glutInitWindowSize(1000,480);
    //se crea la ventana de visualizacion
    glutCreateWindow(":: PLANISPHERE ::");
    init();
    BanderaCero(50);
    glutDisplayFunc(dibujaGrafica);
    //Animation
    glutIdleFunc(dibujaGrafica);
    glutMainLoop();
    return 0;
}
