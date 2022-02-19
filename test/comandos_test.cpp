#include "comandos_test.h"


void comandosTest() {

    ABBSecuencias abb = crearArbolDeSecuencias();

    // ------------------------------------------------------------------

    printf("- Creo secuencia \"pepe\"\n");
    create(abb, string("pepe"));
    printf("\n");

    printf("- Intentar crear nuevamente secuencia \"pepe\"\n");
    create(abb, string("pepe"));
    printf("\n");

    printf("- Sumar secuencia \"pepe\"\n");
    suma(abb, string("pepe"));
    printf("\n");

    printf("- Agregar numero 4 a la secuencia \"pepe\"\n");
    insback(abb, string("pepe"), 4);
    printf("\n");

    printf("- Agregar numero 5 a la secuencia \"pepe\"\n");
    insback(abb, string("pepe"), 5);
    printf("\n");

    printf("- Agregar numero 2 a la secuencia \"pepe\"\n");
    insback(abb, string("pepe"), 2);
    printf("\n");

    printf("- Sumar secuencia \"pepe\"\n");
    suma(abb, string("pepe"));
    printf("\n");

    printf("- Concatenar secuencia \"pepe\" con \"pepe\" -> crear \"pepe_concatenacion\"\n");
    concat(abb, string("pepe"), string("pepe"), string("pepe_concatenacion"));
    printf("\n");

    // ------------------------------------------------------------------

    printf("- Invertir secuencia \"pepe\" -> crear \"pepe_invertida\"\n");
    reverse(abb, string("pepe"), string("pepe_invertida"));
    printf("\n");

    printf("- Agregar numero 20 a secuencia \"pepe_invertida\"\n");
    insback(abb, string("pepe_invertida"), 20);
    printf("\n");

    // ------------------------------------------------------------------

    printf("- Concatenar secuencia \"pepe_concatenacion\" con \"pepe_invertida\" -> crear \"pepe_nuevo\"\n");
    concat(abb, string("pepe_concatenacion"), string("pepe_invertida"), string("pepe_nuevo"));
    printf("\n");

    printf("- Agregar numero 99 a secuencia \"pepe_nuevo\"\n");
    insback(abb, string("pepe_nuevo"), 99);
    printf("\n");

    // ------------------------------------------------------------------

    printf("- Mostrar secuencias cargadas\n");
    show(abb);
    printf("\n");

    // ------------------------------------------------------------------

    printf("- Guardar lista de secuencia \"pepe\" en \"mi_archivo.txt\"\n");
    save(abb, string("pepe"), string("mi_archivo.txt"));
    printf("\n");

    // ------------------------------------------------------------------

    printf("- Leer lista de mi_archivo.txt -> crear \"pepe_archivo\"\n");
    load(abb, string("mi_archivo.txt"), string("pepe_archivo"));
    printf("\n");

    // ------------------------------------------------------------------

    printf("- Mostrar secuencias cargadas\n");
    show(abb);
    printf("\n");

    // ------------------------------------------------------------------

    printf("- Agregar numero 4 a la secuencia \"pepe_archivo\"\n");
    insback(abb, string("pepe_archivo"), 4);
    printf("\n");




    exit(abb);
}

