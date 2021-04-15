#include <stdio.h>

int determinarPar()
{
    int entero;
    printf("Ingrese un entero: ");
    scanf("%d", &entero);
    return entero%2==0;
}