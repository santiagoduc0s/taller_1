#include "comandos.h"

int main() {

    ABBSecuencias abb = crearArbolDeSecuencias(); // variable global

    // create pepe
    create(abb, string("pepe"));

    // insback pepe 4
    insback(abb, string("pepe"), 4);

    // insback pepe 5
    insback(abb, string("pepe"), 5);

    // insback pepe 2
    insback(abb, string("pepe"), 2);

    // create lolo
    create(abb, string("lolo"));

    // insback lolo 3
    insback(abb, string("lolo"), 3);

    // insback lolo 5
    insback(abb, string("lolo"), 5);

    // reverse pepe invpepe
    reverse(abb, string("pepe"), string("invpepe"));

    // suma
    suma(abb, string("pepe"));

    show(abb);

    return 0;

    // ESTO es para testing de santi

    ListaNumerosNaturales lista = crearListaDeNumerosNaturales();

    agregarNumeroAListaDeNumerosNaturales(lista, 1);
    agregarNumeroAListaDeNumerosNaturales(lista, 2);
    agregarNumeroAListaDeNumerosNaturales(lista, 3);
    agregarNumeroAListaDeNumerosNaturales(lista, 4);
    agregarNumeroAListaDeNumerosNaturales(lista, 5);
    agregarNumeroAListaDeNumerosNaturales(lista, 64);

//    printf("%i", sumarValoresDeListaDeNumerosNaturales(lista));

    mostrarListaDeNumerosNaturales(lista);

    mostrarListaDeNumerosNaturales(invertirListaDeNumerosNaturales(lista));

    return 2;

    Secuencia secuencia1 = {string("calo"), lista};
    Secuencia secuencia2 = {string("anti"), lista};
    Secuencia secuencia3 = {string("gjfdg"), lista};
    Secuencia secuencia4 = {string("inasesati"), lista};
    Secuencia secuencia5 = {string("ssdfas"), lista};
    Secuencia secuencia6 = {string("prt"), lista};
    Secuencia secuencia7 = {string("bdrgsd"), lista};
    Secuencia secuencia8 = {string("tgrtg"), lista};
    Secuencia secuencia9 = {string("vntseergi"), lista};


    mostrarSecuencia(secuencia1);
    mostrarSecuencia(secuencia2);

//    ABBSecuencias abb = crearArbolDeSecuencias();
//
//    printf("\n\n");
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia1);
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia2);
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia3);
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia4);
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia5);
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia6);
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia7);
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia8);
//    agregarSecuenciaAlArbolDeSecuancias(abb, secuencia9);
//
//
//    listarArbolDeSecuencias(abb);





}
