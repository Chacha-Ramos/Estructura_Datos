#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Torres.h"

void main(){
    int n;
    printf("Torres Hanoi\n");
    printf("Digite 1010 para salir del programa\n");
    do{
    printf("Numero de discos:\n");
    scanf("%i", &n);
    if(n == 1010)
        break;
    moveTower(n, 'A', 'B', 'C');
    }while(true);
}