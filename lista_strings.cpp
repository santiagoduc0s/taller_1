#include "lista_strings.h"


ListaStrings crearListaDeStrings() {
    return NULL;
}

void liberarListaDeStrings(ListaStrings &lista) {}

boolean listaDeStringsEsVacia(ListaStrings lista) {
    return boolean(lista == NULL);
}

void agregarStringAListaDeStrings(ListaStrings &lista, string texto) {
    ListaStrings nodo = new NodoString;
    if (listaDeStringsEsVacia(lista)) {
        nodo->texto = texto;
        nodo->nodoSiguiente = NULL;
        lista = nodo;
    } else {
        ListaStrings listaAux = lista;
        while (listaAux->nodoSiguiente != NULL) {
            listaAux = listaAux->nodoSiguiente;
        }
        nodo->texto = texto;
        nodo->nodoSiguiente = NULL;
        listaAux->nodoSiguiente = nodo;
    }
}

void mostrarListaDeStrings(ListaStrings lista) {
    int i = 1;
    while (lista != NULL) {
        printf("%i-", i);
        mostrarString(lista->texto);
        printf("-");
        lista = lista->nodoSiguiente;
        i++;
    }
}

ListaStrings convertirStringEnUnaListaDeStrings(string texto) {
    return NULL;
}

int tamanioDeListaDeStrings(ListaStrings lista) {
    int i = 0;
    while (lista != NULL) {
        i++;
        lista = lista->nodoSiguiente;
    }
    return i;
}

string darStringEnLaPosicion(ListaStrings lista, int posicion) {
    string str = new char [1];
    str[0] = '\n';
    return str;
}