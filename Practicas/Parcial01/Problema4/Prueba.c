#include "Stack.h"
#include <stdio.h>

#define type "%d"

bool ejecutar(int, Stack *);
int menu();

int main() {
    bool flag = true;
    Stack *s = createStack();

    do {
        flag = ejecutar(menu(), s);
    } while(flag);

}

int menu() {
    int opc;

    printf("\n\nMenu\n");
    printf("1. Ingresar nuevo Dato\n");
    printf("2. Borrar Elemento\n");
    printf("3. Revisar si esta Vacia\n");
    printf("4. Ver ultimo Elemento\n");
    printf("5. Imprimir Stack\n");
    printf("6. Vaciar Stack\n");
    printf("0. Salir\n");
    printf("Entrada: ");
    scanf("%i", &opc);

    return opc;
}

bool ejecutar(int opc, Stack *s) {
    StackEntry c;
    printf("\n\n");

    switch (opc){
        case 0:
            return false; 
        case 1:
            printf("Ingrese dato: ");
            scanf("%d", &c);
            push(c, s);
            printf("Se ingreso el dato %d correctamente en la pila\n", stackTop(s));
            break;

        case 2:
            if (!stackEmpty(s)) {
                c = pop(s);
                printf("Se elimino %d de la pila.", c);
            } else {
                printf("La pila esta vacia.");
            }
            break;

        case 3:
            if (stackEmpty(s))
                printf("La pila esta vacia\n");
            else
                printf("La pila NO esta vacia");
        
            break;

        case 4:
            if (!stackEmpty(s)) {
                c = stackTop(s);
                printf("Este es el ultimo elemento del stack: %d", c);
            } else {
                printf("La pila esta vacia.");
            }
            break;

        case 5:
            printStack(s);
            break;

        case 6:
            cleanStack(s);
            break;

        default:
            printf("Opcion no valida, trata de nuevo\n");
    }

    return true;
}
