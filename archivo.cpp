#include "archivo.h"

boolean existeArchivo(string nombreArchivo) {
    boolean resultado;
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo != NULL) {
        fclose(archivo);
        return TRUE;
    }
    return FALSE;
}