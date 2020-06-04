#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Binario.h"

void main(){
    bool flag = true;
    int opc, dato, old, new;

    do{
        printf("Menu\n");
        printf("1. Ingresar Datos\n");
        printf("2. Eliminar Dato\n");
        printf("3. Modificar Dato\n");
        printf("4. Buscar Dato\n");
        printf("5. Padre de Dato\n");
        printf("6. Hermano de Dato\n");
        printf("7. Hijo Izquierdo\n");
        printf("8. Hijo Derecho\n");
        printf("0. Salir\n");
        scanf(" %i", &opc);
        if(opc != 0 && opc != 3){
            printf("Ingrese dato\n");
            scanf(" %i", &dato);
        }
        switch (opc)
        {
        case 1:
            Insertar(dato);
            break;
        case 2:
            Eliminar(dato);
            break;
        case 3:
            printf("Ingrese dato a modificar\n");
            scanf(" %i", &old);
            printf("Ingrese nuevo dato\n");
            scanf(" %i", &new);
            Modify(old, new);
            break;
            
        case 4: 
            Find(dato);
            break;

        case 5:
            Padre(dato);
            break;

        case 6:
            Hermano(dato);
            break;

        case 7:
            Hijo_Izq(dato);
            break;

        case 8:
            Hijo_Der(dato);
            break;

        case 0:
            flag = false;
            break;
        
        default:
            flag=false;
            break;
        }

    }while(flag);
}