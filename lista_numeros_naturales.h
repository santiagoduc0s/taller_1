#ifndef TALLER_1_LISTA_NUMEROS_NATURALES_H
#define TALLER_1_LISTA_NUMEROS_NATURALES_H

#include "boolean.h"

typedef struct NodoNumeroNaturalStruct {
    int valor;
    NodoNumeroNaturalStruct *nodoSiguiente;
} NodoNumeroNatural;

typedef NodoNumeroNatural *ListaNumerosNaturales;

// -----------------------------------------

ListaNumerosNaturales crearListaDeNumerosNaturales(); // return NULL


void liberarListaDeNumerosNaturales(ListaNumerosNaturales &lista);


boolean listaDeNumerosNaturalesEsVacia(ListaNumerosNaturales lista);


void agregarNumeroAListaDeNumerosNaturales(ListaNumerosNaturales &lista, int num);


void agregarNumeroPorDelanteALista(ListaNumerosNaturales &lista, int numero);


void mostrarListaDeNumerosNaturales(ListaNumerosNaturales lista);


int tamanioDeListaDeNumerosNaturales(ListaNumerosNaturales lista);


ListaNumerosNaturales invertirListaDeNumerosNaturales(ListaNumerosNaturales lista);


int sumarValoresDeListaDeNumerosNaturales(ListaNumerosNaturales lista);


ListaNumerosNaturales unirDosListasDeNumerosNaturales(ListaNumerosNaturales listaA, ListaNumerosNaturales listaB);


void escribirListaDeNumerosNaturalesEnArchivo(ListaNumerosNaturales lista, FILE *archivo);


ListaNumerosNaturales leerListaDeNumerosNaturalesDeArchivo(FILE *archivo);


#endif
