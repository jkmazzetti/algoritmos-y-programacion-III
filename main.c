#include <stdio.h>
#include "TP Final/Lista.h"
#include "TP Final/Alumno.h"
#include "TP Final/Materia.h"

int main() {
    struct ListaEnlazada *listaAlumnosPorLegajo = crearLista();
    struct ListaEnlazada *listaAlumnosPorEdad = crearLista();
    struct Alumno *alumno1, *alumno2, *alumno3;
    char *nombre1 = "Maria";
    char *nombre2 = "Roberto";
    char *nombre3 = "Ines";
    char *apellido1 = "Lorenzo";
    char *apellido2 = "Felipe";
    char *apellido3 = "Fernandez";
    int edad1 = 30;
    int edad2 = 18;
    int edad3 = 20;
    alumno1 = crearAlumno(142541, edad1, nombre1, apellido1);
    alumno2 = crearAlumno(100001, edad2, nombre2, apellido2);
    alumno3 = crearAlumno(111111, edad3, nombre3, apellido3);
    char *nombreM1 = "Fisica";
    int cod1 = 33;
    struct Materia *materia1;
    char *nombreM2 = "Algebra";
    int cod2 = 36;
    struct Materia *materia2;
    materia1 = crearMateria(cod1, nombreM1);
    materia2 = crearMateria(cod2, nombreM2);
    if (agregarElemetoPorClave(listaAlumnosPorLegajo, nodoAlumno(alumno1))) {
        listaPorEdad(listaAlumnosPorEdad, nodoAlumno(alumno1));
    }
    if (agregarElemetoPorClave(listaAlumnosPorLegajo, nodoAlumno(alumno2))) {
        listaPorEdad(listaAlumnosPorEdad, nodoAlumno(alumno2));
    }
    if (agregarElemetoPorClave(listaAlumnosPorLegajo, nodoAlumno(alumno3))) {
        listaPorEdad(listaAlumnosPorEdad, nodoAlumno(alumno3));
    }
    //mostrarAlumnos(1, listaAlumnosPorLegajo);
    //mostrarAlumnos(1, listaAlumnosPorEdad);
    //mostrarAlumnosPorEdad(1,listaAlumnosPorEdad,20,30);
    //printf("%s%d", "\n", listaAlumnosPorLegajo->cantidadElementos);
    //agregarElemetoPorClave(alumno1->materiasAprobadas,nodoMateria(materia2));
    inscribirAMateria(alumno1, nodoMateria(materia1));
    inscribirAMateria(alumno1, nodoMateria(materia2));
    mostrarMaterias(alumno1->materiasEnCurso);
    eliminarElemento(listaAlumnosPorLegajo, 142541);
    eliminarElemento(listaAlumnosPorLegajo, 111111);
    //eliminarElemento(listaAlumnosPorLegajo, 100001);
    mostrarAlumnos(listaAlumnosPorLegajo);
    mostrarMaterias(alumno1->materiasEnCurso);
    calificarMateria(alumno1,nodoMateria(materia2),8.5);
    mostrarMaterias(alumno1->materiasAprobadas);
    mostrarMaterias(alumno1->materiasEnCurso);
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
    printf("\nEliminar 0: %d", eliminarElemento(miLista, 0));
    mostrar(miLista);
    printf("\nElemento menor: %d", miLista->menor);
 */