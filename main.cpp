#include "comandos.h"
#include "archivo.h"


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

    // concat pepe lolo momo
    concat(abb, string("pepe"), string("lolo"), string("concatenacion"));

    // reverse pepe invpepe
    reverse(abb, string("pepe"), string("invpepe"));

    // suma
//    suma(abb, string("pepe"));

    // save pepe secuencias.txt
    save(abb, string("pepe"), string("secuencias.txt"), TRUE);
    save(abb, string("invpepe"), string("secuencias.txt"), FALSE);


    FILE *archivo = fopen("secuencias.txt", "rb");
    Secuencia sec;
    sec = leerSecuenciaDeArchivo(archivo);
    while (!feof(archivo)) {
        mostrarSecuencia(sec);
        sec = leerSecuenciaDeArchivo(archivo);
    }

    // show
//    show(abb);

    return 0;




//    FILE *archivo;


    // leer strings
//    string str = crearString();
//    archivo = fopen("string.txt", "rb"); // leer
//    if(archivo != NULL) {
//        if (!archivoVacio(string("string.txt"))) {
//            leerStringDeArchivo(str, archivo);
//            while (!feof(archivo)) {
//                mostrarString(str);
//                leerStringDeArchivo(str, archivo);
//            }
//        } else {
//            printf("esta vacio");
//        }
//    }

    // escribir string
//    string str = crearString();
//    cargarString(str);
//    archivo = fopen("string.txt", "ab");
//    escribirStringEnArchivo(str, archivo);

    // escribir entero
//    archivo = fopen("numeros.txt", "ab");
//    int i = 16;
//    fwrite(&i, sizeof(char), 1, archivo);

    // leer entero
//    archivo = fopen("numeros.txt", "rb");
//    int i = 156;
//    if(archivo != NULL) {
//        if (!archivoVacio(string("numeros.txt"))) {
//            fread(&i, sizeof(char), 1, archivo);
//            while (!feof(archivo)) {
//                fread(&i, sizeof(char), 1, archivo);
//                printf("%i ", i);
//            }
//        } else {
//            printf("esta vacio");
//        }
//    }




//    ListaNumerosNaturales lista = crearListaDeNumerosNaturales();
//    agregarNumeroAListaDeNumerosNaturales(lista, 1);
//    agregarNumeroAListaDeNumerosNaturales(lista, 2);
//    agregarNumeroAListaDeNumerosNaturales(lista, 5);
//
//    archivo = fopen("numeros.txt", "ab"); // escribir
//    escribirListaDeNumerosNaturalesEnArchivo(lista, archivo);

//    archivo = fopen("numeros.txt", "rb"); // leer
//    lista = leerListaDeNumerosNaturalesDeArchivo(archivo);
//    while (!feof(archivo)) {
//        mostrarListaDeNumerosNaturales(lista);
//        lista = leerListaDeNumerosNaturalesDeArchivo(archivo);
//    }

//    fclose(archivo);

//    archivo = fopen("numeros.txt", "rb"); // leer
//    while (!feof(archivo)) {
//        mostrarListaDeNumerosNaturales(leerListaDeNumerosNaturalesDeArchivo(archivo));
//    }

    // -- escribir y leer secuencias
//    archivo = fopen("secuencias.txt", "ab");
//    if (archivo != nullptr) {
//
//        Secuencia sec = {string("rarosi"), lista};
//
//        escribirSecuenciaEnArchivo(sec, archivo);
//
//        fclose(archivo);
//    }
//
//    archivo = fopen("secuencias.txt", "rb");
//    Secuencia sec;
//    sec = leerSecuenciaDeArchivo(archivo);
//    while (!feof(archivo)) {
//        mostrarSecuencia(sec);
//        sec = leerSecuenciaDeArchivo(archivo);
//    }




//    mostrarListaDeNumerosNaturales(leerListaDeNumerosNaturalesDeArchivo(archivo));
//    while (!feof(archivo)) {
//        mostrarListaDeNumerosNaturales(leerListaDeNumerosNaturalesDeArchivo(archivo));
//    }



    return 0;

//

    // ESTO es para testing de santi

//    ListaNumerosNaturales lista = crearListaDeNumerosNaturales();
//    ListaNumerosNaturales lista2 = crearListaDeNumerosNaturales();
//
//    agregarNumeroAListaDeNumerosNaturales(lista, 1);
//    agregarNumeroAListaDeNumerosNaturales(lista, 2);
//    agregarNumeroAListaDeNumerosNaturales(lista, 3);
//    agregarNumeroAListaDeNumerosNaturales(lista, 4);
//    agregarNumeroAListaDeNumerosNaturales(lista, 5);
//    agregarNumeroAListaDeNumerosNaturales(lista, 64);

//    agregarNumeroAListaDeNumerosNaturales(lista2, 3);
//    agregarNumeroAListaDeNumerosNaturales(lista2, 4);


//    Secuencia secuencia1 = {string("calo"), lista};
//    Secuencia secuencia2 = {string("anti"), lista};
//    Secuencia secuencia3 = {string("gjfdg"), lista};
//    Secuencia secuencia4 = {string("inasesati"), lista};
//    Secuencia secuencia5 = {string("santi"), lista};
//    Secuencia secuencia6 = {string("prt"), lista};
//    Secuencia secuencia7 = {string("bdrgsd"), lista};
//    Secuencia secuencia8 = {string("tgrtg"), lista};
//    Secuencia secuencia9 = {string("vntseergi"), lista};
//
//
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
//    Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, string("calo"));
//    secuencia.lista = NULL;


//    listarArbolDeSecuencias(abb);
}
