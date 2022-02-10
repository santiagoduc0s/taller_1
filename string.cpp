#include "string.h"

string crearString() {
    string str = new char[1];
    str[0] = '\0';
    return str;
}


void liberarString(string &str) {
    delete[] str;
    str = NULL;
}


int largoString(string str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}


void copiarString(string strA, string &strB) {
    int length = largoString(strA);
    delete[] strB;
    strB = new char[length + 1];
    int i = 0;
    while (strA[i] != '\0') {
        strB[i] = strA[i];
        i++;
    }
    strB[i] = '\0';
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


void escribirStringEnArchivo(string s, FILE *archivo) {
    int i = 0;
    while (s[i] != '\0') {
        fwrite(&s[i], sizeof(char), 1, archivo);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, archivo);
}


void leerStringDeArchivo(string &s, FILE *archivo) {
    string aux = new char[MAX_LENGTH_STRING];

    int i = 0;

    fread(&aux[i], sizeof(char), 1, archivo);
    while (aux[i] != '\0') {
        i++;
        fread(&aux[i], sizeof(char), 1, archivo);
    }
    copiarString(aux, s);
    liberarString(aux);
}


// todo: implementar correctamente
boolean primerStringAlfabeticameteMenor(string a, string b) {
    return boolean(a[0] < b[0]);
}

