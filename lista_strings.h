#ifndef TALLER_1_LISTA_STRINGS_H
#define TALLER_1_LISTA_STRINGS_H

#include "string.h"

typedef struct NodoStringStruct{
    string texto;
    NodoStringStruct *nodoSiguiente;
} NodoString;

typedef NodoString *ListaStrings;

// --------------------------------

ListaStrings crearListaDeStrings(); // return NULL

void liberarListaDeStrings(ListaStrings &lista);

void agregarStringAListaDeStrings(ListaStrings &lista, string texto);

ListaStrings convertirStringEnUnaListaDeStrings(string texto);

int tamanioDeListaDeStrings(ListaStrings lista);

#endif
