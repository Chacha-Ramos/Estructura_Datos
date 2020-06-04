#include <stdio.h>
#include <stdlib.h>


void moveTower(int height,char origin, char destiny, char middle);
void moveDisk(char from, char to);

void moveTower(int height,char origin, char destiny, char middle){
    if(height >= 1){
        moveTower(height-1, origin, middle, destiny);
        moveDisk(origin, destiny);
        moveTower(height-1, middle, destiny, origin);
    }
}

void moveDisk(char from, char to){
    printf("Mover disco de Torre: %c a Torre: %c\n", from, to);
}