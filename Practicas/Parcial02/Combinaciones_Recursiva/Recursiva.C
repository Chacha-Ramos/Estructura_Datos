#include "Recursiva.h"
#include <stdio.h>
#include <stdbool.h>


int main(){

    int TOTAL = 0, GRUPOS = 0;
    printf("Combinaciones sin repeticion de n objetos tomados de k en k\n");
    printf("Para salir del programa digite 1010\n");
    do{
    printf("Ingrese el numero total de elementos\n");
    scanf(" %i", &TOTAL);
    printf("Ingrese el tamano de los grupos\n");
    scanf(" %i", &GRUPOS);
    
    if(TOTAL == 1010 || GRUPOS == 1010)
        break;

    printf("El numero total de grupos de tamano %i es %i\n", GRUPOS, recursiva(TOTAL, GRUPOS));
    }while(true);
    return 0; 
}