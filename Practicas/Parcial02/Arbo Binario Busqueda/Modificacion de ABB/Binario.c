#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Binario.h"

void main(){
    bool flag = true;
    int opc, dato, old, new, n;
    printf("Numero de nodos del arbol: ");
    scanf("%d",&n);
    n = abs(n); 
    for(int i = 0;i < n;i++) {
        printf("\n\tElemento No. %d: ",i + 1); 
        dato = rand() % 100;
        printf("%d",dato);
        Insertar(dato);
    }
    Nodo *p ;
    do{
        printf("\nMenu\n");
        printf("1. Eliminar Dato\n");
        printf("2. Modificar Dato\n");
        printf("3. Buscar Dato\n");
        printf("4. Padre de Dato\n");
        printf("5. Hermano de Dato\n");
        printf("6. Hijo Izquierdo\n");
        printf("7. Hijo Derecho\n");
        printf("8. Ver Arbol\n");
        printf("0. Salir\n");
        scanf(" %i", &opc);
        if(opc != 0 && opc != 2 && opc != 8){
            printf("Ingrese dato\n");
            scanf(" %i", &dato);
        }
        switch (opc)
        {
        case 1:
            Eliminar(dato);
            break;
        case 2:
            printf("Ingrese dato a modificar\n");
            scanf(" %i", &old);
            printf("Ingrese nuevo dato\n");
            scanf(" %i", &new);
            Modify(old, new);
            break;
            
        case 3: 
            Find(dato);
            break;

        case 4:
            Padre(dato);
            break;

        case 5:
            Hermano(dato);
            break;

        case 6:
            Hijo_Izq(dato);
            break;

        case 7:
            Hijo_Der(dato);
            break;
        case 8:
            p = Apuntador();
            ver(0, p);
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