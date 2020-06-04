#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char* StackEntry;

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
void push(char *, Stack *);
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

void push(char *item, Stack *s)
{
    Node *np = createNode(item);

    if (stackEmpty(s))
    {
        np->next = NULL;
        strcpy(np->entry, item);
    }
    else
    {
        np->next = s->top;
        strcpy(np->entry, item);
    }
    s->top = np;

    printf("Meti: %s\n", s->top->entry);
    printf("tope %s\n", stackTop(s));
    printStack(s);
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

char* stackTop(Stack *s)
{
    char* item;

    if (stackEmpty(s))
    {
        printf("Error, la pila esta vacia top\n");
    }
    else
    {
        item = (char*)s->top->entry;
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
            printf("[%s]->", tmp->entry);
            tmp = tmp->next;
        }
        printf("[%s]->\n", tmp->entry);
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

void PedirString(Stack *s){
    char String[10];
    scanf("%s", String);
    push(String, s);
    printStack(s);
}

void estudiantes(char * x [], char * y[], char*string[] ){


}

int main(){
    Stack * Nombre = createStack();
    Stack * Promedio = createStack();
    Stack * Aux = createStack();

    //Primer Alumno
    printf("Ingrese el primer alumno\n");
    PedirString(Nombre);
    printStack(Nombre);
    printf("Ingrese el 2do alumno\n");
    PedirString(Nombre);
    printStack(Nombre);
    char *var = stackTop(Nombre);
    printf("El tope de la pila: %s sjhjdhf", var);

    return 0;
}
