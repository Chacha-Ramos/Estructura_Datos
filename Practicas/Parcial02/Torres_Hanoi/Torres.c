#include <stdio.h>
#include <stdlib.h>
#include "Torres.h"

void main(){
    int n;
    printf("Numero de discos:\n");
    scanf("%i", &n);
    moveTower(n, 'A', 'B', 'C');
}