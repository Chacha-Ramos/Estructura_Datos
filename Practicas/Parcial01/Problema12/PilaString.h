#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

typedef struct NodeNombre{
    char nombre[MAX];
    char promedio[MAX];
    struct Node *previousNode;
} NodeNombre;

NodeNombre *PointerTopNombre = NULL;

typedef struct NodeAux{
    char nombre[MAX];
    char promedio[MAX];
    struct Node *previousNode;
} NodeAux;

NodeAux *PointerTopAux = NULL;

//Original
int push(char[], char[]);
int pop(char[], char[]);
int top(char[], char[]);
void printStack(void);
//Auxiliar
int pushAux(char[], char[]);
int popAux(char[], char[]);
int topAux(char[], char[]);
void printStackAux(void);
//Reset
int reset();

void printStack(void)
{
    NodeNombre *tmp = PointerTopNombre;
    while (tmp != NULL)
    {
        printf("%s\n", tmp->nombre);
        printf("%s\n", tmp->promedio);
        tmp = (NodeNombre *)tmp->previousNode;
    };
    return;
}

int top(char nombre[], char promedio[])
{
    if (PointerTopNombre == NULL)
        return 0;
    strcpy(nombre, PointerTopNombre->nombre);
    strcpy(nombre, PointerTopNombre->promedio);
    return 1;
}

int pop(char nombre[], char promedio[])
{
    if (PointerTopNombre == NULL)
        return 0;
    strcpy(nombre, PointerTopNombre->nombre);
    strcpy(promedio, PointerTopNombre->promedio);
    NodeNombre *PreviousNodePointer = (NodeNombre *)PointerTopNombre->previousNode;
    free(PointerTopNombre);
    PointerTopNombre = PreviousNodePointer;
    return 1;
}

int push(char nombre[], char promedio[])
{
    NodeNombre *NewNodePointer = (NodeNombre*)malloc (sizeof(NodeNombre));
    if (!NewNodePointer)
        return 0;
    strcpy(NewNodePointer->nombre, nombre);
    strcpy(NewNodePointer->promedio, promedio);
    NewNodePointer->previousNode = PointerTopNombre;
    PointerTopNombre = NewNodePointer;
    return 1;
}

//Auxiliar
void printStackAux(void)
{
    NodeAux *tmp = PointerTopAux;
    while (tmp != NULL)
    {
        printf("%s\n", tmp->nombre);
        printf("%s\n", tmp->promedio);
        tmp = (NodeAux *)tmp->previousNode;
    };
    return;
}

int topAux(char nombre[], char promedio[])
{
    if (PointerTopAux == NULL)
        return 0;
    strcpy(nombre, PointerTopAux->nombre);
    strcpy(nombre, PointerTopAux->promedio);
    return 1;
}

int popAux(char nombre[], char promedio[])
{
    if (PointerTopNombre == NULL)
        return 0;
    strcpy(nombre, PointerTopAux->nombre);
    strcpy(promedio, PointerTopAux->promedio);
    NodeAux *PreviousNodePointer = (NodeAux *)PointerTopAux->previousNode;
    free(PointerTopAux);
    PointerTopAux = PreviousNodePointer;
    return 1;
}

int pushAux(char nombre[], char promedio[])
{
    NodeAux *NewNodePointer = (NodeAux *)malloc(sizeof(NodeAux));
    if (!NewNodePointer)
        return 0;
    strcpy(NewNodePointer->nombre, nombre);
    strcpy(NewNodePointer->promedio, promedio);
    NewNodePointer->previousNode = PointerTopAux;
    PointerTopAux = NewNodePointer;
    return 1;
}

int reset(){
    char nombre[MAX];
    char promedio[MAX];
    while (PointerTopAux != NULL)
    {
        popAux(nombre, promedio);
        push(nombre, promedio);
        nombre[MAX];
        promedio[MAX];
    }
    
}