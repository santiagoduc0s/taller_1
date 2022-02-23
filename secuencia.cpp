#include "secuencia.h"

string darNombre(Secuencia secuencia) {
    return secuencia.nombre;
}

ListaNumerosNaturales darLista(Secuencia secuencia) {
    return secuencia.lista;
}

Secuencia crearSecuencia(string nombre, ListaNumerosNaturales lista) {
    Secuencia secuencia;
    secuencia.nombre = nombre;
    secuencia.lista = lista;
    return secuencia;
}

void liberarSecuencia(Secuencia &secuencia) {
     liberarString(secuencia.nombre); // -> funciona si el string es cargado mediante la función "cargarString"
    liberarListaDeNumerosNaturales(secuencia.lista);
}

void mostrarSecuencia(Secuencia secuencia) {
    mostrarString(secuencia.nombre);
    printf(" = ");
    mostrarListaDeNumerosNaturales(secuencia.lista);
    printf("\n");
}

void agregarNumeroASecuencia(Secuencia &secuencia, int numero) {
    agregarNumeroAListaDeNumerosNaturales(secuencia.lista, numero);
}