#include "complejo.h"
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
    printf("\n");
    printf("Escoge operacion\n");
    printf("0) Salir\n");
    printf("1) Obtener parte Real\n");
    printf("2) Obtener parte Imaginaria\n");
    printf("3) Obtener suma\n");
    printf("4) Obtener resta\n");
    printf("5) Obtener multiplicacion\n");
    printf("6) Obtener division\n");
    printf("7) Convertir a la forma polar\n");

    scanf("%d", &opc);

    switch (opc) {
        case 1:
            printf("%f", real(pedirDatos()));
            break;
        case 2:
            printf("%f", imaginario(pedirDatos()));
            break;
        case 3:
            imprimeComplejo(sumar(pedirDatos(), pedirDatos()));
            break;
        case 4:
            imprimeComplejo(restar(pedirDatos(), pedirDatos()));
            break;
        case 5:
            imprimeComplejo(multiplicar(pedirDatos(), pedirDatos()));
            break;
        case 6:
            imprimeComplejo(dividir(pedirDatos(), pedirDatos()));
            break;
        case 7:
            convertirPolar(pedirDatos());
            break;
        default:
            return 0;

    }
    return 1;
}
