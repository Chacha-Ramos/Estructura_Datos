#include "Lista.h"
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void Check(Node *);
void Ingresar(Node *);

int main(){
    Node *vuelos;
    bool flag = true;
    int aux;
    printf("Ingrese vuelos\n");
    Ingresar(vuelos);
    while (flag){
        printf("Menu\n");
        printf("Ingresar Vuelos...1\n");
        printf("Checar Vuelos...2\n");
        printf("Imprimir itinerario...3\n");
        printf("Salir...0\n");
        scanf("%i", &aux);
        switch (aux)
        {
            case 1:
                printf("Ingrese vuelos\n");
                Ingresar(vuelos);
                break;
            case 2: 
                Check(vuelos);
                break;
            case 3: 
                displayALL(vuelos);
                break;
            case 0:
                flag = false;
                break;
            default:
                flag = false;
                break;
        }
    }
    return 0;
}

void Ingresar(Node * temp){
    bool flag = true;
    char Destino[255];
    char Compania[255];
    int pasajeros= 0,tiempo=0;
    char c;
    int tiempos[3];
    struct tm *salida = (struct tm*)malloc(sizeof(salida));
    
    printf("Destino: ");
    scanf("%s", Destino);
    printf("Empresa: ");
    scanf("%s", Compania);
    printf("Numero de Pasajeros: ");
    scanf("%i", &pasajeros);
    printf("Hora de salida(HH:MM:SS) 24Hr format:\n");
    scanf("%i", &tiempo);
    tiempos[0] = tiempo;
    scanf("%i", &tiempo);
    tiempos[1] = tiempo;
    scanf("%i", &tiempo);
    tiempos[2] = tiempo;
    insert(temp, Destino, Compania, pasajeros, tiempos);
    printf("Vuelo Ingresado Correctamente, si desea regresar al menu presione *\n");
    scanf(" %c", &c);
    if(c != '*'){
        Ingresar(temp);
    }
}

void Check(Node *vuelos){
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    int ids[100];
    ids[0] = 0;
    Node * aux;

    printf("Hora: %i:%i:%i\n", info->tm_hour, info->tm_min, info->tm_sec);
    findByHour(vuelos, info, ids);
    if(ids[0] == 0){
        printf("NO HA SALIDO NINGUN VUELO\n");
    }else{
        printf("Salieron los siguientes vuelos:\n");
        for (int i = 0; i < ids[0]; i++)
        {
            aux = findById(vuelos, ids[i+1]);
            display(aux);
            del(vuelos, ids[i+1]);
        }
        
    }
}