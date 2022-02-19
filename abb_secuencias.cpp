#include "abb_secuencias.h"

ABBSecuencias crearArbolDeSecuencias() {
    return NULL;
}


void liberarArbolDeSecuencias(ABBSecuencias &abb) {

    if (abb->hizq == NULL && abb->hder == NULL) {
        liberarSecuencia(abb->secuencia);
    } else {
        if (abb->hizq != NULL) {
            liberarArbolDeSecuencias(abb->hizq);
        }

        if (abb->hder != NULL) {
            liberarArbolDeSecuencias(abb->hder);
        }
    }
}


void agregarSecuenciaAlArbolDeSecuancias(ABBSecuencias &abb, Secuencia secuencia) {
    if (abb == NULL) {
        abb = new NodoABBSecuencia;
        abb->secuencia = secuencia;
        abb->hizq = NULL;
        abb->hder = NULL;
    } else {
        if (primerStringAlfabeticameteMenor(secuencia.nombre, abb->secuencia.nombre)) {
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
            if (primerStringAlfabeticameteMenor(nombre, abb->secuencia.nombre)) {
                return buscarSecuenciaEnArbolDeSecuencias(abb->hizq, nombre);
            } else {
                return buscarSecuenciaEnArbolDeSecuencias(abb->hder, nombre);
            }
        }
    }
}


void agregarNumeroASecuenciaDelArbolDeSecuencias(ABBSecuencias abb, string nombre, int numero) {
    if (abb != NULL) {
       if (compararStrings(abb->secuencia.nombre, nombre)) {
           agregarNumeroASecuencia(abb->secuencia, numero);
           mostrarSecuencia(abb->secuencia);
       } else {
           if (primerStringAlfabeticameteMenor(nombre, abb->secuencia.nombre)) {
               agregarNumeroASecuenciaDelArbolDeSecuencias(abb->hizq, nombre, numero);
           } else {
               agregarNumeroASecuenciaDelArbolDeSecuencias(abb->hder, nombre, numero);
           }
       }
    }
}

