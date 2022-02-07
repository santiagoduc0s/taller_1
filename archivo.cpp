#include "archivo.h"

boolean existeArchivo(string nombreArchivo) {
    boolean resultado;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        resultado = FALSE;
    } else {
        resultado = TRUE;
    }
    fclose(archivo);
    return resultado;
}

boolean archivoVacio(string nombreArchivo) {
    boolean resultado;
    FILE *archivo = fopen(nombreArchivo, "rb");
    fseek(archivo, 0, SEEK_END);
    if (ftell(archivo) == 0) {
        resultado = TRUE;
    } else {
        resultado = FALSE;
    }
    return resultado;
}

long tamanioDelArchivo(string nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    fseek (archivo, 0, SEEK_END);
    long tam = ftell(archivo);
    return tam;
}