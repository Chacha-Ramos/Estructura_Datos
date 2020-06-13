#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct nodo{
    int nivel; 
    int info;
    struct nodo * izq; 
    struct nodo * der;
}Nodo;
 
Nodo * raiz = NULL;
Nodo * ziar = NULL;

bool Insertar(int);
bool Eliminar(int);
bool Find(int);
bool Modify(int, int);
void Padre(int);
void Hermano(int);
void Hijo_Izq(int);
void Hijo_Der(int);
void Preorden(Nodo*);
void Inorden(Nodo*);
void Postorden(Nodo*);
void TotalNodos(Nodo*, int*);
void Altura(Nodo*, int*);
void Invertir(Nodo*);
bool InsertarInver(int);

bool Insertar(int dato){
    Nodo* nuevo;
    int nivel = 1;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = dato;
    nuevo->der = NULL; 
    nuevo->izq = NULL;
    if(raiz == NULL){
        nuevo->nivel = nivel;
        raiz = nuevo;
    }else{
        Nodo * anterior, * head;
        anterior = NULL;
        head = raiz;
        while (head != NULL)
        {
            nivel++;
            anterior = head;
            if(dato <= head->info){
                head = head->izq;
            }else{
                head = head->der;
            }
        }
        nuevo ->nivel = nivel;
        if(dato <= anterior->info){
            anterior->izq = nuevo;
        }else{
            anterior->der = nuevo;
        }
    }
    return true;
}

bool Modify(int old, int new){
    if(Eliminar(old)){
        Insertar(new);
        return true;
    }else{
        printf("No se pudo modificar el elemento\n");
        return false;
    }
}

bool Find(int dato){
    Nodo * anterior, * head;
    anterior = NULL;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        anterior = head;
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if(i != 0){
        printf("Se encontro el elemento\n");
        return true;
    }else{
        printf("No se encontro el elemento\n");
        return false;
    }
}

bool Eliminar(int dato){
    Nodo * anterior, * head;
    anterior = NULL;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        anterior = head;
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if(i != 0){
        if(i == 1){
            printf("No se puede eliminar por que el elemento es la raiz\n");
            return false;
        }else{
            if(dato < anterior->info){
                anterior = head->izq;
            }else{
                anterior = head->der;
            }
            free(head);
            return true;
        }
    }else{
        printf("No se encontro el elemento\n");
        return false;
    }
}

void Padre(int dato){
    Nodo * anterior, * head;
    anterior = NULL;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        anterior = head;
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if (i == 0){
        printf("No se encuentra el elemento\n");
    }else{
        if(anterior != NULL){
            printf("El elemento padre es: %i\n", anterior->info);
        }else{
            printf("El elemento es la raiz\n");
        }
    }
}

void Hermano(int dato){
    Nodo * anterior, * head;
    anterior = NULL;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        anterior = head;
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if (i == 0){
        printf("No se encuentra el elemento\n");
    }else{
        if(anterior != NULL){
            if(dato < anterior->info){
                if(anterior->der == NULL){
                    printf("El elemento no tiene ningun hermano\n");
                }else{
                    printf("Su hermano es: %i\n", anterior->der->info);
                }
            }else{
                if(anterior->izq == NULL){
                    printf("El elemento no tiene ningun hermano\n");
                }else{
                    printf("Su hermano es: %i\n", anterior->izq->info);
                }
            }
        }else{
            printf("El elemento es la raiz\n");
        }
    }
}

void Hijo_Izq(int dato){
    Nodo * head;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if(i == 0){
        printf("No se encuentra el elemento\n");
    }else{
        if(head->izq == NULL){
            printf("No tiene hijo del lado izquierdo\n");
        }else{
            printf("Hijo Izquierdo: %i\n", head->izq->info);
        }
    }
}

