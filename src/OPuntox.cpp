//BENEMERITA UNIVERSIDAD AUTONOMA DE PUEBLA -FACULTAD DE CIENCIAS DE LA COMPUTACION
//GRAFICACION - JESUS HUERTA AGUILAR "PLANISPHERE"
#include <iomanip>
#include <stdlib.h>
#include <cmath> //Para truncar
#include <vector>

#include "OPuntox.h"

///Constructores
OPuntox::OPuntox(int fil,int col){
    //Filas - Columnas
    n = fil;
    m = col;
    ///Matriz llena de ceros
    //INSTANCIACION DE LOS COMPONENTES DE LA MATRIZ
    for (int i = 0;i < n;i++){
        //Almacena los elementos de la columna
        std::vector<OMatrices> v1;
        for (int j = 0; j < m; j++) {
            v1.push_back(OMatrices());
        }
        //Agregalos los elementos de las columas (por fila)
        matriz.push_back(v1);
    }
}

///DESTRUCTOR
OPuntox::~OPuntox(){}

///GETTER
//Devuelve el componente de la matriz
OMatrices OPuntox::getComp(int i,int j){
    return matriz[i][j];
}
//Numero de filas
int OPuntox::getFilNum(){
    return n;
}
//Numero de columnas
int OPuntox::getColNum(){
    return m;
}

///SETTER
//Asigna un valor en un componente en especifico
void OPuntox::setComp(int i,int j,OMatrices val){
    matriz[i][j].setVal(val.getVal());
}

/// - - - - - - -> DIVERSOS
//MULTIPLICA MATRICES 3X3
// - Se retorna la matriz C (en ella se guardara el resultado de la multiplicación)
OPuntox OPuntox::multMatriz(OPuntox A,OPuntox B){
    //Matriz auxiliar
    OPuntox C = OPuntox(3,3);
    OMatrices _A,_B,_C; //Variables para extraer el valor del componente
    for (int i = 0;i < 3;i++){
        for (int j = 0;j < 3;j++){
            C.setComp(i,j,0);
            for (int k = 0;k < 3;k++){
                //Asignamos los componente a operar
                _A = A.getComp(i,k);
                _B = B.getComp(k,j);
                _C = C.getComp(i,j);
                //Guardamos el componente final en C
                C.setComp(i,j,_C.getVal() + (_A.getVal() * _B.getVal()));
            }
        }
    }
    return C;

}
//MULTIPLICA MATRICES PUNTOS
// - Recibe un punto (p)
// - A sera la matriz de modelado
// - points sera la matriz de puntos
OPuntox OPuntox::multMatrizPoints(RPunto p,OPuntox A){
    //Matriz de puntos auxiliar
    OPuntox C = OPuntox(3,1);
    OMatrices _A,_B,_C; //Variables para extraer el valor del componente
    //Asignacion de los puntos X y Y en la matriz de puntos
    OPuntox points = OPuntox(3,1);
    points.setComp(0,0,p.getX());
    points.setComp(1,0,p.getY());
    points.setComp(2,0,1);

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 1;j++){
            C.setComp(i,j,0);
            for (int k = 0;k < 3;k++){
                //Asignamos los componente a operar
                _A = A.getComp(i,k);
                _B = points.getComp(k,j);
                _C = C.getComp(i,j);
                //Guardamos el componente final en C
                C.setComp(i,j,_C.getVal() + _A.getVal() * _B.getVal());
            }
        }
    }
    for(int i = 0; i < 3;i++){
        _C = C.getComp(i,0);
        C.setComp(i,0,trunc(_C.getVal())); //Se trunca por que points es int
    }
    return C;
}
