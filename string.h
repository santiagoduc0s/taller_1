#ifndef TALLER_1_STRING_H
#define TALLER_1_STRING_H

#include "boolean.h"

const int MAX_LENGTH_STRING = 80;

typedef char *string;

// ----------------------------------

string crearString();

void cargarString(string &str);

void liberarString(string &str);

int largoString(string str);

void copiarString(string strA, string &strB);

void mostrarString(string str);

boolean compararStrings(string a, string b);

boolean primerStringAlfabeticameteMenor(string a, string b);

boolean stringContieneSoloLetras(string str);

boolean stringContieneSoloNumeros(string str);

boolean stringTerminaEnPuntoTxt(string str);

int convertirStringANumero(string str);

#endif
