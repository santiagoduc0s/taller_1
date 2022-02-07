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

void escribirSecuenciaEnArchivo(Secuencia secuencia, FILE *archivo) {
    escribirStringEnArchivo(secuencia.nombre, archivo);
    escribirListaDeNumerosNaturalesEnArchivo(secuencia.lista, archivo);
}

Secuencia leerSecuenciaDeArchivo(FILE *archivo) {
    Secuencia secuencia;
    secuencia.nombre = crearString();
    leerStringDeArchivo(secuencia.nombre, archivo);
    secuencia.lista = leerListaDeNumerosNaturalesDeArchivo(archivo);
    return secuencia;
}
