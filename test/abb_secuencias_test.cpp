#include "abb_secuencias_test.h"

void abbSecuenciasTest() {

    printf("- Crear secuencia pepe\n");
    ListaNumerosNaturales listaPepe = crearListaDeNumerosNaturales();
    Secuencia pepe = crearSecuencia(string("pepe"), listaPepe);

    printf("- Mostrar secuencia pepe: ");
    mostrarSecuencia(pepe);
    printf("\n");

    printf("- Agregar numero 5 a la secuencia pepe\n");
    agregarNumeroASecuencia(pepe, 5);
    printf("- Agregar numero 8 a la secuencia pepe\n");
    agregarNumeroASecuencia(pepe, 8);
    printf("- Agregar numero 1 a la secuencia pepe\n");
    agregarNumeroASecuencia(pepe, 1);
    printf("\n");

    printf("- Mostrar secuencia pepe: ");
    mostrarSecuencia(pepe);
    printf("\n");

    printf("-----------------------------------\n\n");

    printf("- Crear secuencia lalo\n");
    ListaNumerosNaturales listaLalo = crearListaDeNumerosNaturales();
    Secuencia lalo = crearSecuencia(string("lalo"), listaLalo);

    printf("- Mostrar secuencia lalo: ");
    mostrarSecuencia(lalo);
    printf("\n");

    printf("- Agregar numero 2 a la secuencia lalo\n");
    agregarNumeroASecuencia(lalo, 2);
    printf("- Agregar numero 3 a la secuencia lalo\n");
    agregarNumeroASecuencia(lalo, 3);
    printf("\n");

    printf("- Mostrar secuencia lalo: ");
    mostrarSecuencia(lalo);
    printf("\n");

    printf("-----------------------------------\n\n");

    printf("- Crear arbol de secuencias\n\n");
    ABBSecuencias abb = crearArbolDeSecuencias();

    printf("- Agregar secuencia pepe al abb\n\n");
    agregarSecuenciaAlArbolDeSecuancias(abb, pepe);

    printf("- Mostrar abb: \n");
    listarArbolDeSecuencias(abb);

    printf("-----------------------------------\n\n");

    printf("- Agregar secuencia lalo al abb\n\n");
    agregarSecuenciaAlArbolDeSecuancias(abb, lalo);

    printf("- Mostrar abb: \n");
    listarArbolDeSecuencias(abb);
    printf("\n");

    printf("-----------------------------------\n\n");


    printf("- Existe secuencia pepe:\n");
    if (existeSecuenciaEnArbolDeSecuencias(abb, string("pepe"))) {
        printf("Si existe\n\n");
    } else {
        printf("No existe\n\n");
    }


    printf("- Existe secuencia polo:\n");
    if (existeSecuenciaEnArbolDeSecuencias(abb, string("polo"))) {
        printf("Si existe\n\n");
    } else {
        printf("No existe\n\n");
    }




}