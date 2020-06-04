#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "quick.h"
#define TAM 10


int main(){
  int v[10] = {15,2,46,78,29,43,61,75,84,55};
  for (int i = 0; i < TAM; i++)
    printf("%d ",v[i]);
  quickSort(v,0,10);
  printf("\nLista ordenada:\n");
  for (int i = 0; i < TAM; i++)
    printf("%d ",v[i]);

  return 0;
}

int pivotar(int v[], int izq, int der){
  int posPiv = (izq+der)/2;
  int valPiv = v[posPiv];
  int indAlmc;
  swap(v,posPiv,der);
  indAlmc=izq;
  for (int indLect = izq; indLect < der; indLect++) {
    if (v[indLect]<=valPiv) {
      swap(v,indLect,indAlmc);
      indAlmc++;
    }
  }
  swap(v,indAlmc,der);
  return indAlmc;
}

void quickSort(int v[], int izq, int der){
  int pivote;
  if (izq<der) {
    pivote = pivotar(v,izq,der);
    quickSort(v,izq,pivote-1);
    quickSort(v,pivote+1,der);
  }
}

void swap(int v[],int ind, int indC){
  int aux;
  aux=v[ind];
  v[ind]=v[indC];
  v[indC]=aux;
}
