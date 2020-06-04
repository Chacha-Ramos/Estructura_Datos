#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int info;
    struct nodo *sig;
} nodoL;

typedef nodoL *lista;

void insFront(lista *L, int n);
int mostrar(nodoL *L);
void borrar(lista *L, int n);

void insFront(lista *L, int n)
{
    lista aux = (lista)malloc(sizeof(nodoL));
    aux->info = n;
    aux->sig = *L;
    *L = aux;
}

int mostrar(nodoL *L)
{
    int i = 0;
    if (L != NULL)
    {
        i = 1;
        printf(" |%d|->", L->info);
        mostrar(L->sig);
    }
    return i;
}

void borrar(lista *L, int n)
{
    lista aux = *L;
    (*L) = (*L)->sig;
    free(aux);
}