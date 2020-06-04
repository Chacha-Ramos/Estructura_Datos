#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Stack.h"

char intrucciones[] = "Se ejecuta asi:\n\t$./a.out 6523+8*-3+*\n\n";

int evaluador(const char *);
int operar(int, int, char);
bool esNumero(char);

int main(int argc, char const *argv[]) {
    if (argc != 2) 
        printf("%s", intrucciones);
    else
        printf("Resultado: %d\n\n", evaluador(argv[1]));

    return 0;
}

int evaluador(const char *c) {
    Stack *s = createStack();
    int a, b, i = 0;
    char tmp[1];

    while (c[i] != '\0') {
        if (esNumero(c[i])) {
            tmp[0] = c[i];
            push((int)atoi(tmp), s);
        } else {
            a = pop(s);
            b = pop(s);
            push(operar(a, b, c[i]), s);
        }
        i++;
    }    

    return stackTop(s);
}

bool esNumero(char c) {
    if (c > 47 && c < 58)
        return true;
    
    return false;
}

int operar(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return b - a;
    case '*':
        return a * b;
    case '/':
        return b / a;
    case 'e':
        return pow(b, a);
    
    default:
        printf("Operacion invalida!\n");
        return -1;
    }
}