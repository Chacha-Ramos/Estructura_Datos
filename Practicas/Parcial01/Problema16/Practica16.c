#include <stdio.h>
#include <stdbool.h>
#include "Lista.h"

void Insertar(Node *, Node *);
void Suma(Node *, Node *);
void Resta(Node *, Node *);
void Multiplicacion(Node *, Node *);
void Division(Node *, Node *);

int main(){
    Node *lista1 = (Node *)malloc(sizeof(Node));
    Node *lista2 = (Node *)malloc(sizeof(Node));
    lista1->next = NULL;
    lista2->next = NULL;
    bool flag = true;
    int opc;

    printf("Ingrese las 2 listas, si ya no quiere ingresar elementos presione 1010\n");
    Insertar(lista1, lista2);

    do{
        printf("Menu\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicacion\n");
        printf("4. Division\n");
        printf("0. Salir\n");
        scanf("%i", &opc);
        switch(opc){
            case 1:
                printf("Suma\n");
                Suma(lista1->next, lista2->next);
                break;
            case 2:
                printf("Resta\n");
                Resta(lista1->next, lista2->next);
                break;
            case 3:
                printf("Multiplicacion\n");
                Multiplicacion(lista1->next, lista2->next);
                break;
            case 4:
                printf("Division\n");
                Division(lista1->next, lista2->next);
                break;
            case 0:
                flag = false;
                break;
            default:
                flag = false;
                break;
        }
    }while(flag);
    
    return 0;
}

void Insertar(Node *lista1, Node *lista2)
{
    printf("Lista 1\n");
    float num, num2;
    bool flag = true;
    do{
        scanf("%f", &num);
        if(num != 1010){
            insert(lista1, num);
        }else{
            flag = false;
        }
    }while(flag);
    flag = true;
    printf("Lista 2\n");
    do
    {
        scanf("%f", &num2);
        if (num2 != 1010){
            insert(lista2, num2);
        }
        else{
            flag = false;
        }
    } while (flag);
}

void Suma(Node *list1, Node *list2)
{
    Node * aux1 = list1, *aux2 = list2;
    if (list1 != NULL && list2 != NULL)
    {
        printf("[%f] + [%f] = %f\n", aux1->numero, aux2->numero, ((aux1->numero) +(aux2->numero)));
        Suma(aux1->next, aux2->next);
    }
}

void Resta(Node *list1, Node *list2)
{
    Node *aux1 = list1, *aux2 = list2;
    if (list1 != NULL && list2 != NULL)
    {
        printf("[%f] - [%f] = %i\n", aux1->numero, aux2->numero, ((aux1->numero) - (aux2->numero)));
        Resta(aux1->next, aux2->next);
    }
}

void Multiplicacion(Node *list1, Node *list2)
{
    Node *aux1 = list1, *aux2 = list2;
    if (list1 != NULL && list2 != NULL)
    {
        printf("[%f] * [%f] = %f\n", aux1->numero, aux2->numero, ((aux1->numero)*(aux2->numero)));
        Multiplicacion(aux1->next, aux2->next);
    }
}

void Division(Node *list1, Node *list2)
{
    Node *aux1 = list1, *aux2 = list2;
    if (list1 != NULL && list2 != NULL)
    {
        printf("[%f] / [%f] = %f\n", aux1->numero, aux2->numero, ((aux1->numero)/(aux2->numero)));
        Division(aux1->next, aux2->next);
    }
}