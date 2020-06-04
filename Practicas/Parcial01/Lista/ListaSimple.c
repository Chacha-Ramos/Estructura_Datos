#include <stdio.h>
#include <stdlib.h>

typedef struct snodo
{
	int id;
	struct snodo *sig;
} tnodo;			   

typedef tnodo *tpuntero;

void insertarEnLista(tpuntero *cabeza, int e);
void imprimirLista(tpuntero cabeza);
void borrarLista(tpuntero *cabeza);

int main()
{
	int e;
	tpuntero cabeza; 

	printf("Ingrese elementos, -1 para terminar: ");
	scanf("%d", &e);

	while (e != -1)
	{
		insertarEnLista(&cabeza, e);
		printf("Ingresado correctamente");
		printf("\n");
		printf("Ingrese elementos, -1 para terminar: ");
		scanf("%d", &e);
	}

	printf("\nSe imprime la lista cargada: ");
	imprimirLista(cabeza);

	printf("\nSe borra la lista cargada\n");
	borrarLista(&cabeza);

	printf("\n");
	system("PAUSE");

	return 0;
}

void insertarEnLista(tpuntero *cabeza, int e)
{
	tpuntero nuevo;				  
	nuevo = malloc(sizeof(tnodo)); 
	nuevo->valor = e;			   
	nuevo->sig = *cabeza;		  
	*cabeza = nuevo;			  
}

void imprimirLista(tpuntero cabeza)
{
	while (cabeza != NULL)
	{								 
		printf("%4d", cabeza->valor); 
		cabeza = cabeza->sig;		
	}
}

void borrarLista(tpuntero *cabeza)
{
	tpuntero actual;

	while (*cabeza != NULL)
	{							  
		actual = *cabeza;		 
		*cabeza = (*cabeza)->sig; 
		free(actual);
	}
}