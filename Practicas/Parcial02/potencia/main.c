#include "fun.c"

int main(){
	int a,b;
	printf("Ingrese la base\n");
	scanf("%d",&a);
	printf("Ingrese la potencia\n");
	scanf("%d",&b);
	int c = potencia(a,b,1);
	printf("El resultado de %d elevado a la %d es %d\n", a,b,c);
	return 0;
}