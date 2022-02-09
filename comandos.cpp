#include "comandos.h"
#include "archivo.h"

void create(ABBSecuencias &abb, string nombreSecuencia) {

    if (!existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        Secuencia secuencia;
        secuencia.nombre = nombreSecuencia;
        secuencia.lista = NULL;
        agregarSecuenciaAlArbolDeSecuancias(abb, secuencia);
    } else {
        printf("Ya existe una secuencia con ese nombre cargada en memoria\n");
    }
}


void insback(ABBSecuencias &abb, string nombreSecuencia, int numero) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) { // valido que exista
        agregarNumeroASecuenciaDelArbolDeSecuencias(abb, nombreSecuencia, numero);
    } else {
        printf("No existe una secuencia con ese nombre cargada en memoria\n");
    }
}


void reverse(ABBSecuencias &abb, string nombreSecuencia, string nombreNuevaSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        if (existeSecuenciaEnArbolDeSecuencias(abb, nombreNuevaSecuencia)) {

            Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);

            Secuencia nuevaSecuencia;
            nuevaSecuencia.lista = invertirListaDeNumerosNaturales(secuencia.lista);
            nuevaSecuencia.nombre = nombreNuevaSecuencia;

            agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
        } else {
            printf("Ya existe una secuencia con ese nombre cargada en memoria\n");
        }
    } else {
        printf("No existe una secuencia con ese nombre cargada en memoria\n");
    }
}


void show(ABBSecuencias abb) {
    if (abb != NULL) {
        listarArbolDeSecuencias(abb);
    } else {
        printf("No hay ninguna secuencia cargada en memoria");
    }
}


void suma(ABBSecuencias abb, string nombreSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);
        printf("%i\n", sumarValoresDeListaDeNumerosNaturales(secuencia.lista));
    } else {
        printf("No existe una secuencia con ese nombre cargada en memoria\n");
    }
}


void concat(ABBSecuencias &abb, string nombreSecuenciaA, string nombreSecuenciaB, string nombreNuevaSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaA)) {
        if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaB)) {
            if (existeSecuenciaEnArbolDeSecuencias(abb, nombreNuevaSecuencia)) {
                Secuencia secuenciaA = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaA);
                Secuencia secuenciaB = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaB);

                Secuencia nuevaSecuencia;
                nuevaSecuencia.lista = unirDosListasDeNumerosNaturales(secuenciaA.lista, secuenciaB.lista);
                nuevaSecuencia.nombre = nombreNuevaSecuencia;

                agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
            } else {
                printf("Ya existe una secuencia con ese nombre cargada en memoria\n");
            }
        } else {
            printf("No existe una secuencia con ese nombre cargada en memoria\n");
        }
    } else {
        printf("No existe una secuencia con ese nombre cargada en memoria\n");
    }
}


void save(ABBSecuencias &abb, string nombreSecuencia, string nombreArchivo) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);

        // todo: utilizando la función existeArchivo(), preguntar al usuario si desea sobrescribir el documento
        boolean sobrescribirArchivo = TRUE;
        string modoArchivo;
        if (sobrescribirArchivo) {
            modoArchivo = string("wb");
        } else {
            modoArchivo = string("ab");
        }

        FILE *archivo = fopen(nombreArchivo, modoArchivo);
        if (archivo != NULL) {

            escribirListaDeNumerosNaturalesEnArchivo(secuencia.lista, archivo);
            mostrarString(nombreSecuencia);
            printf(" almacenada correctamente en ");
            mostrarString(nombreArchivo);
            printf("\n");

            fclose(archivo);
        }
    } else {
        printf("No existe una secuencia con ese nombre cargada en memoria\n");
    }
}


void load(ABBSecuencias &abb, string nombreArchivo, string nombreSecuencia) {

    if (!existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        if (existeArchivo(nombreArchivo)) {
            Secuencia secuencia;
            secuencia.nombre = nombreSecuencia;
            FILE *archivo = fopen(nombreArchivo, "rb");
            secuencia.lista = leerListaDeNumerosNaturalesDeArchivo(archivo);
            agregarSecuenciaAlArbolDeSecuancias(abb, secuencia);
        } else {
            printf("No existe un archivo con ese nombre\n");
        }
    } else {
        printf("Ya existe una secuencia con ese nombre cargada en memoria\n");
    }
}


void exit(ABBSecuencias &abb) {
    if (abb != NULL) {
        liberarArbolDeSecuencias(abb);
    }
}
