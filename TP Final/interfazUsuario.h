#include "Lista.h"
#include "Alumno.h"
#include "Materia.h"

int mostrarMenu(struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo) {
    int opcion;
    char apellido[30], nombre[30];
    int max, min, legajoBusqueda, edad;
    bool confirmado;

    printf("1- Buscar estudiante.\n");
    printf("2- Agregar estudiante.\n");
    printf("3- Eliminar estudiante.\n");
    printf("4- Salir.\n");
    printf("Su respuesta: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            printf("Buscar estudiante por:\n");
            printf("1- Nombre.\n");
            printf("2- Rango de edad.\n");
            printf("3- Legajo.\n");
            printf("Su respuesta: ");
            scanf("%d", &opcion);
            switch (opcion) {

                case 1:
                    printf("Nombre: ");
                    scanf("%s", nombre);
                    buscarPorNombre(listaAlumnosLegajo, nombre);
                    break;
                case 2:
                    printf("Edad minima: ");
                    scanf("%d", &min);
                    printf("Edad maxima: ");
                    scanf("%d", &max);
                    buscarPorRangoEtario(listaAlumnosEdad, min, max);
                    break;
                case 3:
                    printf("Legajo: ");
                    scanf("%d", &legajoBusqueda);
                    if(buscarPorLegajo(listaAlumnosLegajo, legajoBusqueda)) {
                        printf("Gestionar.\n");
                        printf("1- Inscripcion materia.\n");
                        printf("2- Calificar materia.\n");
                        printf("3- Mostrar promedio.\n");
                        printf("4_ Volver al inicio.\n");
                        printf("Su respuesta: ");
                        scanf("%d", &opcion);
                        switch (opcion) {

                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                mostrarMenu(listaAlumnosEdad, listaAlumnosLegajo, legajo);
                            default:
                                break;


                        }
                    }
                    break;

                default:
                    break;
            }
            break;

        case 2:
            legajo++;
            printf("Nuevo estudiante. \n");
            printf("Ingrese edad: ");
            scanf("%d", &edad);
            printf("Ingrese nombre: ");
            scanf("%s", nombre);
            printf("Ingrese apellido: ");
            scanf("%s", apellido);
            struct Alumno *alumno = crearAlumno(legajo, edad, nombre, apellido);
            confirmado = agregarElemetoPorClave(listaAlumnosLegajo, nodoAlumno(alumno));
            if (confirmado) {
                listarPorEdad(listaAlumnosEdad, nodoAlumno(alumno));
            }
            printf("Se agrego alumno: %d\n", confirmado);
            break;

        case 3:
            printf("Eliminar estudiante.\n");
            printf("Ingrese legajo: ");
            scanf("%d", &legajoBusqueda);
            printf("Eliminado: %d", eliminarElemento(listaAlumnosEdad, legajoBusqueda));
            printf("Eliminado: %d\n", eliminarElemento(listaAlumnosLegajo, legajoBusqueda));
            break;

        default:
            break;
    }
    if (opcion >= 1 && opcion < 4) {
        mostrarMenu(listaAlumnosEdad, listaAlumnosLegajo, legajo);
    }
}