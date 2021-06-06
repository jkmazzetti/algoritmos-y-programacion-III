#include "Lista.h"
#include "Alumno.h"
#include "Materia.h"
#include "Carrera.h"

void menuAlumnos(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras, struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo, int codigoMateria, int codigoCarrera);
void menuCarreras(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras, struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo, int codigoMateria, int codigoCarrera);

int menuPrincipal(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras, struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo, int codigoMateria, int codigoCarrera) {
    int opcion;
    printf("1- Gestionar Carreras.\n");
    printf("2- Gestionar Estudiantes.\n");
    printf("3- Salir.\n");
    printf("Su respuesta: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            menuCarreras(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
            break;
        case 2:
            menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
        default:
            break;
    }

    return 0;
}

void menuAlumnos(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras, struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo, int codigoMateria, int codigoCarrera){
    int opcion;
    char apellido[30], nombre[30];
    int max, min, legajoBusqueda, edad;
    struct Alumno *alumno;
    bool confirmado;
    printf("1- Buscar estudiante.\n");
    printf("2- Agregar estudiante.\n");
    printf("3- Eliminar estudiante.\n");
    printf("4- Volver.\n");
    printf("5- Salir.\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            printf("Buscar estudiante por:\n");
            printf("1- Apellido.\n");
            printf("2- Rango de edad.\n");
            printf("3- Legajo.\n");
            printf("Opcion: ");
            scanf("%d", &opcion);
            switch (opcion) {

                case 1:
                    printf("Nombre: ");
                    scanf("%s", nombre);
                    buscarPorApellido(listaAlumnosLegajo, nombre);
                    menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
                    break;
                case 2:
                    printf("Minima: ");
                    scanf("%d", &min);
                    printf("Maxima: ");
                    scanf("%d", &max);
                    buscarPorRangoEtario(listaAlumnosEdad, min, max);
                    menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
                    break;
                case 3:
                    printf("Legajo: ");
                    scanf("%d", &legajoBusqueda);
                    alumno=NULL;
                    alumno=buscarPorLegajo(listaAlumnosLegajo, legajoBusqueda);
                    if (alumno!=NULL) {
                        printf("Gestionar.\n");
                        printf("1- Inscripcion Carrera.\n");
                        printf("2- Inscripcion Materia.\n");
                        printf("3- Calificar Materia.\n");
                        printf("4- Mostrar Promedio.\n");
                        printf("5_ Volver.\n");
                        printf("6_ Inicio.\n");
                        printf("7_ Salir.\n");
                        printf("Su respuesta: ");
                        scanf("%d", &opcion);
                        switch (opcion) {

                            case 1:
                                printf("Codigo: ");
                                scanf("%d", &codigoCarrera);
                                alumno->carrera=buscarCarrera(listaCarreras,codigoCarrera);
                                break;
                            case 2:
                                menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
                                break;
                            case 3:
                                menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
                                break;
                            case 4:
                                menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
                                case 5:
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
            printf("Edad: ");
            scanf("%d", &edad);
            printf("Nombre: ");
            scanf("%s", nombre);
            printf("Apellido: ");
            scanf("%s", apellido);
            struct Alumno *alumno = crearAlumno(legajo, edad, nombre, apellido);
            confirmado = agregarElemetoPorClave(listaAlumnosLegajo, nodoAlumno(alumno));
            if (confirmado) {
                listarPorEdad(listaAlumnosEdad, nodoAlumno(alumno));
            }
            printf("Confirmacion: %d\n", confirmado);
            menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
            break;

        case 3:
            printf("Eliminar estudiante.\n");
            printf("Legajo: ");
            scanf("%d", &legajoBusqueda);
            eliminarElemento(listaAlumnosEdad, legajoBusqueda);
            printf("Eliminado: %d\n", eliminarElemento(listaAlumnosLegajo, legajoBusqueda));
            menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
            break;

        case 4:
            menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
            break;
        default:
            break;
    }
}
void menuCarreras(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras, struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo, int codigoMateria, int codigoCarrera) {
    int opcion, codigo;
    char apellido[30], nombre[30];
    int max, min, legajoBusqueda, edad;
    struct Carrera *carrera;
    struct Materia *materia;
    bool confirmado;
    printf("1- Buscar Carrera.\n");
    printf("2- Agregar Carrera.\n");
    printf("3- Eliminar Carrera.\n");
    printf("4- Volver.\n");
    printf("5- Salir.\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            carrera = NULL;
            printf("\nCodigo de Carrera: ");
            scanf("%d", &codigo);
            carrera = buscarCarrera(listaCarreras, codigo);
            if (carrera != NULL) {
                switch (opcion) {
                    printf("1- Agregar Materia.\n");
                    printf("2- Eliminar Materia.\n");
                    printf("4- Volver.\n");
                    printf("5- Salir.\n");
                    printf("Opcion: ");
                    scanf("%d", &opcion);
                    case 1:
                        scanf("Codigo: ", &codigo);
                        materia=NULL;
                        materia=buscarMateria(listaMaterias,codigo);
                        if(materia!=NULL) {
                            agregarElemetoPorClave(carrera->materias,codigo);
                        }
                        break;
                    case 2:
                        break;

                    default:
                        break;
                }
                break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    break;
                default:
                    break;
            } else{
                menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria, codigoCarrera);
            }
    }
}
