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
        secuencia.lista = invertirListaDeNumerosNaturales(secuencia.lista);
        secuencia.nombre = nombreNuevaSecuencia;

        agregarSecuenciaAlArbolDeSecuancias(abb, secuencia);
    }
}


void show(ABBSecuencias abb) {
    listarArbolDeSecuencias(abb);
}
