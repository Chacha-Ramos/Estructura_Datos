#include <stdio.h>
#include "fun.h"

int potencia(int a, int b, int c){
	return a*(c>=b?1:potencia(a,b,c+1));
}