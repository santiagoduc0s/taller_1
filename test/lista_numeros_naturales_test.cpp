#include "lista_numeros_naturales_test.h"

void listaNumerosNaturalesTest() {



    ListaNumerosNaturales lista = crearListaDeNumerosNaturales();



    printf("- Se valida si la lista es vacia\n");
    if (listaDeNumerosNaturalesEsVacia(lista)) {
        printf("CORRECTO: SI es vacia\n\n");
    } else {
        printf("ERROR: NO es vacia\n\n");
    }



    printf("- Se valida si el largo de la lista es cero\n");
    if (tamanioDeListaDeNumerosNaturales(lista) == 0) {
        printf("CORRECTO: El largo de la lista es cero\n\n");
    } else {
        printf("ERROR: El largo de la lista NO es cero\n\n");
    }



    printf("- Se agrega a la lista el numero 5\n");
    agregarNumeroAListaDeNumerosNaturales(lista, 5);

    printf("- Se agrega a la lista el numero 8\n");
    agregarNumeroAListaDeNumerosNaturales(lista, 8);

    printf("- Se agrega a la lista el numero 2\n");
    agregarNumeroAListaDeNumerosNaturales(lista, 2);

    printf("- Mostrar lista: ");
    mostrarListaDeNumerosNaturales(lista);
    printf("\n\n");



    printf("- Se valida si el largo de la lista es tres\n");
    if (tamanioDeListaDeNumerosNaturales(lista) == 3) {
        printf("CORRECTO: El largo de la lista es tres\n\n");
    } else {
        printf("ERROR: El largo de la lista NO es tres\n\n");
    }



    printf("- Se valida que no se agregue el -5 a la lista\n");
    agregarNumeroAListaDeNumerosNaturales(lista, -5);
    printf("- Mostrar lista: ");
    mostrarListaDeNumerosNaturales(lista);
    printf("\n\n");


    printf("- Se valida que los numeros de la lista sumen 15\n");
    printf("- La suma de la lista es %i\n", sumarValoresDeListaDeNumerosNaturales(lista));





}