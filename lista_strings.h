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

boolean listaDeStringsEsVacia(ListaStrings lista);

void agregarStringAListaDeStrings(ListaStrings &lista, string texto);

void mostrarListaDeStrings(ListaStrings lista);

ListaStrings convertirStringEnUnaListaDeStrings(string texto);

int tamanioDeListaDeStrings(ListaStrings lista);

string darStringEnLaPosicion(ListaStrings lista, int posicion);

#endif
