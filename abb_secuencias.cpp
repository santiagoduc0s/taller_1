#include "abb_secuencias.h"

ABBSecuencias crearArbolDeSecuencias() {
    return NULL;
}

void agregarSecuenciaAlArbolDeSecuancias(ABBSecuencias &abb, Secuencia secuencia) {
    if (abb == NULL) {
        abb = new NodoABBSecuencia;
        abb->secuencia = secuencia;
        abb->hizq = NULL;
        abb->hder = NULL;
    } else {
        if (secuencia.nombre[0] < abb->secuencia.nombre[0]) { // todo: crear funcion que compare strings alfabeticamente
            agregarSecuenciaAlArbolDeSecuancias(abb->hizq, secuencia);
        } else {
            agregarSecuenciaAlArbolDeSecuancias(abb->hder, secuencia);
        }
    }
}

void listarArbolDeSecuencias(ABBSecuencias abb) {
    if (abb != NULL) {
        listarArbolDeSecuencias(abb->hizq);
        mostrarSecuencia(abb->secuencia);
        listarArbolDeSecuencias(abb->hder);
    }
}

boolean existeSecuenciaEnArbolDeSecuencias(ABBSecuencias abb, string nombre) {
    if (abb == NULL) {
        return FALSE;
    } else if (compararStrings(abb->secuencia.nombre, nombre)) {
        return TRUE;
    } else {
        return boolean(existeSecuenciaEnArbolDeSecuencias(abb->hizq, nombre) || existeSecuenciaEnArbolDeSecuencias(abb->hder, nombre));
    }
}


Secuencia buscarSecuenciaEnArbolDeSecuencias(ABBSecuencias abb, string nombre) {
    if (abb != NULL) {
        if (compararStrings(abb->secuencia.nombre, nombre)) {
            return abb->secuencia;
        } else {
            buscarSecuenciaEnArbolDeSecuencias(abb->hizq, nombre);
            buscarSecuenciaEnArbolDeSecuencias(abb->hder, nombre);
        }
    }
}

void agregarNumeroASecuenciaDelArbolDeSecuencias(ABBSecuencias abb, string nombre, int numero) {
    if (abb != NULL) {
       if (compararStrings(abb->secuencia.nombre, nombre)) {
           agregarNumeroASecuencia(abb->secuencia, numero);
       } else {
           agregarNumeroASecuenciaDelArbolDeSecuencias(abb->hizq, nombre, numero);
           agregarNumeroASecuenciaDelArbolDeSecuencias(abb->hder, nombre, numero);
       }
    }
}