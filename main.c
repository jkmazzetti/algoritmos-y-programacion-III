#include <stdio.h>
#include "TP1/parImpar.h"
#include "TP1/promedio.h"
#include "TP1/maximo.h"

int main() {
    int lista[]={2,3,4,5,6,9,1,55};
    printf("¿Es par? %d",determinarPar());
    printf("Promedio: %.6f",promediar());
    printf("Maximo: %d",maximo(lista));
    return 0;
}
