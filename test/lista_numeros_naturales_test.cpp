#include "lista_numeros_naturales_test.h"

void listaNumerosNaturalesTest() {


    printf("Se crea una lista \n\n");
    ListaNumerosNaturales lista = crearListaDeNumerosNaturales();



    printf("- Largo de la lista\n");
    printf("Largo: %i\n\n", tamanioDeListaDeNumerosNaturales(lista));



    printf("- Se agrega a la lista el numero 5\n");
    agregarNumeroAListaDeNumerosNaturales(lista, 5);

    printf("- Se agrega a la lista el numero 8\n");
    agregarNumeroAListaDeNumerosNaturales(lista, 8);

    printf("- Se agrega a la lista el numero 2\n");
    agregarNumeroAListaDeNumerosNaturales(lista, 2);

    printf("Mostrar lista: ");
    mostrarListaDeNumerosNaturales(lista);
    printf("\n\n");



    printf("- Largo de la lista\n");
    printf("Largo: %i\n\n", tamanioDeListaDeNumerosNaturales(lista));



    printf("- Se agrega a la lista el numero -5\n");
    agregarNumeroAListaDeNumerosNaturales(lista, -5);


    printf("Mostrar lista: ");
    mostrarListaDeNumerosNaturales(lista);
    printf("\n\n");


    printf("- Se suman los numeros de la lista\n");
    printf("Suma: %i\n", sumarValoresDeListaDeNumerosNaturales(lista));

    printf("\n------------------------------------\n\n");

    printf("Se crea otra lista \n\n");
    ListaNumerosNaturales lista2 = crearListaDeNumerosNaturales();

    printf("- Se agrega a la lista el numero 5\n");
    agregarNumeroAListaDeNumerosNaturales(lista2, 5);

    printf("- Se agrega a la lista el numero 10\n");
    agregarNumeroAListaDeNumerosNaturales(lista2, 10);

    printf("Mostrar lista: ");
    mostrarListaDeNumerosNaturales(lista2);
    printf("\n\n");

    printf("\n------------------------------------\n\n");

    printf("- Se unen las dos listas\n\n");
    ListaNumerosNaturales lista3 = unirDosListasDeNumerosNaturales(lista, lista2);

    printf("Mostrar lista: ");
    mostrarListaDeNumerosNaturales(lista3);
    printf("\n\n");


    printf("- Se crea un archivo\n");
    FILE *file = fopen("lista.txt", "wb");

    printf("- Se guarda la lista concatenada\n\n");
    escribirListaDeNumerosNaturalesEnArchivo(lista3, file);
    fclose(file);

    printf("- Se lee la lista del archivo creado\n");
    fopen("lista.txt", "rb");
    ListaNumerosNaturales lista4 = leerListaDeNumerosNaturalesDeArchivo(file);

    printf("- Mostrar lista guardada en el archivo\n");
    mostrarListaDeNumerosNaturales(lista4);
    fclose(file);
}