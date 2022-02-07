#include "comandos.h"

void create(ABBSecuencias &abb, string nombreSecuencia) {

    if (!existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) { // valido que no exista

        Secuencia secuencia;
        secuencia.nombre = nombreSecuencia;
        secuencia.lista = NULL;

        agregarSecuenciaAlArbolDeSecuancias(abb, secuencia);
    }
}


void insback(ABBSecuencias &abb, string nombreSecuencia, int numero) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) { // valido que exista
        agregarNumeroASecuenciaDelArbolDeSecuencias(abb, nombreSecuencia, numero);
    }
}


void reverse(ABBSecuencias &abb, string nombreSecuencia, string nombreNuevaSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {

        Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);

        Secuencia nuevaSecuencia;
        nuevaSecuencia.lista = invertirListaDeNumerosNaturales(secuencia.lista);
        nuevaSecuencia.nombre = nombreNuevaSecuencia;

        agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
    }
}


void show(ABBSecuencias abb) {
    listarArbolDeSecuencias(abb);
}


void suma(ABBSecuencias abb, string nombreSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);
        printf("%i\n", sumarValoresDeListaDeNumerosNaturales(secuencia.lista));
    }
}


void concat(ABBSecuencias &abb, string nombreSecuenciaA, string nombreSecuenciaB, string nombreNuevaSecuencia) {

    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaA)
        && existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaB)) {
        Secuencia secuenciaA = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaA);
        Secuencia secuenciaB = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuenciaB);

        Secuencia nuevaSecuencia;
        nuevaSecuencia.lista = unirDosListasDeNumerosNaturales(secuenciaA.lista, secuenciaB.lista);
        nuevaSecuencia.nombre = nombreNuevaSecuencia;

        agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
    }
}


void save(ABBSecuencias &abb, string nombreSecuencia, string nombreArchivo, boolean sobrescribirArchivo) {
    if (existeSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia)) {
        Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, nombreSecuencia);

        string modoArchivo;
        if (sobrescribirArchivo) {
            modoArchivo = string("wb");
        } else {
            modoArchivo = string("ab");
        }

        FILE *archivo = fopen(nombreArchivo, modoArchivo);
        if (archivo != NULL) {

            escribirSecuenciaEnArchivo(secuencia, archivo);
            mostrarString(nombreSecuencia);
            printf(" almacenada correctamente en ");
            mostrarString(nombreArchivo);
            printf("\n");

            fclose(archivo);
        }
    }
}


void load(ABBSecuencias &abb, string nombreArchivo, string nombreSecuencia) {

}
