#include "fun.c"

int main(){
	Stack *s = createStack();
	char a[100];
	char b[100];
	printf("Ingrese la primer cadena\n");
	scanf("%[^\n]",a);
	printf("Ingrese la cadena que quiere buscar\n");
	scanf("%s",b);

	contador(a,b,0,s);
	int i=0;
	StackEntry r;
	r = pop(s);
	if (r!=-1){
		printf("Las posiciones en que se repiten la segunda cadena en la primera son:\n");
		while(r!=-1){
			printf(" %d ", r);
			r = pop(s);	
		}
		int efe=0;
	}else{
		printf("No hay coincidencias\n");
	}

	/*
	while(efe<5){
		printf("%d ",pop(s));
		efe++;
	}*/
	
}