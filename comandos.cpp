#include "comandos.h"
#include "stdio.h"

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
