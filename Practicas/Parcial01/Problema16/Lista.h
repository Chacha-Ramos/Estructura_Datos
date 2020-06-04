#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 255

typedef struct node
{
    int id;
    float numero;
    struct node *next;
    struct node *prev;
} Node;

void insert(Node *, float);
void del(Node *, int);
Node *findById(Node *, int);
void displayALL(Node *);
void displayALLBackwards(Node *);
void display(Node *);

void insert(Node *current,float numero)
{
    int ids = 0;
    while (current->next != NULL)
    {
        current = current->next;
        ids = current->id;
    }
    ids++;
    current->next = (Node *)malloc(sizeof(Node));
    (current->next)->prev = current;
    current = current->next;
    current->numero = numero;
    current->id = ids;
    current->next = NULL;
}

void del(Node *current, int ids)
{
    while (current->next != NULL && current->next->id != ids)
    {
        current = current->next;
    }
    if (current->next == NULL && current->id != ids)
    {
        printf("El elemento %d no esta en la lista \n", ids);
        return;
    }
    Node *tmp = current->next;
    if (tmp->next == NULL)
    {
        current->next = NULL;
    }
    else
    {
        current->next = tmp->next;
        (current->next)->prev = tmp->prev;
    }
    free(tmp);
}

Node *findById(Node *tmp, int ids)
{
    Node *current = tmp;
    current = current->next;
    while (current != NULL)
    {
        if (current->id == ids)
        {
            return current;
        }
        else
        {
            current = current->next;
        }
    }
    return NULL;
}

void displayALL(Node *tmp)
{
    Node *current = tmp;
    current = current->next;
    if (current == NULL)
    {
        printf("NO HAY VUELOS REGISTRADOS");
        return;
    }
    while (current != NULL)
    {
        printf("Numero: %d\n", current->numero);
        current = current->next;
    }
}

void displayResult(Node *tmp)
{
    Node *current = tmp;
    current = current->next;
    if (current == NULL)
    {
        printf("NO HAY REGISTROS");
        return;
    }
    while (current != NULL)
    {
        printf("Numero: %d\n", current->numero);
        del(tmp, current->id);
        current = current->next;
    }
}

void display(Node *tmp)
{
    Node *current = tmp;
    printf("ID: %d\n", current->id);
    printf("Numero: %d\n", current->numero);
}