void Hijo_Der(int dato){
    Nodo * head;
    head = raiz;
    int i = 0;
    while (head != NULL)
    {
        if(head->info == dato){
            i = head->nivel;
            break;
        }
        if(dato < head->info){
            head = head->izq;
        }else{
            head = head->der;
        }
    }
    if(i == 0){
        printf("No se encuentra el elemento\n");
    }else{
        if(head->der == NULL){
            printf("No tiene hijo del lado derecho\n");
        }else{
            printf("Hijo Derecho: %i\n", head->der->info);
        }
    }
}

void Preorden(Nodo* arbol){
	if(arbol == NULL){
		printf(" - ");
	}else{
		printf("( %i ", arbol->info);
		Preorden(arbol->izq);
		Preorden(arbol->der);
		printf(" )");
	}
}

void Inorden(Nodo* arbol){
	if(arbol == NULL){
		printf(" - ");
	}else{
		printf("( ");
		Inorden(arbol->izq);
		printf(" %i ", arbol->info);
		Inorden(arbol->der);
		printf(" )");
	}
}

void Postorden(Nodo* arbol){
	if(arbol == NULL){
		printf(" - ");
	}else{
		printf("( ");
		Postorden(arbol->izq);
		Postorden(arbol->der);
		printf(" %i ", arbol->info);
		printf(" )");
	}
}

void TotalNodos(Nodo* arbol, int* tn){
	if(arbol != NULL){
		*tn=(*tn)+1;
		TotalNodos(arbol->izq, tn);
		TotalNodos(arbol->der, tn);
	}
}

void Altura(Nodo* arbol, int* h){
	if(arbol != NULL){
		if(*h < arbol->nivel){
			*h=arbol->nivel;
		}
		Altura(arbol->izq, h);
		Altura(arbol->der, h);
	}
}

bool InsertarInver(int dato){
    Nodo* nuevo;
    int nivel = 1;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = dato;
    nuevo->der = NULL; 
    nuevo->izq = NULL;
    if(ziar == NULL){
        nuevo->nivel = nivel;
        ziar = nuevo;
    }else{
        Nodo * anterior, * head;
        anterior = NULL;
        head = ziar;
        while (head != NULL)
        {
            nivel++;
            anterior = head;
            if(dato >= head->info){
                head = head->izq;
            }else{
                head = head->der;
            }
        }
        nuevo ->nivel = nivel;
        if(dato >= anterior->info){
            anterior->izq = nuevo;
        }else{
            anterior->der = nuevo;
        }
    }
    return true;
}

void Invertir(Nodo* arbol){
	if(arbol != NULL){
		InsertarInver(arbol->info);
		Invertir(arbol->izq);
		Invertir(arbol->der);
	}
}


void main(){
    bool flag = true;
    int opc, dato, old, new, tn = 0, h = 0;

    do{
        printf("\nMenu\n");
        printf("1.  Ingresar Datos\n");
        printf("2.  Eliminar Dato\n");
        printf("3.  Modificar Dato\n");
        printf("4.  Buscar Dato\n");
        printf("5.  Padre de Dato\n");
        printf("6.  Hermano de Dato\n");
        printf("7.  Hijo Izquierdo\n");
        printf("8.  Hijo Derecho\n");
		printf("9.  Imprimir Preorden\n");
		printf("10. Imprimir Inorden\n");
		printf("11. Imprimir Postorden\n");
		printf("12. Imprimir el total de nodos\n");
		printf("13. Imprimir altura del arbol\n");
		printf("14. Imprimir inversa\n");
        printf("0.  Salir\n");
        scanf(" %i", &opc);
        if(opc != 0 && opc != 3 && opc < 9){
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
		case 9:
			Preorden(raiz);
			break;
		case 10:
			Inorden(raiz);
			break;
		case 11:
			Postorden(raiz);
			break;
		case 12:
			TotalNodos(raiz, &tn);
			printf("El total de nodos es: %i", tn);
			break;
		case 13:
			Altura(raiz, &h);
			printf("La altura del arbol es: %i", h);
			break;
		case 14:
			Invertir(raiz);
			Preorden(ziar);
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