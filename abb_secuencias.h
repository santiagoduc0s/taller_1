#ifndef TALLER_1_ABB_SECUENCIAS_H
#define TALLER_1_ABB_SECUENCIAS_H

#include "secuencia.h"

struct NodoABBSecuenciaStruct {
    Secuencia secuencia;
    NodoABBSecuenciaStruct *hizq;
    NodoABBSecuenciaStruct *hder;
};

typedef NodoABBSecuenciaStruct NodoABBSecuencia;

typedef NodoABBSecuencia *ABBSecuencias;

// ------------------------------------

ABBSecuencias crearArbolDeSecuencias(); // return NULL

void liberarArbolDeSecuencias(ABBSecuencias &abb);

void listarArbolDeSecuencias(ABBSecuencias abb);

void agregarSecuenciaAlArbolDeSecuancias(ABBSecuencias &abb, Secuencia secuencia);

boolean existeSecuenciaEnArbolDeSecuencias(ABBSecuencias abb, string nombre);

///PRECONDICION: existe una secuencia con ese nombre
Secuencia buscarSecuenciaEnArbolDeSecuencias(ABBSecuencias abb, string nombre);

///PRECONDICION: numero tiene que ser mayor o igual a 0
void agregarNumeroASecuenciaDelArbolDeSecuencias(ABBSecuencias &abb, string nombre, int numero);

#endif
