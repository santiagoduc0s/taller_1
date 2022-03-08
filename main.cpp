// production
#include "comandos.h"
#include "lista_strings.h"
#include "abb_secuencias.h"

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

    printf("Bienvenido al creador de secuencias. Por favor, ingrese un comando para continuar...\n\n");
    help();


    do {

        fflush(stdin); //Limpia el input
        printf("\n-> ");
        cargarString(input); //Carga el string con los comandos

        if (largoString(input) > 0) //si hay texto
        {

            listaInput = convertirStringEnUnaListaDeStrings(input); //La convierte en una lista de strings en base a los espacios

            primerString = darStringEnLaPosicion(listaInput, 1);

            if (compararStrings(primerString, string("create"))) // ----------------------------------- create
            {
                if (tamanioDeListaDeStrings(listaInput) == 2)
                {
                    segundoString = darStringEnLaPosicion(listaInput, 2);

                    if (stringContieneSoloLetras(segundoString))
                    {
                        if (!existeSecuenciaEnArbolDeSecuencias(abb, segundoString))
                        {
                            Secuencia secuencia = crearSecuencia(segundoString, NULL);
                            agregarSecuenciaAlArbolDeSecuancias(abb, secuencia);
                            mostrarSecuencia(secuencia);
                        }
                        else
                        {
                            printf("Ya existe una secuencia con ese nombre cargada\n");
                        }

                    }
                    else
                    {
                        printf("El nombre de la secuencia ingresado es invalido\n");
                    }

                }
                else
                {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("insback"))) // -------------------------- insback
            {
                if (tamanioDeListaDeStrings(listaInput) == 3) {

                    segundoString = darStringEnLaPosicion(listaInput, 2);
                    tercerString = darStringEnLaPosicion(listaInput, 3);

                    if (stringContieneSoloLetras(segundoString)) {
                        if (stringContieneSoloNumeros(tercerString))
                        {
                            if (existeSecuenciaEnArbolDeSecuencias(abb, segundoString)) {
                                agregarNumeroASecuenciaDelArbolDeSecuencias(abb, segundoString, convertirStringANumero(tercerString));
                            } else {
                                printf("No existe una secuencia con ese nombre\n");
                            }
                        }
                        else
                        {
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

                    if (abb != NULL)
                    {
                        listarArbolDeSecuencias(abb);
                    }
                    else
                    {
                        printf("No hay ninguna secuencia cargada\n");
                    }

                } else {
                    printf("La cantidad de parametros ingresados es incorrecta\n");
                }

            }
            else if (compararStrings(primerString, string("sum"))) // ---------------------------------- sum
            {
                if (tamanioDeListaDeStrings(listaInput) == 2) {

                    segundoString = darStringEnLaPosicion(listaInput, 2);

                    if (stringContieneSoloLetras(segundoString)) {
                        if (existeSecuenciaEnArbolDeSecuencias(abb, segundoString))
                        {
                            Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, segundoString);

                            printf("%i\n", sumarValoresDeListaDeNumerosNaturales(secuencia.lista));
                        }
                        else
                        {
                            printf("No existe una secuencia con ese nombre\n");
                        }
                    }
                    else
                    {
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
                        stringContieneSoloLetras(cuartoString))
                    {
                        if (existeSecuenciaEnArbolDeSecuencias(abb, segundoString)) {
                            if (existeSecuenciaEnArbolDeSecuencias(abb, tercerString)) {
                                if (!existeSecuenciaEnArbolDeSecuencias(abb, cuartoString)) {
                                    Secuencia secuenciaA = buscarSecuenciaEnArbolDeSecuencias(abb, segundoString);
                                    Secuencia secuenciaB = buscarSecuenciaEnArbolDeSecuencias(abb, tercerString);

                                    Secuencia nuevaSecuencia = crearSecuencia(cuartoString, unirDosListasDeNumerosNaturales(secuenciaA.lista, secuenciaB.lista));
                                    agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
                                    mostrarSecuencia(nuevaSecuencia);
                                } else {
                                    printf("Ya existe una secuencia con ese nombre cargada\n");
                                }
                            } else {
                                printf("No existe una secuencia con ese nombre\n");
                            }
                        }
                        else {
                            printf("No existe una secuencia con ese nombre\n");
                        }
                    }
                    else {
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

                    if (stringContieneSoloLetras(segundoString) && stringContieneSoloLetras(tercerString))
                    {
                        if (existeSecuenciaEnArbolDeSecuencias(abb, segundoString)) {
                            if (!existeSecuenciaEnArbolDeSecuencias(abb, tercerString))
                            {

                                Secuencia secuenciaBuscada = buscarSecuenciaEnArbolDeSecuencias(abb, segundoString);
                                Secuencia nuevaSecuencia = crearSecuencia(tercerString, invertirListaDeNumerosNaturales(secuenciaBuscada.lista));
                                agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
                                mostrarSecuencia(nuevaSecuencia);
                            }
                            else
                            {
                                printf("Ya existe una secuencia con ese nombre cargada\n");
                            }
                        }
                        else
                        {
                            printf("No existe una secuencia con ese nombre\n");
                        }

                    }
                    else
                    {
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

                        if (stringTerminaEnPuntoTxt(tercerString))
                        {
                            if (existeSecuenciaEnArbolDeSecuencias(abb, segundoString))
                            {
                                Secuencia secuencia = buscarSecuenciaEnArbolDeSecuencias(abb, segundoString);

                                boolean sobrescribirArchivo = TRUE;
                                FILE *archivo = fopen(tercerString, "rb");

                                if (archivo != NULL)
                                {
                                    printf("El archivo ");
                                    mostrarString(tercerString);
                                    printf(" ya existe, desea sobreescribirlo? ");
                                    cargarBoolean(sobrescribirArchivo);
                                    fclose(archivo);
                                }

                                if (sobrescribirArchivo)
                                {
                                    archivo = fopen(tercerString, "wb");
                                    escribirListaDeNumerosNaturalesEnArchivo(secuencia.lista, archivo);
                                    mostrarString(segundoString);
                                    printf(" almacenada correctamente en ");
                                    mostrarString(tercerString);
                                    printf("\n");
                                    fclose(archivo);
                                }
                            }
                            else
                            {
                                printf("No existe una secuencia con ese nombre\n");
                            }
                        }
                        else {
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
                            if (!existeSecuenciaEnArbolDeSecuencias(abb, tercerString))
                            {

                                FILE *archivo = fopen(segundoString, "rb");
                                if (archivo != NULL)
                                {
                                    Secuencia nuevaSecuencia = crearSecuencia(tercerString, leerListaDeNumerosNaturalesDeArchivo(archivo));
                                    agregarSecuenciaAlArbolDeSecuancias(abb, nuevaSecuencia);
                                    mostrarSecuencia(nuevaSecuencia);
                                }
                                else
                                {
                                    printf("No existe un archivo con ese nombre\n");
                                }
                                fclose(archivo);
                            }
                            else
                            {
                                printf("Ya existe una secuencia con ese nombre cargada\n");
                            }
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
                if (abb != NULL)
                {
                    liberarArbolDeSecuencias(abb);
                }
                liberarListaDeStrings(listaInput);
                printf("Nos vemos pronto\n");
                break;
            }

            else if (compararStrings(primerString, string("clear")))
            {
               if (tamanioDeListaDeStrings(listaInput) == 1)
                    clearScreen();
            }
            else if (compararStrings(primerString, string("help")))
            {
               if (tamanioDeListaDeStrings(listaInput) == 1)
                    help();
            }

            else {
                printf("El comando ingresado no existe en el sistema\n");
            }

        } else {
            printf("No ingreso ningun comando\n");
        }


    } while (true);

}
