#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

typedef struct nodo avl;
struct nodo{
int dato; 
int altura;
avl *izquierdo; 
avl *derecho;
};

void error(void){
perror("\n\t\aERROR: Memoria insuficiente..."); 
exit(1);
}

/* Crea un nuevo nodo del tipo de la estructura	*/
avl *Nuevo(){
avl *q = (avl *)malloc(sizeof(avl)); 
if(!q) 
    error();
return(q);
}

/* Cuenta el número de nodos en el árbol	*/
int num_nodos(avl *p){  
if(p == NULL) 
    return(0);
return(num_nodos(p -> izquierdo) + 1 + num_nodos(p -> derecho));
}

/* Borra todo el árbol AVL	*/
avl *borrar(avl *p){
if(p != NULL){
    borrar(p -> izquierdo); 
    borrar(p -> derecho); 
    free(p);
}
return(NULL);
}

/* Busca un dato en el árbol	*/
avl *buscar(int dato, avl *p) {
if(p == NULL) 
    return(NULL);
if(dato < p -> dato) 
    return(buscar(dato, p -> izquierdo));
else if(dato > p -> dato) 
    return(buscar(dato, p -> derecho)); 
else 
    return(p);
}

/* Busca el mínimo en el árbol	*/
avl *buscar_min(avl *p) {
if(p == NULL) 
    return(NULL);
else if(p -> izquierdo == NULL) 
    return(p); 
else 
    return(buscar_min( p -> izquierdo ));
}

/* Busca el máximo en el árbol	*/
avl *buscar_max(avl *p) {
if(p != NULL) 
    while(p -> derecho != NULL) 
        p = p -> derecho; 
return(p);
}

/* Calcula la altura del árbol	*/
int altura(avl *p){
if(p == NULL ) 
    return(-1); 
else 
    return(p -> altura);
}
/* Regresa el máximo entre A y B	*/
int Max(int a, int b) {
    return(a > b ? a : b);
}

/* Rotación simple a la izquierda	*/
avl *rot_izq(avl *p) {
avl *q;
q = p -> izquierdo;
p->izquierdo = q -> derecho;
q -> derecho = p;
p->altura = Max(altura(p -> izquierdo ), altura( p -> derecho)) + 1;
q -> altura = Max(altura(q -> izquierdo ), p -> altura) + 1;
return(q);	/* Nueva Raíz	*/
}

/* Rotación simple a la derecha	*/
avl*rot_der(avl *q){
avl*p;
p=q->derecho;
q->derecho = p -> izquierdo;
p -> izquierdo = q;
q->altura = Max(altura(q -> izquierdo), altura(q -> derecho)) + 1; p -> altura = Max(altura(p -> derecho), q -> altura) + 1;
return(p);	/* Nueva raíz	*/
}

/* Rotación doble a la izquierda	*/
avl *rot_dob_izq(avl *k){
k -> izquierdo = rot_der(k -> izquierdo); 
return(rot_izq(k));
}

/* Rotación doble a la derecha	*/
avl *rot_dob_der(avl *q) {
q -> derecho = rot_izq(q -> derecho); 
return(rot_der(q));
}

/* Recorre el árbol en Pre-Orden	*/
void pre_orden(avl *p){
if(p != NULL){
    printf("%d ",p -> dato); 
    pre_orden(p -> izquierdo); 
    pre_orden(p -> derecho);
}
}

/* Recorre el árbol En-Orden	*/
void en_orden(avl *p){
if(p != NULL) {
    en_orden(p -> izquierdo); 
    printf("%d ",p -> dato); 
    en_orden(p -> derecho);
}
}   
/* Recorre el árbol en Post-Orden	*/
void post_orden(avl *p){
if(p != NULL){
    post_orden(p -> izquierdo); 
    post_orden(p -> derecho);
    printf("%d ",p -> dato);
    }
}

