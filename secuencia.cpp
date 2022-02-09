#include "secuencia.h"

void mostrarSecuencia(Secuencia secuencia) {
    mostrarString(secuencia.nombre);
    printf(" = ");
    mostrarListaDeNumerosNaturales(secuencia.lista);
    printf("\n");
}

void agregarNumeroASecuencia(Secuencia &secuencia, int numero) {
    agregarNumeroAListaDeNumerosNaturales(secuencia.lista, numero);
}