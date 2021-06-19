#include "TP Final/Interfaz.h"

int main() {
    int legajo = 5000;
    int codigoMateria = 50;
    int codigoCarrera = 100;
    struct Carrera *ingAmb, *ingSonido, *enfermeria;

    struct Materia *fisica, *analisis, *quimica, *algebra, *geologia, *biologia, *recursosNaturales, *primerosAuxilios, *acustica;

    fisica = crearMateria(codigoMateria++, "Fisica");
    analisis = crearMateria(codigoMateria++, "Análisis");
    quimica = crearMateria(codigoMateria++, "Química");
    algebra = crearMateria(codigoMateria++, "Álgebra");
    geologia = crearMateria(codigoMateria++, "Geología");
    biologia = crearMateria(codigoMateria++, "Biología");
    recursosNaturales = crearMateria(codigoMateria++, "RecursosNaturales");
    primerosAuxilios = crearMateria(codigoMateria++, "PrimerosAuxilios");
    acustica = crearMateria(codigoMateria++, "Acústica");
    ingAmb = crearCarrera(codigoCarrera++, "IngenieríaAmbiental");
    ingSonido = crearCarrera(codigoCarrera++, "IngenieriaEnSonido");
    enfermeria = crearCarrera(codigoCarrera++, "Enfermería");
    //agregar materias a carreras
    agregarElemetoPorClave(ingAmb->materias, nodoMateria(fisica));
    agregarElemetoPorClave(ingAmb->materias, nodoMateria(analisis));
    agregarElemetoPorClave(ingAmb->materias, nodoMateria(geologia));
    agregarElemetoPorClave(ingAmb->materias, nodoMateria(quimica));
    agregarElemetoPorClave(ingAmb->materias, nodoMateria(algebra));
    agregarElemetoPorClave(ingAmb->materias, nodoMateria(biologia));
    agregarElemetoPorClave(ingAmb->materias, nodoMateria(recursosNaturales));
    agregarElemetoPorClave(ingSonido->materias, nodoMateria(acustica));
    agregarElemetoPorClave(ingSonido->materias, nodoMateria(fisica));
    agregarElemetoPorClave(ingSonido->materias, nodoMateria(analisis));
    agregarElemetoPorClave(enfermeria->materias, nodoMateria(primerosAuxilios));
    agregarElemetoPorClave(enfermeria->materias, nodoMateria(algebra));
    agregarElemetoPorClave(enfermeria->materias, nodoMateria(quimica));
    agregarElemetoPorClave(enfermeria->materias, nodoMateria(biologia));
    struct ListaEnlazada *listaAlumnosLegajo = crearLista();
    struct ListaEnlazada *listaAlumnosEdad = crearLista();
    struct ListaEnlazada *listaMaterias = crearLista();
    struct ListaEnlazada *listaCarreras = crearLista();
    //agregar carrera a lista
    agregarElemetoPorClave(listaCarreras, nodoCarrera(ingAmb));
    agregarElemetoPorClave(listaCarreras, nodoCarrera(ingSonido));
    agregarElemetoPorClave(listaCarreras, nodoCarrera(enfermeria));
    //agregar materias a lista
    agregarElemetoPorClave(listaMaterias, nodoMateria(fisica));
    agregarElemetoPorClave(listaMaterias, nodoMateria(analisis));
    agregarElemetoPorClave(listaMaterias, nodoMateria(geologia));
    agregarElemetoPorClave(listaMaterias, nodoMateria(quimica));
    agregarElemetoPorClave(listaMaterias, nodoMateria(algebra));
    agregarElemetoPorClave(listaMaterias, nodoMateria(biologia));
    agregarElemetoPorClave(listaMaterias, nodoMateria(recursosNaturales));
    agregarElemetoPorClave(listaMaterias, nodoMateria(primerosAuxilios));
    agregarElemetoPorClave(listaMaterias, nodoMateria(acustica));
    menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                  codigoCarrera);
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

/*TP3:
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
    printf("\nEliminar 0: %d", eliminarElementoPorClave(miLista, 0));
    mostrar(miLista);
    printf("\nElemento menor: %d", miLista->menor);
 */