/* Inserta un dato en el árbol p	*/
avl *insertar(int dato, avl *p){
if(p == NULL) {
    p = Nuevo();
    p -> dato = dato; p -> altura = 0;
    p -> izquierdo = NULL; p -> derecho = NULL;
} else if(dato < p -> dato) {
    p -> izquierdo = insertar(dato, p -> izquierdo); 
    if((altura(p -> izquierdo) - altura(p -> derecho)) == 2) {
        if(dato < p -> izquierdo -> dato){ 
            p = rot_izq(p);
        }else{ 
            p = rot_dob_izq(p);
        }
    }
} else if(dato > p -> dato) {
    p -> derecho = insertar(dato, p -> derecho);
    if((altura(p -> derecho) - altura(p -> izquierdo)) == 2){ 
        if(dato > p -> derecho -> dato){ 
            p = rot_der(p);
        }else{ 
            p = rot_dob_der(p);
        }
    }
}
p -> altura = Max(altura(p -> izquierdo), altura(p -> derecho)) + 1; 
return(p);
}

/* Pone menú	*/
void menu(void){
printf("\n\tOperaciones con Arboles AVL"); 
printf("\nA = Llenar un arbol de forma aleatoria"); 
printf("\nC = Llenar un arbol de forma manual"); 
printf("\nB = Buscar un dato");
printf("\nM = Buscar Minimo y Maximo"); 
printf("\nN = Contar Nodos y Altura"); 
printf("\nR = Ver Recorridos"); 
printf("\nV = Ver arbol");
printf("\nQ = Salir"); 
printf("\nElija una Opcion : ");
}

/* Recorre y muestra todos los nodos	*/
void ver(int nivel,avl *p){
int i;
if(p != NULL) {
    ver(nivel + 1,p -> derecho);
    printf("\n");
    for(i = 0;i < nivel;i++) 
    printf("	");
    printf("%d",p -> dato); 
    ver(nivel + 1,p -> izquierdo);
}
}

/* Programa principal	*/
int main(void){ 
int n,i,dato; 
char op;
avl *p = NULL,*q;	/* Árbol Vacío	*/ 
while(1){
    menu();
    op = tolower(getch()); 
    switch(op){
        case 'a':
            printf("Numero de nodos del arbol: ");
            scanf("%d",&n);
            n = abs(n); 
            for(i = 0;i < n;i++) {
                printf("\n\tElemento No. %d: ",i + 1); 
                dato = rand() % 100;
                printf("%d",dato);
                p = insertar(dato,p);
            }
        break; 
        case 'c':
            printf("Numero de nodos del arbol: "); 
            scanf("%d",&n);
            n = abs(n); 
            for(i = 0;i < n;i++) {
                printf("\n\tElemento No. %d: ",i + 1); 
                scanf("%d",&dato);
                p = insertar(dato,p);
            }
        break; 
        case 'v':
            printf("Arbol AVL"); 
            ver(0,p);
        break; 
        case 'm':
            q = buscar_min(p); 
            printf("\n\n\tMinimo = %d",q -> dato); 
            q = buscar_max(p); 
            printf("\n\n\tMaximo = %d",q -> dato); 
        break;
        case 'n':
            printf("\n\n\tNodos : %d\n\n\tAltura =%d",num_nodos(p),altura(p)); 
        break;
        case 'b':
            printf("\n\tDato a Buscar: "); 
            scanf("%d",&dato);
            q = buscar(dato,p);
            if(q != NULL) 
                printf("Se encontro el dato %d",dato); 
            else 
                printf("No se encontro el dato %d",dato); 
        break;
        case 'r':
            printf("Recorrido en Pre-Orden:"); 
            pre_orden(p);
            printf("Recorrido En Orden:"); 
            en_orden(p);
            printf("Recorrido en Post-Orden:"); 
            post_orden(p);
        break; 
        case 'q':
            borrar(p);	/* Borra el árbol	*/ 
            exit(1);
        break;
}
        getch();
}
return(0);
}   
