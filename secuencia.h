#ifndef TALLER_1_SECUENCIA_H
#define TALLER_1_SECUENCIA_H

#include "string.h"
#include "lista_numeros_naturales.h"

typedef struct {
    string nombre;
    ListaNumerosNaturales lista;
} Secuencia;

string darNombre(Secuencia secuencia);

ListaNumerosNaturales darLista(Secuencia secuencia);

Secuencia crearSecuencia(string nombre, ListaNumerosNaturales lista);

void liberarSecuencia(Secuencia &secuencia);

void mostrarSecuencia(Secuencia secuencia);

void agregarNumeroASecuencia(Secuencia &secuencia, int numero);

#endif
