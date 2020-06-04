#include<stdio.h>
#include<stdlib.h>

typedef int Entry;

typedef struct nodo{
	struct nodo *next;
	Entry dato;
} nodo;

typedef struct cola{
	nodo *f;
	nodo *r;
	int id;
	struct cola *nextc;
} cola;


void encolar(Entry, cola *);
void desencolar(cola *);
Entry frente(cola *);
void print(cola *);

void invertir(cola *);

cola *concate(cola *, cola *);


void encolar(Entry a, cola *x){
	nodo *temp = (nodo *)malloc(sizeof(nodo));
	nodo *tempo = (nodo *)malloc(sizeof(nodo));
	temp->dato=a;
	
	if(x->f==NULL && x->r==NULL){
		temp->next=NULL;
		x->f=x->r=temp;
		
		return;
	}
	
	x->r->next=temp;
	x->r=x->r->next;
	
	print(x);
	return;
}

void desencolar(cola *x){
	Entry a;
	nodo *temp=x->f;
	if(x->f==NULL){
		printf("La cola esta vacia\n");
		return;
	}
	
	if(x->f==x->r){
		x->f=x->r=NULL;
	}else{
		x->f=x->f->next;
	}
	
	free(temp);
}

void print(cola *x){
	nodo *temp=x->f;
	printf("🏡");
	while(temp!=NULL){
		printf("<-[%d]", temp->dato);
		temp=temp->next;
	}
	printf("\n");
}

void main(){
	int b, c, opc, a, num=0,x,i=0,o,p,tere=0;
	char sn;
	cola *tem = (cola *)malloc(sizeof(cola));
	cola *tem1 = (cola *)malloc(sizeof(cola));
	cola *tem2 = (cola *)malloc(sizeof(cola));
	cola *xx = (cola *)malloc(sizeof(cola));
	cola *yy = (cola *)malloc(sizeof(cola));

	cola *lista[2];
	do{
		printf("----------Menú----------\n");
		printf("1.- Crear cola\n");
		printf("2.- Inversa de una cola\n");
		printf("3.- Concatenar colas\n");
		printf("Ingrese el numero de la opcion que desea:");
		scanf("%d", &opc);
		switch(opc){
			case 1:
				if(tere==2){
					printf("Ya hay dos colas\n");
					break;
				}else{
					if(tere==0){
						printf("Cuantos datos va a meter?");
						scanf("%d", &a);
						while(i<a){
							printf("Ingrese dato %d:", i);
							scanf("%d", &x);
							encolar(x, tem1);
							i++;
						}	
						lista[num]=tem1;
					}else{
						printf("Cuantos datos va a meter?");
						scanf("%d", &a);
						while(i<a){
							printf("Ingrese dato %d:", i);
							scanf("%d", &x);
							encolar(x, tem2);
							i++;	
						}
						lista[num]=tem2;		
					}
				}
				
				
				
			
				printf("Se guardo como cola %d\n", num);
				num++;
				i=0;
				tere++;
				
				break;
			case 2:
				
				printf("Ingrese la cola a invertir [0/1]:");
				scanf("%d", &b);
				
				invertir(lista[b]);
				
				
				
				
				break;
			case 3:
				
				
				printf("Ingrese la primera cola:");
				scanf("%d", &o);
				printf("Ingrese la segunda cola:");
				scanf("%d", &p);
				xx=lista[o];
				yy=lista[p];
				tem=concate(xx, yy);
				printf("La cola concatenada es:");
				print(tem);
				break;
			default:
				printf("Opcion no valida\n");
				break;
		}
		printf("Desea continuar? [s/n]");
		scanf("%s", &sn);
	}while(sn=='s');
}

cola *concate(cola *base, cola *otra){
	cola *tem = (cola *)malloc(sizeof(cola));
	nodo *temp = (nodo *)malloc(sizeof(nodo));
	tem=base;
	temp=tem->f;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=otra->f;
	return tem;
}

void invertir(cola *x){
	nodo *temp = x->f;
	nodo *temp1 = x->f;
	
	int i=0, j=0;
	printf("🏡");
	while(temp!=NULL){
		printf("<-[%d]", temp->dato);
		temp=temp->next;
		i++;
	}
	printf("La cola invertida es:\n");
	printf("🏡");
	while(i!=0){
		temp1=x->f;
		while(j<i){
			if(i-j==1)
				printf("<-[%d]", temp1->dato);
			
			temp1=temp1->next;
			j++;
		}
		
		i--;
		j=0;
		
	}
	
}