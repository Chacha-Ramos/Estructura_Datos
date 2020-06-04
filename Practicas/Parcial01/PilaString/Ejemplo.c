#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

typedef struct Node
{
    char nombre[MAX];
    char promedio[MAX];
    struct Node *previousNode;
} Node;

Node *PointerTopNombre = NULL;

int push(char[], char[]);
int pop(char[], char[]);
int top(char[], char[]);
void printStack(void);

int main(void)
{
    char Promedio[MAX];
    char Nombres[MAX];
    int promedio;
    for (int i = 0; i < 4; i++)
    {
        printf("Ingrese el primer alumno (Nombre y Promedio)\n");
        scanf("%s", Nombres);
        scanf("%s", Promedio);
        if (!push(Nombres, Promedio))
        {
            printf("Something went horribly wrong pushing data, but the program will carry on\n");
        }
    }
    
    if (pop(Nombres, Promedio)){
        printf("Nombre POP: %s\n", Nombres);
        printf("Promedio POP: %s\n", Promedio);
    }else
        printf("Error Popping Data\n");
    
    printf("\n\nPrinting Data\n---\n");
    PrintStack();
    return 1;
}

void PrintStack(void)
{
    Node *tmp = PointerTopNombre;
    while (tmp != NULL)
    {
        printf("%s\n", tmp->nombre);
        printf("%s\n", tmp->promedio);
        tmp = tmp->previousNode;
    };
    return;
}

int top(char nombre[], char promedio[]){
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
    Node *PreviousNodePointer = PointerTopNombre->previousNode;
    free(PointerTopNombre);
    PointerTopNombre = PreviousNodePointer;
    return 1;
}

int push(char nombre[], char promedio[])
{
    Node *NewNodePointer = (Node*)malloc(sizeof(Node));
    if (!NewNodePointer)
        return 0;
    strcpy(NewNodePointer->nombre, nombre);
    strcpy(NewNodePointer->promedio, promedio);
    NewNodePointer->previousNode = PointerTopNombre;
    PointerTopNombre = NewNodePointer;
    return 1;
}