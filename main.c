#include <stdio.h>
#include "TP3/listaEnlazadaSimple.h"

int main() {
//TP3
    struct ListaEnlazada *miLista = crearLista();
    agregarElemento(miLista, 11);
    agregarElemento(miLista, 11);
    agregarElemento(miLista, 12);
    agregarElemento(miLista, 15);
    agregarElemento(miLista, 2);
    mostrar(miLista);
    printf("\nCantidad de elementos: %d", miLista->cantidadElementos);
    printf("\nElemento mayor: %d", miLista->mayor);
    printf("\nElemento menor: %d", miLista->menor);
    printf("\nBusqueda de 5: %d", buscarElemento(miLista, 5));
    printf("\nBusqueda de 12: %d", buscarElemento(miLista, 12));
    printf("\nEliminar 15: %d", eliminarElemento(miLista, 15));
    printf("\nElemento menor: %d", miLista->menor);
    printf("\nElemento mayor: %d", miLista->mayor);
    mostrar(miLista);
    printf("\nCantidad de elementos: %d", miLista->cantidadElementos);
    agregarElemento(miLista, 0);
    mostrar(miLista);
    printf("\nElemento menor: %d", miLista->menor);
    printf("\nElemento mayor: %d", miLista->mayor);
    agregarElemento(miLista, 2);
    mostrar(miLista);
    printf("\nCantidad de elementos: %d", miLista->cantidadElementos);
    printf("\nEliminar 11: %d", eliminarElemento(miLista, 11));
    mostrar(miLista);
    printf("\nEliminar 15: %d", eliminarElemento(miLista, 15));
    return 0;
}

/* INCLUIR EN MAIN PARA SU EJECUCION.
    TP1:

    int lista[]={2,3,4,5,6,9,1,55};
    printf("¿Es par? %d",determinarPar());
    printf("Promedio: %.6f",promediar());
    printf("Maximo: %d",maximo(lista));
    printf("Minimo %d",minimo(lista));
    mostrarASCII();
    mostrarMenu();
    solicitarDatos();

 */

/*TP2:
    struct Persona carlos = {"Carlos", "Aguirre", 54};
    struct Persona primerHijo = {"Felipe", "Aguirre", 14};
    struct Persona segundoHijo = {"Maria", "Aguirre", 2};
    struct Persona hijos[2] = {primerHijo, segundoHijo};
    struct Padre padreCarlos = {carlos, hijos};
    printf("%s%p%s%p%s", "¡Las direcciones de memoria ", padreCarlos.datosHijos[1].nombre, " y ", segundoHijo.nombre,
           " son distintas! \nSe esperaba que fueran iguales...\n");
    for (int i = 0; i < 5; i++) {
        printf("\n%p ", crearPersona("Carlos", "Aguirre", 5 * i));
    }
    printf("\n\n%s",
           "Se debe crear una funcion que asigne un nuevo puntero para cada nueva instancia."
           "\nDe lo contrario no crea nueva instancia sino que reescribe siempre la misma.");

*/