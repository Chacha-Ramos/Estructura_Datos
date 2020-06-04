#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char StackEntry;

typedef struct node_stack{
    StackEntry entry;
    struct node_stack *next;
} Node;

typedef struct stack{
    Node *top;
} Stack;

Node *createNode(StackEntry);
Stack *createStack();
bool stackEmpty(Stack *);
void push(StackEntry, Stack *);
StackEntry pop(Stack *);
StackEntry stackTop(Stack *);
void printStack(Stack *);
void cleanStack(Stack *);

Node *createNode(StackEntry item)
{
    Node *np = (Node *)malloc(sizeof(Node));

    if (np == NULL)
    {
        printf("Error, no se puede asignar memoria\n");
    }
    else
    {
        np->entry = item;
        np->next = NULL;
    }

    return np;
}

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
}

bool stackEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(StackEntry item, Stack *s)
{
    Node *np = createNode(item);

    if (stackEmpty(s))
    {
        np->next = NULL;
    }
    else
    {
        np->next = s->top;
    }
    s->top = np;
}

StackEntry pop(Stack *s)
{
    StackEntry item;

    if (stackEmpty(s))
    {
        printf("Error, la pila esta vacia pop");
    }
    else
    {
        item = s->top->entry;
        Node *np = s->top;
        s->top = s->top->next;
        free(np);
    }

    return item;
}

StackEntry stackTop(Stack *s)
{
    StackEntry item;

    if (stackEmpty(s))
    {
        printf("Error, la pila esta vacia top\n");
    }
    else
    {
        item = s->top->entry;
    }

    return item;
}

void printStack(Stack *s)
{
    if (!stackEmpty(s))
    {
        Node *tmp = s->top;

        while (tmp->next != NULL)
        {
            printf("[%d]->", tmp->entry);
            tmp = tmp->next;
        }
        printf("[%d]->\n", tmp->entry);
    }
    else
    {
        printf("[ ]\n");
    }
}

void cleanStack(Stack *s)
{
    while (!stackEmpty(s))
    {
        pop(s);
    }
}
