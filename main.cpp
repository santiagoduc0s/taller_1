// production
#include "comandos.h"
#include "lista_strings.h"

// testing
//#include "./test/lista_numeros_naturales_test.h"
//#include "./test/comandos_test.h"

int main() {

    ABBSecuencias abb = crearArbolDeSecuencias();
    string input = crearString();
    ListaStrings listaInput = crearListaDeStrings();
    string primerString = crearString();
    string segundoString = crearString();
    string tercerString = crearString();
    string cuartoString = crearString();

    do {

        fflush(stdin);
        cargarString(input);

        if (largoString(input) > 0) {

            listaInput = convertirStringEnUnaListaDeStrings(input);

            primerString = darStringEnLaPosicion(listaInput, 1);

            if (compararStrings(primerString, string("create"))) // ----------------------------------- create
            {
                if (tamanioDeListaDeStrings(listaInput) == 2) {

                    segundoString = darStringEnLaPosicion(listaInput, 2);

                    if (stringContieneSoloLetras(segundoString)) {
                        create(abb, segundoString);
                    } else {
                        printf("El nombre de la secuencia ingresado es invalido\n");
                    }

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("insback"))) // -------------------------- insback
            {
                if (tamanioDeListaDeStrings(listaInput) == 3) {

                    segundoString = darStringEnLaPosicion(listaInput, 2);
                    tercerString = darStringEnLaPosicion(listaInput, 3);

                    if (stringContieneSoloLetras(segundoString)) {
                        if (stringContieneSoloNumeros(tercerString)) {
                            insback(abb, segundoString, convertirStringANumero(tercerString));
                        } else {
                            printf("El valor que intenta agregar es invalido\n");
                        }

                    } else {
                        printf("El nombre de la secuencia ingresado es invalido\n");
                    }

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("show"))) // -------------------------------- show
            {
                if (tamanioDeListaDeStrings(listaInput) == 1) {

                    show(abb);

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("sum"))) // ---------------------------------- sum
            {
                if (tamanioDeListaDeStrings(listaInput) == 2) {

                    segundoString = darStringEnLaPosicion(listaInput, 2);

                    if (stringContieneSoloLetras(segundoString)) {
                        sum(abb, segundoString);
                    } else {
                        printf("El nombre de la secuencia ingresado es invalido\n");
                    }

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("concat"))) // ---------------------------- concat
            {
                if (tamanioDeListaDeStrings(listaInput) == 4) {

                    segundoString = darStringEnLaPosicion(listaInput, 2);
                    tercerString = darStringEnLaPosicion(listaInput, 3);
                    cuartoString = darStringEnLaPosicion(listaInput, 4);

                    if (stringContieneSoloLetras(segundoString) &&
                        stringContieneSoloLetras(tercerString) &&
                        stringContieneSoloLetras(cuartoString)) {
                        concat(abb, segundoString, tercerString, cuartoString);
                    } else {
                        printf("El nombre de las secuencias debe estar compuesto por solo letras\n");
                    }

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("reverse"))) // -------------------------- reverse
            {

                if (tamanioDeListaDeStrings(listaInput) == 3) {

                    segundoString = darStringEnLaPosicion(listaInput, 2);
                    tercerString = darStringEnLaPosicion(listaInput, 3);

                    if (stringContieneSoloLetras(segundoString) &&
                        stringContieneSoloLetras(tercerString)) {
                        reverse(abb, segundoString, tercerString);
                    } else {
                        printf("El nombre de las secuencias debe estar compuesto por solo letras\n");
                    }

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("save"))) // -------------------------------- save
            {
                if (tamanioDeListaDeStrings(listaInput) == 3) {

                    segundoString = darStringEnLaPosicion(listaInput, 2);
                    tercerString = darStringEnLaPosicion(listaInput, 3);

                    if (stringContieneSoloLetras(segundoString)) {

                        if (stringTerminaEnPuntoTxt(tercerString)) {
                            save(abb, segundoString, tercerString);
                        } else {
                            printf("El nombre del archivo debe finalizar con \".txt\"\n");
                        }

                    } else {
                        printf("El nombre de las secuencias debe estar compuesto por solo letras\n");
                    }

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("load"))) // -------------------------------- load
            {
                if (tamanioDeListaDeStrings(listaInput) == 3) {

                    segundoString = darStringEnLaPosicion(listaInput, 2); // nombre archivo
                    tercerString = darStringEnLaPosicion(listaInput, 3); // nombre nueva secuencia

                    if (stringTerminaEnPuntoTxt(segundoString)) {

                        if (stringContieneSoloLetras(tercerString)) {
                            load(abb, segundoString, tercerString);
                        } else {
                            printf("El nombre de las secuencias debe estar compuesto por solo letras\n");
                        }

                    } else {
                        printf("El nombre del archivo debe finalizar con \".txt\"\n");
                    }

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("exit"))) // -------------------------------- exit
            {
                exit(abb);
                liberarListaDeStrings(listaInput);
                printf("Nos vemos pronto\n");
                break;
            }
            else {
                printf("El comando ingresado no existe en el sistema\n");
            }

        } else {
            printf("No ingreso ningun comando\n");
        }


    } while (true);

}
