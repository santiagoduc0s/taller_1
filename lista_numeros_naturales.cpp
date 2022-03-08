#include "lista_numeros_naturales.h"


ListaNumerosNaturales crearListaDeNumerosNaturales() {
    return NULL;
}


void liberarListaDeNumerosNaturales(ListaNumerosNaturales &lista) {
    if (lista != NULL) {
        liberarListaDeNumerosNaturales(lista->nodoSiguiente);
        delete lista;
    }
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

void agregarNumeroPorDelanteALista(ListaNumerosNaturales &lista, int numero) {
    ListaNumerosNaturales aux = new NodoNumeroNatural;
    aux->valor = numero;
    aux->nodoSiguiente = lista;
    lista = aux;
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

ListaNumerosNaturales invertirListaDeNumerosNaturales(ListaNumerosNaturales lista)
{
    ListaNumerosNaturales resultado = crearListaDeNumerosNaturales();

    while (lista != NULL) {
        agregarNumeroPorDelanteALista(resultado, lista->valor);
        lista = lista->nodoSiguiente;
    }

    return resultado;
}

int sumarValoresDeListaDeNumerosNaturales(ListaNumerosNaturales lista) {
    int suma = 0;
    while (lista != NULL) {
        suma = suma + lista->valor;
        lista = lista->nodoSiguiente;
    }
    return suma;
}


ListaNumerosNaturales unirDosListasDeNumerosNaturales(ListaNumerosNaturales listaA, ListaNumerosNaturales listaB) {

    ListaNumerosNaturales nuevaLista = crearListaDeNumerosNaturales();

    while (listaA != NULL) {
        agregarNumeroAListaDeNumerosNaturales(nuevaLista, listaA->valor);
        listaA = listaA->nodoSiguiente;
    }

    while (listaB != NULL) {
        agregarNumeroAListaDeNumerosNaturales(nuevaLista, listaB->valor);
        listaB = listaB->nodoSiguiente;
    }

    return nuevaLista;
}

/*
void escribirListaDeNumerosNaturalesEnArchivo(ListaNumerosNaturales lista, FILE *archivo) {
    // todo: preguntar cuando termina el archivo
    while (lista != NULL) {
        fwrite(&lista->valor, sizeof(int), 1, archivo);
        lista = lista->nodoSiguiente;
    }
    int endList = -1;
    fwrite(&endList, sizeof(int), 1, archivo);
}
*/

void escribirListaDeNumerosNaturalesEnArchivo(ListaNumerosNaturales lista, FILE *archivo) {
    while (lista != NULL) {
        fwrite(&lista->valor, sizeof(int), 1, archivo);
        lista = lista->nodoSiguiente;
    }
}


ListaNumerosNaturales leerListaDeNumerosNaturalesDeArchivo(FILE *archivo) {
    ListaNumerosNaturales lista = crearListaDeNumerosNaturales();
    int buffer;

    fread(&buffer, sizeof(int), 1, archivo);
    while (!feof(archivo)) {
        agregarNumeroAListaDeNumerosNaturales(lista, buffer);
        fread(&buffer, sizeof(int), 1, archivo);
    }

    return lista;
}


/*
ListaNumerosNaturales leerListaDeNumerosNaturalesDeArchivo(FILE *archivo) {
    // todo: preguntar cuando termina el archivo
    ListaNumerosNaturales lista = crearListaDeNumerosNaturales();
    int buffer = -1;

    fread(&buffer, sizeof(int), 1, archivo);
    while (buffer != -1) {
        agregarNumeroAListaDeNumerosNaturales(lista, buffer);
        fread(&buffer, sizeof(int), 1, archivo);
    }

    return lista;
}*/
