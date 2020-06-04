#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 255

typedef struct node{
    int id;
    char destino[MAX];
    char compania[MAX];
    int pasajeros;
    int tiempo[3];
    struct node *next;
    struct node *prev;
} Node;

void insert(Node *, char [], char [], int , int[]);
void del(Node *, int);
Node *findById(Node *, int);
void findByHour(Node *, struct tm *, int[]);
void displayALL(Node *);
void displayALLBackwards(Node *);
void display(Node *);

void insert(Node *current, char destino[], char compania[], int pasajeros, int salida[])
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
    current->pasajeros = pasajeros;
    (current->tiempo)[0] = salida[0];
    (current->tiempo)[1] = salida[1];
    (current->tiempo)[2] = salida[2];
    strcpy(current->compania, compania);
    strcpy(current->destino, destino);
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
        if (current->id == ids){
            return current;
        }else{
            current = current->next;
        }
    }
    return NULL;
}

void findByHour(Node *tmp, struct tm *salida, int ids[])
{
    Node *current = tmp;
    int aux=1;
    current = current->next;
    while (current != NULL)
    {
        if ((current->tiempo[0]) <= (salida->tm_hour))
        {
            if ((current->tiempo[0]) == (salida->tm_hour)){
                if ((current->tiempo[1]) <= (salida->tm_min))
                {
                    ids[aux] = current->id;
                    ids[0] += 1;
                    aux++;
                }
            }else{
                ids[aux] = current->id;
                ids[0] += 1;
                aux++;
            }
        }
        current = current->next;
    }
}

void displayALL(Node *tmp)
{
    Node *current = tmp;
    current = current->next;
    if(current == NULL){
        printf("NO HAY VUELOS REGISTRADOS\n");
        return;
    }
    while (current != NULL)
    {
        printf("ID: %d\n", current->id);
        printf("Destino: %s\n", current->destino);
        printf("Empresa: %s\n", current->compania);
        printf("Numero de Pasajeros: %d\n", current->pasajeros);
        printf("Hora de salida: %d:%d:%d\n", (current->tiempo[0]), (current->tiempo[1]), (current->tiempo[2]));
        current = current->next;
    }
}

void displayALLBackwards(Node *tmp)
{
    Node *current = tmp;
    Node *head = current;
    current = current->next;
    while (current != NULL)
    {
        current = current->next;
    }
    while (current != head)
    {
        printf("ID: %d\n", current->id);
        printf("Destino: %s\n", current->destino);
        printf("Empresa: %s\n", current->compania);
        printf("Numero de Pasajeros: %d\n", current->pasajeros);
        printf("Hora de salida: %d:%d:%d\n", (current->tiempo[0]), (current->tiempo[1]), (current->tiempo[2]));
        current = current->prev;
    }
}

void display(Node *tmp)
{
    Node * current = tmp;
    printf("ID: %d\n", current->id);
    printf("Destino: %s\n", current->destino);
    printf("Empresa: %s\n", current->compania);
    printf("Numero de Pasajeros: %d\n", current->pasajeros);
    printf("Hora de salida: %d:%d:%d\n", (current->tiempo[0]), (current->tiempo[1]), (current->tiempo[2]));
}
