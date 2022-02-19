#include "comandos.h"

void create(ABBSecuencias &abb, string nombreSecuencia) {

    if (!existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        Secuencia secuencia = crearSecuencia(nombreSecuencia, NULL);
        agregarSecuenciaAlArbolDeSecuancias(abb, secuencia);
        mostrarSecuencia(secuencia);
    } else {
        printf("Ya existe una secuencia con ese nombre cargada\n");
    }
}


void insback(ABBSecuencias &abb, string nombreSecuencia, int numero) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        agregarNumeroASecuenciaDelArbolDeSecuencias(abb, nombreSecuencia, numero);
    } else {
        printf("No existe una secuencia con ese nombre cargada en memoria\n");
    }
}


void reverse(ABBSecuencias &abb, string nombreSecuencia, string nombreNuevaSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        if (!existeSecuenciaEnArbolDeSecuencias(abb, nombreNuevaSecuencia)) {

            Secuencia secuenciaBuscada = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);
            Secuencia nuevaSecuencia = crearSecuencia(nombreNuevaSecuencia,
                                                      invertirListaDeNumerosNaturales(secuenciaBuscada.lista));
            agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
            mostrarSecuencia(nuevaSecuencia);
        } else {
            printf("Ya existe una secuencia con ese nombre cargada\n");
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
            if (!existeSecuenciaEnArbolDeSecuencias(abb, nombreNuevaSecuencia)) {
                Secuencia secuenciaA = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaA);
                Secuencia secuenciaB = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaB);

                Secuencia nuevaSecuencia = crearSecuencia(nombreNuevaSecuencia,
                                                          unirDosListasDeNumerosNaturales(secuenciaA.lista,
                                                                                          secuenciaB.lista));
                agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
                mostrarSecuencia(nuevaSecuencia);
            } else {
                printf("jeee");
                printf("Ya existe una secuencia con ese nombre cargada\n");
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

        boolean sobrescribirArchivo = TRUE;
        FILE *archivo = fopen(nombreArchivo, "rb");
        if (archivo != NULL) {
            printf("El archivo ");
            mostrarString(nombreArchivo);
            printf(" ya existe, desea sobreescribirlo? ");
            cargarBoolean(sobrescribirArchivo);
            fclose(archivo);
        }

        if (sobrescribirArchivo) {
            archivo = fopen(nombreArchivo, "wb");
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

        FILE *archivo = fopen(nombreArchivo, "rb");
        if (archivo != NULL) {
            Secuencia nuevaSecuencia = crearSecuencia(nombreSecuencia, leerListaDeNumerosNaturalesDeArchivo(archivo));
            agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
            mostrarSecuencia(nuevaSecuencia);
        } else {
            printf("No existe un archivo con ese nombre\n");
        }
    } else {
        printf("Ya existe una secuencia con ese nombre cargada\n");
    }
}


void exit(ABBSecuencias &abb) {
    if (abb != NULL) {
        liberarArbolDeSecuencias(abb);
    }
    printf("Hasta la proxima!");
}
