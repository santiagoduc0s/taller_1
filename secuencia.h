#ifndef TALLER_1_SECUENCIA_H
#define TALLER_1_SECUENCIA_H

#include "string.h"
#include "lista_numeros_naturales.h"

typedef struct {
    string nombre;
    ListaNumerosNaturales lista;
} Secuencia;


void mostrarSecuencia(Secuencia secuencia);

void agregarNumeroASecuencia(Secuencia &secuencia, int numero);

#endif
