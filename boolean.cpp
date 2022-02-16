#include "boolean.h"

void cargarBoolean(boolean &b) {
    boolean opcionValida = FALSE;
    char valor;

    do {
        fflush(stdin);
        printf("(S/N)?");
        scanf("%c", &valor);
        if (valor == 'S' || valor == 's' || valor == 'N' || valor == 'n') {
            if (valor == 'S' || valor == 's') {
                b = TRUE;
            } else {
                b = FALSE;
            }
            opcionValida = TRUE;
        }
    } while (opcionValida == FALSE);
}

void mostrarBoolean(boolean b) {
     if (b)
        printf ("verdadero");
     else
        printf ("falso");
}
