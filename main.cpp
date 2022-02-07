#include "comandos.h"

int main() {

    ABBSecuencias abb = crearArbolDeSecuencias();

    // create pepe
    create(abb, string("pepe"));

    // insback pepe 4
    insback(abb, string("pepe"), 4);

    // insback pepe 5
    insback(abb, string("pepe"), 5);

    // insback pepe 2
    insback(abb, string("pepe"), 2);

    // create lolo
    create(abb, string("lolo"));

    // insback lolo 3
    insback(abb, string("lolo"), 3);

    // insback lolo 5
    insback(abb, string("lolo"), 5);

    // concat pepe lolo momo
    concat(abb, string("pepe"), string("lolo"), string("concatenacion"));

    // reverse pepe invpepe
    reverse(abb, string("pepe"), string("invpepe"));

    // suma
    suma(abb, string("pepe"));

    // save pepe secuencias.txt
    save(abb, string("pepe"), string("secuencias.txt"), TRUE);

    // save invpepe  secuencias.txt
    save(abb, string("invpepe"), string("secuencias.txt"), FALSE);

    // show
    show(abb);

    return 0;

    // IMPORTANTE para el comando load
//    FILE *archivo = fopen("secuencias.txt", "rb");
//    Secuencia sec;
//    sec = leerSecuenciaDeArchivo(archivo);
//    while (!feof(archivo)) {
//        mostrarSecuencia(sec);
//        sec = leerSecuenciaDeArchivo(archivo);
//    }
}
