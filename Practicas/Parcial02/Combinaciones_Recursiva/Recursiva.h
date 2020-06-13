int recursiva(int N_Total, int K_Grupos)
{
if (K_Grupos > N_Total) //EL tamaño de los grupos es mas grande que el numero total de elementos 
    return 0;
else if (N_Total == K_Grupos || K_Grupos == 0) //El numero total de elementos es igual al tamaño del grupo o el tamaño del grupo es 0
    return 1;
else 
    return recursiva(N_Total-1, K_Grupos) + recursiva(N_Total-1, K_Grupos-1); //Parte recursiva
}