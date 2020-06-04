#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Hash.h"

void Create(head []);
void Read(head[], int);
void Update(head[], int, int);
void Delete(head[], int);
void ReadAll(head[]);

int Modulo(int);
void Restart(head []);

int main(){
    head array[MAX];
    Restart(array);
    Create(array);
    bool flag = true;
    int opc, id, original, modified; 

    do{
        printf("Menu\n");
        printf("1. Ingresar Datos\n");
        printf("2. Buscar Dato\n");
        printf("3. Modificar Dato\n");
        printf("4. Borrar Dato\n");
        printf("5. Imprimir Tabla\n");
        printf("6. Borrar Tabla\n");
        printf("0. Salir\n");
        scanf(" %i", &opc);

        switch (opc)
        {
        case 1:
            Create(array);
            break;
        case 2:
            printf("Ingresar dato que quiere buscar\n");
            scanf("%i", &id);
            Read(array, id);
            break;

        case 3:
            printf("Ingresar dato que quiere modificar\n");
            scanf("%i", &original);
            printf("Ingresar nuevo dato\n");
            scanf("%i", &modified);
            Update(array, original, modified);
            break;

        case 4:
            printf("Ingresar dato que quiere borrar\n");
            scanf("%i", &id);
            Delete(array, id);
            break;

        case 5:
            ReadAll(array);
            break;

        case 6:
            Restart(array);
            break;

        case 0:
            flag = false;
            break;
        
        default:
            flag=false;
            break;
        }

    }while(flag);
    return 0;
}

void Create(head array[]){
    int i, id;
    head aux;
    printf("Ingresar dato, si ya no quiere ingresar otro dato digite 1010\n");
    scanf(" %i", &i);
    if(i != 1010){
        id = Modulo(i);
        aux = array[id];
        array[id]=insertarEnLista(aux, i);
        Create(array);
    }
}

void Read(head aux[], int i){
    int id = Modulo(i);
    head tmp = buscar(aux[id], i);
    if (tmp != NULL)
    {
        imprimirLista(tmp);
    }
}

void ReadAll(head aux[]){
    imprimirArray(aux);
}

void Update(head aux[], int i, int j){
    int id = Modulo(i);
    head tmp = buscar(aux[id], i);
    if (tmp != NULL)
    {
        aux[id] = borrar(tmp, i);
        id = Modulo(j);
        tmp = aux[id];
        aux[id] = insertarEnLista(tmp, j);
    }
}

void Delete(head aux [], int i){
    int id = Modulo(i);
    head tmp = buscar(aux[id], i);
    if (tmp != NULL)
    {
        aux[id]=borrar(tmp, i);
    }
}

void Restart(head array[])
{
    for (int i = 0; i < MAX; i++)
    {
        array[i] = NULL;
    }
}

int Modulo(int i){
    return i%MAX;
}