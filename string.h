#ifndef TALLER_1_STRING_H
#define TALLER_1_STRING_H

#include "boolean.h"

const int MAX_LENGTH_STRING = 80;

typedef char *string;


string crearString();


void eliminarString(string &str);


int largoString(string str);


void copiarString(string from, string &to);


void cargarString(string &str);


void mostrarString(string str);


boolean compararStrings(string a, string b);


#endif
