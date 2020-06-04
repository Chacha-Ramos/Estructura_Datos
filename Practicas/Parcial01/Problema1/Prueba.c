#include "Fraccion.h"
#include <stdio.h>
#include <stdbool.h>

int menu();

int main(int argc, char const *argv[]) {

    while (true) {
        if (menu() == 0)
            break;
    }

    return 0;
}

int menu() {
    int opc;
    fraccion a, b;
    printf("Escoge operacion\n");
    printf("0) Salir\n");
    printf("1) Obtener numerador\n");
    printf("2) Obtener denominador\n");
    printf("3) Obtener suma\n");
    printf("4) Obtener resta\n");
    printf("5) Obtener multiplicacion\n");
    printf("6) Obtener division\n");
    printf("7) Simplificar\n");

    scanf("%d", &opc);

    switch (opc) {
        case 1:
            numerador(pedirDatos());
            break;
        case 2:
            denominador(pedirDatos());
            break;
        case 3:
            imprimeFraccion(sumar(pedirDatos(), pedirDatos()));
            break;
        case 4:
            imprimeFraccion(restar(pedirDatos(), pedirDatos()));
            break;
        case 5:
            imprimeFraccion(multiplicar(pedirDatos(), pedirDatos()));
            break;
        case 6:
            imprimeFraccion(dividir(pedirDatos(), pedirDatos()));
            break;
        case 7:
            imprimeFraccion(simplificar(pedirDatos()));
            break;
        default:
            return 0;

    }
    return 1;
}
