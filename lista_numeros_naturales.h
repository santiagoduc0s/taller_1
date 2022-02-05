#ifndef TALLER_1_LISTA_NUMEROS_NATURALES_H
#define TALLER_1_LISTA_NUMEROS_NATURALES_H

#include "boolean.h"

//struct NodoNumeroNaturalStruct {
//    int valor;
//    NodoNumeroNaturalStruct *nodoSiguiente;
//};

typedef struct NodoNumeroNaturalStruct {
    int valor;
    NodoNumeroNaturalStruct *nodoSiguiente;
} NodoNumeroNatural;

typedef NodoNumeroNatural * ListaNumerosNaturales;

// -----------------------------------------


ListaNumerosNaturales crearListaDeNumerosNaturales();


boolean listaDeNumerosNaturalesEsVacia(ListaNumerosNaturales lista);


void agregarNumeroAListaDeNumerosNaturales(ListaNumerosNaturales &lista, int num);


void mostrarListaDeNumerosNaturales(ListaNumerosNaturales lista);


int tamanioDeListaDeNumerosNaturales(ListaNumerosNaturales lista);


ListaNumerosNaturales invertirListaDeNumerosNaturales(ListaNumerosNaturales lista);


int sumarValoresDeListaDeNumerosNaturales(ListaNumerosNaturales lista);


ListaNumerosNaturales unirDosListasDeNumerosNaturales(ListaNumerosNaturales listaA, ListaNumerosNaturales listaB);


#endif
