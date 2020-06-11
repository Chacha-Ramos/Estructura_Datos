#include <stdio.h>
#include "fun.h"

int contador(char*a,char*b,int pos,Stack *e){
	
	if (a[pos]!= '\0'){
		if (a[pos]==*b){
			if (something(a,b,pos)){
				push(pos,e);
				contador(a,b,pos+1,e);
			}else{
				contador(a,b,pos+1,e);
			}
		}else{
			contador(a,b,pos+1,e);
		}
	}else{
		return 0;
	}
}

int something(char*a, char*b,int pos){
	int truuu=1;
	while(*b!='\0'){
		if (a[pos]!=*b){
			truuu=0;
			break;
		}
		pos++;
		b++;
	}	
	return truuu;
}