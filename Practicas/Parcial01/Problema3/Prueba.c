#include "pila.h"
#include<stdio.h>

int main()
{
    StackEntry c;
    Stack s;
    bool flag = 1;
    CreateStack(&s);
    int opc = 0;

    printf("Ingrese datos para la pila\nSi no quiere ingresar mas datos presione *\n");
    for (int i = 0; i < 10; i++){
        scanf(" %c", &c);
        if (c != '*'){
            Push(c, &s);
        }else{
            break;
        }
    }
    while (flag){
        printf("\n\nMenu\n");
        printf("1. Nuevo Dato\n");
        printf("2. Borrar Ultimo Elemento\n");
        printf("3. Checar Vacio\n");
        printf("4. Checar Lleno\n");
        printf("5. Ultimo Elemento\n");
        printf("0. Salir\n");
        scanf("%i", &opc);

        switch (opc){
        case 1:
            c = ' ';
            printf("Ingrese dato para la pila\n");
            scanf(" %c", &c);
            Push(c, &s);
            printf("Se ingreso el dato correctamente en la pila\n");
            break;

        case 2:
            c = ' ';
            Pop(&c, &s);
            if (c != ' '){
                printf("Se elimino el ultimo dato\n");
            }
            break;

        case 3:
            if (StackEmpty(&s) == 0){
                printf("No esta vacio el stack");
            }
            else{
                printf("Esta vacio el stack");
            }
            break;

        case 4:
            if (StackFull(&s) != 0){
                printf("Esta lleno el stack");
            }
            else{
                printf("No esta lleno el stack");
            }
            break;

        case 5:
            c = ' ';
            StackTop(&c, &s);
            if(c != ' '){
            printf("Este es el ultimo elemento del stack: %c", c);
            }
            break;

        default:
            flag = 0;
        }
    }

    return 0;
}
