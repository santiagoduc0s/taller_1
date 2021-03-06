#include "lista_strings.h"


ListaStrings crearListaDeStrings() {
    return NULL;
}

void liberarListaDeStrings(ListaStrings &lista) {
    if (lista != NULL) {
        liberarListaDeStrings(lista->nodoSiguiente);
        liberarString(lista->texto);
        delete lista;
    }
}

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
        printf("-\n");
        lista = lista->nodoSiguiente;
        i++;
    }
}

ListaStrings convertirStringEnUnaListaDeStrings(string texto) {

    string nuevoString = new char[MAX_LENGTH_STRING - 1]; //string precioso y mejorado. Con los espacios hermosos.
    int indiceTexto;
    int indiceNuevoString = 0;
    boolean leyendoString = FALSE;

    // extraer palabras de "texto" en "nuevoString" separados por espacios
    for (indiceTexto = 0; indiceTexto < largoString(texto); indiceTexto++) {
        if (texto[indiceTexto] != ' ') { //es letra
            leyendoString = TRUE;
            nuevoString[indiceNuevoString] = texto[indiceTexto];
            indiceNuevoString++;
        } else {
            if (leyendoString && indiceTexto != 0) {
                nuevoString[indiceNuevoString] = ' ';
                indiceNuevoString++;
            }
            leyendoString = FALSE;
        }
    }

    if (nuevoString[indiceNuevoString - 1] != ' ') {
        nuevoString[indiceNuevoString] = ' ';
        nuevoString[indiceNuevoString + 1] = '\0';
    } else {
        nuevoString[indiceNuevoString] = '\0';
    }

    // mostrarString(nuevoString); // testing
    // printf("|\n\n"); // testing

    string palabra = new char[MAX_LENGTH_STRING - 1];
    int indicePalabra = 0;
    ListaStrings lista = crearListaDeStrings();

    // convertir "nuevoString" en una lista
    for (indiceNuevoString = 0; indiceNuevoString < largoString(nuevoString); indiceNuevoString++) {
        if (nuevoString[indiceNuevoString] != ' ') { // es una letra
            palabra[indicePalabra] = nuevoString[indiceNuevoString];
            indicePalabra++;
        } else { //si es un espacio
            palabra[indicePalabra] = '\0';
            string stringAgregarLista = crearString();
            copiarString(palabra, stringAgregarLista);
            agregarStringAListaDeStrings(lista, stringAgregarLista);

            delete[] palabra;
            palabra = new char[MAX_LENGTH_STRING - 1];
            indicePalabra = 0;
        }
    }

    //mostrarListaDeStrings(lista); // testing
    delete[] palabra;
    delete[] nuevoString;

    return lista;
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
    string str = crearString();

    if (posicion >= 1 && posicion <= tamanioDeListaDeStrings(lista) ) {
        int i = 1;
        boolean estoyPosicionado = FALSE;

        while (lista != NULL && !estoyPosicionado) {
            if (i == posicion) {
                str = lista->texto;
                estoyPosicionado = TRUE;
            } else {
                lista = lista->nodoSiguiente;
                i++;
            }
        }
    } else {
        printf("La posicion ingresada esta fuera de rango\n");
    }
    return str;
}
