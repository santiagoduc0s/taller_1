#ifndef TALLER_1_COMANDOS_H
#define TALLER_1_COMANDOS_H

#include "abb_secuencias.h"

void create(ABBSecuencias &abb, string nombreSecuencia);

void insback(ABBSecuencias &abb, string nombreSecuencia, int numero);

void reverse(ABBSecuencias &abb, string nombreSecuencia, string nombreNuevaSecuencia);

void show(ABBSecuencias abb);

void suma(ABBSecuencias abb, string nombreSecuencia);

void concat(ABBSecuencias &abb, string nombreSecuenciaA, string nombreSecuenciaB, string nombreNuevaSecuencia);

#endif
