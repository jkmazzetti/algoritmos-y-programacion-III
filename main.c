#include <stdio.h>
#include "TP1/parImpar.h"
#include "TP1/promedio.h"
#include "TP1/maximo.h"
#include "TP1/minimo.h"
#include "TP1/caracteres.h"
#include "TP1/menu.h"
#include "TP1/datos.h"
#include "TP2/estructuras.h"

int main() {
//    int lista[]={2,3,4,5,6,9,1,55};
//    printf("¿Es par? %d",determinarPar());
//    printf("Promedio: %.6f",promediar());
//    printf("Maximo: %d",maximo(lista));
//    printf("Minimo %d",minimo(lista));
//    mostrarASCII();
//    mostrarMenu();
//    solicitarDatos();
    struct Persona carlos={"Carlos","Aguirre",54};
    struct Persona primerHijo= {"Felipe","Aguirre",14};
    struct Persona segundoHijo= {"Maria","Aguirre", 2};
    struct Persona hijos[2]={primerHijo,segundoHijo};
    struct Padre pc= {carlos,hijos};
    printf("%s%p%s%p%s","¡Las direcciones de memoria ",pc.datosHijos[1].nombre," y ",segundoHijo.nombre," son distintas! \nSe esperaba que fueran iguales...");
    return 0;
}
