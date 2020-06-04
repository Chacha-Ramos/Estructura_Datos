#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define TAM 10

int main(){

  int a[TAM]={94,12,48,56,79,23,57,61,25,100};
/*  int a[TAM]={1,12,23,25,56,48,57,21,79,94};*/
  int i, pasada, aux,count2=0;
  bool count=false;
  printf("Los datos en orden original son:\n");
  for (i = 0; i < TAM-1; i++)
    printf("%d,",a[i]);
  printf("\n");
  i=0;
  for (pasada = 0; pasada < TAM; pasada++) {
    count=false;
    for (i = 0; i < TAM-pasada-1; i++) {
      if (a[i]>a[i+1]) {
        aux=a[i];
        a[i]=a[i+1];
        a[i+1]=aux;
        count=true;
        /*printf("\ni=%d\n",i);
        for (int z = 0; z < TAM; z++)
          printf("%d ",a[z]);
        */
      }
    }
    for (int j = i; j >pasada; j--) {
      if (a[j]<a[j-1]) {
        aux=a[j];
        a[j]=a[j-1];
        a[j-1]=aux;
        count=true;
        /*printf("\nj=%d\n",i);
        for (int z = 0; z < TAM; z++)
          printf("%d ",a[z]);*/
      }
      count2++;
    }
    if (count==false) {
      printf("\nse salio en la rep: %d\n",count2);
      break;
    }
  }
  printf("\nlos datos ordenados son:\n");
  for (i = 0; i < TAM; i++)
    printf("%d ",a[i]);
}
