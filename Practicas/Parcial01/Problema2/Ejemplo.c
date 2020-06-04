#include <stdio.h>
#include <stdlib.h>
#include "complejoDinamico.h"

int main(int argc, char const *argv[]) {

    complejo c[3];
    complejo *c1 = (complejo*) malloc(sizeof(complejo) * 3);

    for (int i = 0; i < 3; i++) {
        c1++ = pedirDatos();
        //c[i] = *pedirDatos();
    }


    return 0;
}
