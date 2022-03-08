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
        printf("No existe una secuencia con ese nombre\n");
    }
}

void reverse(ABBSecuencias &abb, string nombreSecuencia, string nombreNuevaSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        if (!existeSecuenciaEnArbolDeSecuencias(abb, nombreNuevaSecuencia)) {

            Secuencia secuenciaBuscada = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);
            Secuencia nuevaSecuencia = crearSecuencia(nombreNuevaSecuencia, invertirListaDeNumerosNaturales(secuenciaBuscada.lista));
            agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
            mostrarSecuencia(nuevaSecuencia);
        } else {
            printf("Ya existe una secuencia con ese nombre cargada\n");
        }
    } else {
        printf("No existe una secuencia con ese nombre\n");
    }
}


void show(ABBSecuencias abb) {
    if (abb != NULL) {
        listarArbolDeSecuencias(abb);
    } else {
        printf("No hay ninguna secuencia cargada\n");
    }
}


void sum(ABBSecuencias abb, string nombreSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);
        printf("%i\n", sumarValoresDeListaDeNumerosNaturales(secuencia.lista));
    } else {
        printf("No existe una secuencia con ese nombre\n");
    }
}


void concat(ABBSecuencias &abb, string nombreSecuenciaA, string nombreSecuenciaB, string nombreNuevaSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaA)) {
        if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaB)) {
            if (!existeSecuenciaEnArbolDeSecuencias(abb, nombreNuevaSecuencia)) {
                Secuencia secuenciaA = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaA);
                Secuencia secuenciaB = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaB);

                Secuencia nuevaSecuencia = crearSecuencia(nombreNuevaSecuencia, unirDosListasDeNumerosNaturales(secuenciaA.lista, secuenciaB.lista));
                agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
                mostrarSecuencia(nuevaSecuencia);
            } else {
                printf("Ya existe una secuencia con ese nombre cargada\n");
            }
        } else {
            printf("No existe una secuencia con ese nombre\n");
        }
    } else {
        printf("No existe una secuencia con ese nombre\n");
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
        printf("No existe una secuencia con ese nombre\n");
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
        fclose(archivo);
    } else {
        printf("Ya existe una secuencia con ese nombre cargada\n");
    }
}


void exit(ABBSecuencias &abb) {
    if (abb != NULL) {
        liberarArbolDeSecuencias(abb);
    }
}

void clearScreen()
{
    int i;
    for (i = 0; i < 90; i++)
        printf("\n");
}

void help()
{
    printf("\n-- COMANDOS DISPONIBLES --\n\n");
    printf("- create [nombre_secuencia]  -> Crea una secuencia\n");
    printf("- insback [nombre_secuencia] [num_natural]  -> Agrega un valor al final de una secuencia\n");
    printf("- reverse [nombre_secuencia_origen] [nombre_secuencia_resultado]  -> Invierte una secuencia\n");
    printf("- show  -> Muestra todas las secuencias\n");
    printf("- sum [nombre_secuencia]  -> Suma todos los elementos de una secuencia y muestra el resultado\n");
    printf("- concat [nombre_secuencia1] [nombre_secuencia2] [nombre_secuencia_resultado]  -> Combina dos secuencias en una nueva\n");
    printf("- save [nombre_secuencia] [nombre_archivo_txt]  -> Guarda una secuencia existente en un archivo txt\n");
    printf("- load [nombre_archivo_txt] [nombre_secuencia]  -> Dado un archivo txt, crea y carga una secuencia\n");
    printf("- help  -> Muestra la lista de comandos disponibles\n");
    printf("- clear  -> Limpia la pantalla\n");
    printf("- exit  -> Cierra el programa\n\n\n\n\n");
}
