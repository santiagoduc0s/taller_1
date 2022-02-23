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

boolean compararStrings(string a, string b) {
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

boolean primerStringAlfabeticameteMenor(string a, string b) {

    int largoStringA = largoString(a);
    int largoStringB = largoString(b);
    int largoMenorString;

    if (largoStringA < largoStringB) {
        largoMenorString = largoStringA;
    } else {
        largoMenorString = largoStringB;
    }

    boolean sonIdenticos = TRUE;
    boolean esAlfabeticameteMenor = TRUE;
    for (int i = 0; i < largoMenorString; ++i) {
        if (b[i] < a[i]) {
            esAlfabeticameteMenor = FALSE;
            sonIdenticos = FALSE;
        } else if (b[i] > a[i]) {
            sonIdenticos = FALSE;
            break;
        }
    }

    if (sonIdenticos && largoStringB < largoStringA) {
        esAlfabeticameteMenor = FALSE;
    }

    return esAlfabeticameteMenor;
}

int convertirStringANumero(string str) {
    int multiplicoPor = 1;
    int suma = 0;
    int numero;
    int i = largoString(str) - 1;
    // todo: hacer un for
    while (i >= 0) {
        numero = int(str[i]) - 48;
        suma = suma + (multiplicoPor * numero);
        multiplicoPor = multiplicoPor * 10;
        i--;
    }
    return suma;
}

boolean stringTerminaEnPuntoTxt(string str) {
    int i = 0;
    boolean termina = FALSE;

    while (str[i] != '\0' && !termina) {
        if (str[i] == '.') {
            i++;
            if (str[i] == 't') {
                i++;
                if (str[i] == 'x') {
                    i++;
                    if (str[i] == 't') {
                        i++;
                        if (str[i] == '\0') {
                            termina = TRUE;
                        }
                    }
                }
            }
        }
        i++;
    }
    return termina;
}

boolean stringContieneSoloNumeros(string s) {
    boolean contieneSoloNumeros = TRUE;
    int i = 0;
    while ((s[i] != '\0') && contieneSoloNumeros) {
        if (s[i] >= 48 && s[i] <= 57)
            i++;
        else
            contieneSoloNumeros = FALSE;
    }
    return contieneSoloNumeros;
}

boolean stringContieneSoloLetras(string s) {
    boolean contieneSoloLetras = TRUE;
    int i = 0;
    while ((s[i] != '\0') && contieneSoloLetras) {
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
            i++;
        else
            contieneSoloLetras = FALSE;

    }
    return contieneSoloLetras;
}



