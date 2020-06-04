#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Node;

void insert(Node*, int);
void del(Node *, int);
Node *find(Node *, int);
void display(Node*);
void displayBackwards(Node *);

void insert(Node *current, int data)
{
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = (Node *)malloc(sizeof(Node));
    (current->next)->prev = current;
    current = current->next;
    current->data = data;
    current->next = NULL;
}

void del(Node *current, int data)
{
    while (current->next != NULL && (current->next)->data != data)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        printf("El elemento %d no esta en la lista \n", data);
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
    return;
}

Node *find(Node *current, int data)
{
    current = current->next;
    while (current != NULL)
    {
        if (current->data == data)
            return current;
        current = current->next;
    }
    return NULL;
}

void display(Node*current){
    current = current->next;
    while(current != NULL){
        printf("%d\n", current->data);
        current = current->next;
    }
}

void displayBackwards(Node *current){
    Node * head = current;
    current = current ->next;
    while (current != NULL)
    {
        current = current->next;
    }
    while(current != head){
        printf("%d\n", current->data);
        current = current->prev;
    }
}