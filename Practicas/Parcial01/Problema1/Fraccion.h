#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct fracc {
    int numerador;
    int denominador;
}fraccion;

void numerador(fraccion);
void denominador(fraccion);
fraccion crearFraccion(int, int);
void imprimeFraccion(fraccion);
fraccion sumar(fraccion, fraccion);
fraccion restar(fraccion, fraccion);
fraccion multiplicar(fraccion, fraccion);
fraccion dividir(fraccion, fraccion);
fraccion simplificar(fraccion);
fraccion pedirDatos();

fraccion pedirDatos() {
    int n, d;

    printf("Ingrasa el numerador: ");
    scanf("%d", &n);

    do {
        printf("Ingrasa el denominador: ");
        scanf("%d", &d);

        if (d == 0) {
            printf("El denominador no puede ser cero\n");
        }
    } while(d == 0);

    return crearFraccion(n, d);
}

fraccion crearFraccion(int num, int den) {
    fraccion f;
    f.numerador = num;
    f.denominador = den;

    return f;
}

void imprimeFraccion(fraccion f) {
    printf("%d / %d \n", f.numerador, f.denominador);
}

void numerador(fraccion f) {
    printf("%d\n", f.numerador);
}

void denominador(fraccion f) {
    printf("%d\n", f.denominador);
}

fraccion simplificar(fraccion f) {
    int num = f.numerador;
    int den = f.denominador;

    for (int i = 2; i < MAX; ) {
        if (num % i == 0 && den % i == 0) {
            num /= i;
            den /= i;
        }

        if (!(num % i == 0 && den % i == 0)) {
            i++;
        }
    }

    return crearFraccion(num, den);
}

fraccion sumar(fraccion a, fraccion b) {
    fraccion result;
    result.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    result.denominador = a.denominador * b.denominador;
    return simplificar(result);
}

fraccion restar(fraccion a, fraccion b) {
    fraccion result;
    result.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
    result.denominador = a.denominador * b.denominador;
    return simplificar(result);
}

fraccion multiplicar(fraccion a, fraccion b) {
    fraccion result;
    result.numerador = a.numerador * b.numerador;
    result.denominador = a.denominador * b.denominador;
    return simplificar(result);
}

fraccion dividir(fraccion a, fraccion b) {
    fraccion result;
    result.numerador = a.numerador * b.denominador;
    result.denominador = a.denominador * b.numerador;
    return simplificar(result);
}
