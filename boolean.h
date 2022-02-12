#ifndef TALLER_1_BOOLEAN_H
#define TALLER_1_BOOLEAN_H

#include <stdio.h>

typedef enum {
    FALSE, TRUE
} boolean;

// -------------------------

void cargarBoolean(boolean &b);

void mostrarBoolean(boolean b);

#endif
