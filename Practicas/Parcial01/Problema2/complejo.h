#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct comp {
    float re;
    float im;
} complejo;

complejo crearComplejo(float, float);
void imprimeComplejo(complejo);
complejo sumar(complejo, complejo);
complejo restar(complejo, complejo);
complejo multiplicar(complejo, complejo);
complejo dividir(complejo, complejo);
float real(complejo);
float imaginario(complejo);
complejo pedirDatos();
void convertirPolar(complejo);

complejo pedirDatos() {
    float r, i;
    printf("Ingresa la parte real: ");
    scanf("%f", &r);
    printf("Ingresa la parte imaginaria: ");
    scanf("%f", &i);

    return crearComplejo(r, i);
}

complejo crearComplejo(float a, float b) {
    complejo c;
    c.re = a;
    c.im = b;

    return c;
}

void imprimeComplejo(complejo c) {
    printf("C = %.3f + %.3fi\n", c.re, c.im);
}
complejo sumar(complejo a, complejo b) {
    complejo r;
    r.re = a.re + b.re;
    r.im = a.im + b.im;

    return r;
}

complejo restar(complejo a, complejo b) {
    complejo r;
    r.re = a.re - b.re;
    r.im = a.im - b.im;

    return r;
}
complejo multiplicar(complejo a, complejo b) {
    complejo r;
    r.re = (a.re * b.re) - (a.im * b.im);
    r.im = (a.re * b.im) + (a.im * b.re);

    return r;
}

complejo dividir(complejo a, complejo b) {
    complejo r;
    float denominador = pow(a.im, 2) + pow(b.im, 2);
    r.re = ((a.re * b.re) + (a.im * b.im)) / denominador;
    r.im = ((-1) * (a.re * b.im) + (a.im * b.re)) / denominador;

    return r;
}
float real(complejo a) {
    return a.re;
}


float imaginario(complejo a) {
    return a.im;
}

void convertirPolar(complejo a) {
    float r = sqrt(pow(a.re, 2) + pow(a.im, 2));
    float alpha = atan(a.im / a.re);

    printf("La forma polar es->  z = %f(cos(%.3f) + isen(%.3f))\n", r, alpha, alpha);
}
