#include "string.h"

string crearString() {
    string str = new char[1];
    str[0] = '\0';
    return str;
}


void eliminarString(string &str) {
    delete[] str;
    str = NULL;
}


int largoString(string str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}


void copiarString(string from, string &to) {
    int length = largoString(from);
    delete[] to;
    to = new char[length + 1];
    int i = 0;
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}


void cargarString(string &str) {
    string aux;
    char character;
    int i = 0;
    aux = new char[MAX_LENGTH_STRING - 1];
    scanf("%c", &character);
    while ((character != '\n') && (i < MAX_LENGTH_STRING - 1)) {
        aux[i] = character;
        i++;
        scanf("%c", &character);
    }
    aux[i] = '\0';

    copiarString(aux, str);
    delete[] aux;
}


void mostrarString(string str) {
    int i = 0;
    while (str[i] != '\0') {
        printf("%c", str[i]);
        i++;
    }
}


boolean compararStrings(string a, string b)
{
    boolean equal = TRUE;
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0' && equal == TRUE) {
        if (a[i] != b[i]) {
            equal = FALSE;
        }
        i++;
    }

    if ((a[i] != '\0' || b[i] != '\0') && a[i] != b[i]) {
        equal = FALSE;
    }

    return equal;
}


void escribirString(string s, FILE *archivo) {
    int i = 0;
    while (s[i] != '\0') {
        fwrite(&s[i], sizeof(char), 1, archivo);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, archivo);
}


void leerString(string &s, FILE *archivo) {
    string aux = new char[MAX_LENGTH_STRING];

    int i = 0;

    fread(&aux[i], sizeof(char), 1, archivo);
    while (aux[i] != '\0') {
        i++;
        fread(&aux[i], sizeof(char), 1, archivo);
    }
    copiarString(aux, s);
    eliminarString(aux);
}


// todo: implementar correctamente
boolean primerStringAlfabeticameteMenor(string a, string b) {
    return boolean(a[0] < b[0]);
}

