#include "PilaString.h"
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>


void PushString();
int Ordenar(char[], char[]);
void GetMax(int);

int main(){

    char Promedio[MAX];
    char Nombres[MAX];
    int posicion = 0, ayuda = 0;
    for(int i = 1; i<=3; i++){
        PushString();
    }
    GetMax(3);
    for (int i = 1, j = 1; i < 57; i++, j++)
    {   
        PushString();
        if(j==3){
            j =0;
            posicion = Ordenar(Nombres, Promedio);
            GetMax(posicion);
        }
    }
    for (int i = 1; i < 40; i++)
    {
        posicion = Ordenar(Nombres, Promedio);
        GetMax(posicion);
    }    
    return 0;
}

void PushString(){
    char Promedio[MAX];
    char Nombres[MAX];
    printf("Ingrese alumnno (Nombre y Promedio)\n");
    scanf("%s", Nombres);
    scanf("%s", Promedio);
    if(!push(Nombres, Promedio))

        printf("Error");  
}

int Ordenar(char Nombres[], char Promedio[]){
    int posicion = 1, i = 1;
    float max = 0, aux = 0;
    while(pop(Nombres, Promedio)){
        pushAux(Nombres, Promedio);
        aux = (float)atof(Promedio);
        if(aux > max){
            max = aux;
            posicion = i;
        }
        i++;
    }
    reset();
    return posicion;
}

void GetMax(int posicion){
    char Promedio[MAX];
    char Nombres[MAX];
    for (int i = 1; i <= posicion; i++)
    {
        pop(Nombres, Promedio);
        if(i != posicion)
            pushAux(Nombres, Promedio);
    }
    printf("Se esta atendiendo a: %s\n", Nombres);
    printf("Con promedio de: %s\n", Promedio);
    reset();
}