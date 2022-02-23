#include "abb_secuencias.h"

ABBSecuencias crearArbolDeSecuencias() {
    return NULL;
}


void liberarArbolDeSecuencias(ABBSecuencias &abb) {

    if (abb != NULL) {
        listarArbolDeSecuencias(abb->hizq);
        listarArbolDeSecuencias(abb->hder);
        liberarSecuencia(abb->secuencia);
        delete abb;
    }
}


void agregarSecuenciaAlArbolDeSecuancias(ABBSecuencias &abb, Secuencia secuencia) {
    if (abb == NULL) {
        abb = new NodoABBSecuencia;
        abb->secuencia = secuencia;
        abb->hizq = NULL;
        abb->hder = NULL;
    } else {
        if (primerStringAlfabeticameteMenor(darNombre(secuencia), darNombre(abb->secuencia))) {
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
        if (primerStringAlfabeticameteMenor(nombre, darNombre(abb->secuencia))) {
            return boolean(existeSecuenciaEnArbolDeSecuencias(abb->hizq, nombre));
        } else {
            return boolean(existeSecuenciaEnArbolDeSecuencias(abb->hder, nombre));
        }
    }
}


Secuencia buscarSecuenciaEnArbolDeSecuencias(ABBSecuencias abb, string nombre) {
    if (abb != NULL) {
        if (compararStrings(darNombre(abb->secuencia), nombre)) {
            return abb->secuencia;
        } else {
            if (primerStringAlfabeticameteMenor(nombre, darNombre(abb->secuencia))) {
                return buscarSecuenciaEnArbolDeSecuencias(abb->hizq, nombre);
            } else {
                return buscarSecuenciaEnArbolDeSecuencias(abb->hder, nombre);
            }
        }
    }
}


void agregarNumeroASecuenciaDelArbolDeSecuencias(ABBSecuencias &abb, string nombre, int numero) {
    if (abb != NULL) {
       if (compararStrings(abb->secuencia.nombre, nombre)) {
           agregarNumeroASecuencia(abb->secuencia, numero);
           mostrarSecuencia(abb->secuencia);
       } else {
           if (primerStringAlfabeticameteMenor(nombre, darNombre(abb->secuencia))) {
               agregarNumeroASecuenciaDelArbolDeSecuencias(abb->hizq, nombre, numero);
           } else {
               agregarNumeroASecuenciaDelArbolDeSecuencias(abb->hder, nombre, numero);
           }
       }
    }
}

