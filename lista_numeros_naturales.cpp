#include "lista_numeros_naturales.h"

ListaNumerosNaturales crearListaDeNumerosNaturales() {
    return NULL;
}

boolean listaDeNumerosNaturalesEsVacia(ListaNumerosNaturales lista) {
    return boolean(lista == NULL);
}

void agregarNumeroAListaDeNumerosNaturales(ListaNumerosNaturales &lista, int num) {
    ListaNumerosNaturales nodo = new NodoNumeroNatural;
    if (listaDeNumerosNaturalesEsVacia(lista)) {
        nodo->valor = num;
        nodo->nodoSiguiente = NULL;
        lista = nodo;
    } else {
        ListaNumerosNaturales listaAux = lista;
        while (listaAux->nodoSiguiente != NULL) {
            listaAux = listaAux->nodoSiguiente;
        }
        nodo->valor = num;
        nodo->nodoSiguiente = NULL;
        listaAux->nodoSiguiente = nodo;
    }
}

void mostrarListaDeNumerosNaturales(ListaNumerosNaturales lista) {
    printf("[ ");
    while (lista != NULL) {
        if (lista->nodoSiguiente != NULL) {
            printf("%i, ", lista->valor);
        } else {
            printf("%i ", lista->valor);
        }
        lista = lista->nodoSiguiente;
    }
    printf("]");
}

int tamanioDeListaDeNumerosNaturales(ListaNumerosNaturales lista) {
    int i = 0;
    while (lista != NULL) {
        i++;
        lista = lista->nodoSiguiente;
    }
    return i;
}

ListaNumerosNaturales invertirListaDeNumerosNaturales(ListaNumerosNaturales lista) {
    int *numeros = new int[tamanioDeListaDeNumerosNaturales(lista)];
    int i = 0;
    while (lista != NULL) {
        numeros[i] = lista->valor;
        i++;
        lista = lista->nodoSiguiente;
    }

    ListaNumerosNaturales nuevaLista = crearListaDeNumerosNaturales();
    for (i = i - 1; i >= 0; --i) {
        agregarNumeroAListaDeNumerosNaturales(nuevaLista, numeros[i]);
    }
    delete[] numeros;
    return nuevaLista;
}