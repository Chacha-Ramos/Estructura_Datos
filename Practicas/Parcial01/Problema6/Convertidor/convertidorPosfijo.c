#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Stack.h"

char intrucciones[] = "Se ejecuta asi:\n\t$./a.out \"2+3*(5-4)\"\n\n";

void convertidor(const char *, char []);
bool esOperador(char);
bool esNumero(char);

int main(int argc, char const *argv[]) {
    char result[3];

    if (argc != 2) 
        printf("%s", intrucciones);
    else {
        convertidor(argv[1], result);
        printf("Resultado: %s\n\n", result);
    }
        

    return 0;
}

void convertidor(const char *c, char result[]) {
    Stack *s = createStack();
    int i = 0;
    char aux[] = " ";
    //result[] = "";

    while (c[i] != '\0') {
        if (esNumero(c[i])) {
            aux[0] = c[i];
            strcat(result, aux);
        } else if(c[i] == 40) {
            aux[0] = pop(s);
            strcat(result, aux);
            push(c[i], s);
        } else if(c[i] == 41) {
            while((aux[0] = pop(s)) != '(') {
                strcat(result, aux);
            }
        } else { //Es un operador
            if (c[i] == '*' || c[i] == '/') {
                if (stackTop(s) == 'e') {
                    aux[0] = pop(s);
                    strcat(result, aux);
                    push(c[i], s);
                } else {
                    push(c[i], s);
                }
            } else if (c[i] == '+' || c[i] == '-') {
                if (stackTop(s) == '*' || stackTop(s) == '/') {
                    aux[0] = pop(s);
                    strcat(result, aux);
                    push(c[i], s);
                } else {
                    push(c[i], s);
                }
            } else {
                push(c[i], s);
            }  
        }
        i++;
        printf("%s\n", result);
    }  

    while (!stackEmpty(s)) {
        aux[0] = pop(s);
        strcat(result, aux);
    }  

    //return result;
}

bool esNumero(char c) {
    if ((c > 47) && (c < 58))
        return true;
    
    return false;
}

bool esOperador(char op) {
    return ((op > 41) && (op < 48)) || (op == 'e'); 
}