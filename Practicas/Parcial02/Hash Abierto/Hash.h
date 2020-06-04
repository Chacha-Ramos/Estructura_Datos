#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *next;
} Nodo;

typedef Nodo *head;
#define MAX 10


head insertarEnLista(head , int );
void imprimirLista(head);
void borrarLista(head );
head buscar(head , int);
head borrar(head , int);
void imprimirArray(head[]);

void imprimirArray(head array[]){
    for (int i = 0; i < MAX; i++)
    {
        imprimirLista(array[i]);
    }
}

head insertarEnLista(head cabeza, int e)
{
    head aux;
    aux = (head)malloc(sizeof(Nodo));
    aux->valor = e;
    aux->next = cabeza;
    cabeza = aux;
    return cabeza;
}

void imprimirLista(head aux)
{
    head cabeza=aux;
    if(cabeza != NULL){
        while (cabeza != NULL)
        {
            printf("[%d]->", cabeza->valor);
            cabeza = cabeza->next;
        }
    }else{
        printf("[]->");
    }
    printf("\n");
}

void borrarLista(head cabeza)
{
    head actual;

    while (cabeza != NULL)
    {
        actual = cabeza;
        cabeza = cabeza->next;
        free(actual);
    }
}

head buscar(head cabeza, int i){
    head aux = cabeza;
    while (aux != NULL && aux->valor != i)
    {
        aux = aux->next;
    }
    if(aux == NULL){
        printf("No existe el elemento: %i\n", i);
    }
    return aux;
}

head borrar(head aux, int i){
    head tmp;
    while (aux != NULL && aux->valor != i)
    {
        aux = aux->next;
    }
    if (aux == NULL)
    {
        printf("No existe el elemento: %i\n", i);
    }
    else
    {
        if(aux->next == NULL){
            aux = NULL;
        }else{
            tmp = aux;
            aux = aux->next;
            free(tmp);
        }
    }
    return aux;
}