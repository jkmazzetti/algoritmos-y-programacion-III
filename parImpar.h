#include <stdio.h>
#include <math.h>

void determinarPar()
{
    int entero;
    printf("Ingrese un entero: ");
    scanf("%d", &entero);
    printf("El numero %d",entero);
    if(pow((double)(-1),(double)(entero))>0){
        printf(" es par.");
    }else{
        printf(" es impar.");
    }
}