#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct nodo{
    int datoN;
	char datoL[3];
	int nR;
    struct nodo *next;
} Nodo;

typedef Nodo *head;

#define MAX 10

head insertarEnLista(head, int, char[]);

head insertarEnLista(head cabeza, int x, char a[3]){
    head aux, tem = cabeza;
    int ey = 0;
    
	while(ey != 10 && tem!=NULL){
        if((tem->datoN==x) && (strcmp(tem->datoL,a)==0)){
            ey=10;
        }else{
            tem = tem->next;
        }
    }
    if(tem == NULL){
		aux = (head)malloc(sizeof(Nodo));
		aux->datoN = x;
		
		strcpy(aux->datoL, a);
		aux->nR=1;
		aux->next = cabeza;
		cabeza = aux;
		return cabeza;
    }else{
		tem->nR=tem->nR+1;
		printf("Ha rebasado  el limite de velocidad %d veces\n", tem->nR);
	}
    return NULL;
}

void imprimirLista(head aux){
    head cabeza=aux;
    if(cabeza != NULL){
        while (cabeza != NULL)
        {
            printf("[%d,%s]->", cabeza->datoN, cabeza->datoL);
            cabeza = cabeza->next;
        }
    }else{
        printf("[]->");
    }
    printf("\n");
}
void imprimirArray(head array[]){
    for (int i = 0; i < MAX; i++){
        imprimirLista(array[i]);
    }
}
//----------------------------------------------------------------
void Create(head []);
void Read(head[], int);
void Update(head[], int, int);
void Delete(head[], int);
void ReadAll(head[]);

int FuncionD(char);
void Restart(head []);

int main(){
    head array[MAX];
    Restart(array);
    Create(array);
    return 0;
}

void Create(head array[]){
    int i, id, v;
	char a[3];
    head aux;
    printf("Datos de la placa\n");
	printf("Ingrese los 3 numeros:\n");
    scanf(" %i", &i);
    v=i;
	printf("Ingrese las 3 letras:\n");
    scanf(" %s", a);
    printf("v vale: %i", v);
    id = FuncionD(a[1]);
    
    aux = array[id];
	if(insertarEnLista(aux, v, a) != NULL){ 
		printf("Es su primera infracción\n");
		array[id]=insertarEnLista(aux, v, a);
	}
	imprimirArray(array);
	printf("Desea continuar? [si=1 / no=0]\n");
	scanf(" %i", &i);
	if(i != 0){
        Create(array);
    }
}

void Restart(head array[])
{
    for (int i = 0; i < MAX; i++)
    {
        array[i] = NULL;
    }
}

int FuncionD(char a){
    int e;
	if(a=='a' || a=='b' || a=='c'){
		e=1;
	}else{
		if(a=='d' || a=='e' || a=='f'){
			e=2;
		}else{
			if(a=='g' || a=='h' || a=='i'){
				e=3;
			}else{
				if(a=='j' || a=='k' || a=='l'){
					e=4;
				}else{
					if(a=='m' || a=='n' || a=='o'){
						e=5;
					}else{
						if(a=='p' || a=='q' || a=='r'){
							e=6;
						}else{
							if(a=='s' || a=='t' || a=='u'){
								e=7;
							}else{
								if(a=='v' || a=='w' || a=='x'){
									e=8;
								}else{
									if(a=='y' || a=='z'){
										e=9;
									}else{
										e=0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return e;
}