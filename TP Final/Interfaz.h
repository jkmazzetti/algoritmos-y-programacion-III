#include "Lista.h"
#include "Alumno.h"
#include "Materia.h"
#include "Carrera.h"

void menuAlumnos(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras,
                 struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo,
                 int codigoMateria, int codigoCarrera);

void menuCarreras(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras,
                  struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo,
                  int codigoMateria, int codigoCarrera);

int menuPrincipal(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras,
                  struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo,
                  int codigoMateria, int codigoCarrera) {
    int opcion;
    printf("1- Gestionar Carreras.\n");
    printf("2- Gestionar Alumnos.\n");
    printf("3- Salir.\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            menuCarreras(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                         codigoCarrera);
            break;
        case 2:
            menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                        codigoCarrera);
        default:
            break;
    }

    return 0;
}

void menuAlumnos(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras,
                 struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo,
                 int codigoMateria, int codigoCarrera) {
    printf("-Alumnos-\n");
    int opcion, codigo, nota;
    char apellido[30], nombre[30], r = 's';
    int max, min, legajoBusqueda, edad;
    struct Alumno *alumno;
    bool confirmado;
    printf("1- Buscar.\n");
    printf("2- Nuevo.\n");
    printf("3- Eliminar.\n");
    printf("4- Mostrar Todo.\n");
    printf("5- Volver.\n");
    printf("6- Salir.\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            printf("-Busqueda-\n");
            printf("1- Apellido.\n");
            printf("2- Rango de edad.\n");
            printf("3- Legajo.\n");
            printf("Opcion: ");
            scanf("%d", &opcion);
            switch (opcion) {

                case 1:
                    printf("Apellido: ");
                    scanf("%s", apellido);
                    buscarPorApellido(listaAlumnosLegajo, apellido);
                    menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                codigoMateria, codigoCarrera);
                    break;
                case 2:
                    printf("Minima: ");
                    scanf("%d", &min);
                    printf("Maxima: ");
                    scanf("%d", &max);
                    buscarPorRangoEtario(listaAlumnosEdad, min, max);
                    menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                codigoMateria, codigoCarrera);
                    break;
                case 3:
                    printf("Legajo: ");
                    scanf("%d", &legajoBusqueda);
                    alumno = NULL;
                    alumno = buscarPorLegajo(listaAlumnosLegajo, legajoBusqueda);
                    if (alumno != NULL) {
                        printf("1- Inscripcion Carrera.\n");
                        printf("2- Inscripcion Materia.\n");
                        printf("3- Materia en Curso.\n");
                        printf("4- Materia Aprobadas.\n");
                        printf("5- Calificar Materia.\n");
                        printf("6- Mostrar Promedio.\n");
                        printf("7- Volver.\n");
                        printf("8- Inicio.\n");
                        printf("9- Salir.\n");
                        printf("Opcion: ");
                        scanf("%d", &opcion);
                        switch (opcion) {

                            case 1:
                                printf("Codigo: ");
                                scanf("%d", &codigo);
                                alumno->carrera = buscarCarrera(listaCarreras, codigo);
                                menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                            codigoMateria, codigoCarrera);

                                break;
                            case 2:
                                if (alumno->carrera == NULL) {
                                    printf("Debe inscribirse a carrera antes.\n");
                                    menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo,
                                                legajo, codigoMateria, codigoCarrera);
                                } else {
                                    r = 's';
                                    while (r == 's' && alumno->alcanzoLimite == false) {
                                        printf("Codigo: ");
                                        scanf("%d", &codigo);
                                        inscribirAMateria(alumno, nodoMateria(buscarMateria(listaMaterias, codigo)));
                                        printf("Continuar inscribiendo s/n: ");
                                        scanf(" %c", &r);
                                    }
                                    menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo,
                                                legajo, codigoMateria, codigoCarrera);
                                }

                                break;
                            case 3:
                                if (alumno->materiasEnCurso->inicial != NULL) {
                                    mostrarMaterias(alumno->materiasEnCurso);
                                } else {
                                    printf("A??n no est?? inscripto a materias.\n");
                                }
                                menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                            codigoMateria, codigoCarrera);

                                break;
                            case 4:
                                if (alumno->materiasAprobadas->cantidadElementos == 0) {
                                    printf("No hay informaci??n disponible.\n");
                                } else {
                                    mostrarMaterias(alumno->materiasAprobadas);
                                }
                                menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                            codigoMateria, codigoCarrera);
                                break;

                            case 5:
                                r = 's';
                                if(alumno->materiasEnCurso->inicial!=NULL) {
                                    while (r == 's') {
                                        printf("Codigo: ");
                                        scanf("%d", &codigo);
                                        printf("Nota: ");
                                        scanf("%d", &nota);
                                        calificar(alumno, codigo, nota);
                                        printf("Continuar calificando s/n: ");
                                        scanf(" %c", &r);
                                    }
                                } else{
                                    printf("No est?? inscripto a materias.");
                                }
                                menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                            codigoMateria, codigoCarrera);
                                break;
                            case 6:
                                printf("Promedio: %f\n", alumno->promedio);
                                menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                            codigoMateria, codigoCarrera);
                                break;
                            case 7:
                                menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                            codigoMateria, codigoCarrera);
                                break;
                            case 8:
                                menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo,
                                              legajo, codigoMateria, codigoCarrera);
                                break;
                            default:
                                break;
                        }
                    } else {
                        menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                    codigoMateria, codigoCarrera);

                    }
                    break;
                default:
                    break;
            }
            break;

        case 2:
            while (r == 's') {
                legajo++;
                printf("-Nuevo Alumno-\n");
                printf("Edad: ");
                scanf("%d", &edad);
                printf("Nombre: ");
                scanf(" %s", nombre);
                printf("Apellido: ");
                scanf(" %s", apellido);
                struct Alumno *alumno = crearAlumno(legajo, edad, nombre, apellido);
                confirmado = agregarElemetoPorClave(listaAlumnosLegajo, nodoAlumno(alumno));
                if (confirmado) {
                    listarPorEdad(listaAlumnosEdad, nodoAlumno(alumno));
                }
                printf("Confirmacion: %d\n", confirmado);
                printf("Continuar inscribiendo s/n: ");
                scanf(" %c", &r);
            }
            menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                        codigoCarrera);
            break;

        case 3:
            printf("Eliminar estudiante.\n");
            printf("Legajo: ");
            scanf("%d", &legajoBusqueda);
            if (eliminarElementoPorClave(listaAlumnosLegajo, legajoBusqueda)) {
                printf("Eliminado: %d\n", eliminarDeListaOrdenadaPorEdad(listaAlumnosEdad, legajoBusqueda));
            }
            menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                        codigoCarrera);
            break;
        case 4:
            mostrarAlumnos(listaAlumnosLegajo);
            printf("\n");
            menuAlumnos(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                        codigoCarrera);
            break;

        case 5:
            menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                          codigoCarrera);
            break;
        default:
            break;
    }
}

void menuCarreras(struct ListaEnlazada *listaMaterias, struct ListaEnlazada *listaCarreras,
                  struct ListaEnlazada *listaAlumnosEdad, struct ListaEnlazada *listaAlumnosLegajo, int legajo,
                  int codigoMateria, int codigoCarrera) {
    printf("-Carreras-\n");
    int opcion, codigo;
    char nombre[30];
    char r = 's';
    struct Carrera *carrera;
    struct Materia *materia;
    printf("1- Buscar Carrera.\n");
    printf("2- Nueva Carrera.\n");
    printf("3- Eliminar Carrera.\n");
    printf("4- Mostrar Carreras.\n");
    printf("5- Mostrar Materias.\n");
    printf("6- Volver.\n");
    printf("7- Salir.\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            carrera = NULL;
            printf("Codigo de Carrera: ");
            scanf("%d", &codigo);
            carrera = buscarCarrera(listaCarreras, codigo);
            if (carrera != NULL) {
                printf("1- Agregar Materia.\n");
                printf("2- Nueva Materia.\n");
                printf("3- Eliminar Materia.\n");
                printf("4- Volver.\n");
                printf("5- Salir.\n");
                printf("Opcion: ");
                scanf("%d", &opcion);
                switch (opcion) {
                    case 1:
                        while (r == 's') {
                            printf("C??digo: ");
                            scanf("%d", &codigo);
                            materia = NULL;
                            materia = buscarMateria(listaMaterias, codigo);
                            if (materia != NULL) {
                                agregarElemetoPorClave(carrera->materias, nodoMateria(materia));
                            }
                            printf("Continuar agregando s/n: ");
                            scanf(" %c", &r);
                        }
                        menuCarreras(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                     codigoMateria, codigoCarrera);
                        break;
                    case 2:
                        printf("Nombre: ");
                        scanf("%s", nombre);
                        materia = crearMateria(codigoMateria, nombre);
                        agregarElemetoPorClave(listaMaterias, nodoMateria(materia));
                        agregarElemetoPorClave(carrera->materias, nodoMateria(materia));
                        menuCarreras(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                     codigoMateria, codigoCarrera);
                        break;
                    case 3:
                        printf("C??digo: ");
                        scanf("%d", &codigo);
                        eliminarElementoPorClave(carrera->materias, codigo);
                        menuCarreras(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo,
                                     codigoMateria, codigoCarrera);
                        break;
                    case 4:
                        menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo,
                                      legajo, codigoMateria, codigoCarrera);
                        break;
                    default:
                        break;
                }
            } else {
                menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                              codigoCarrera);
            }
            break;

        case 2:

            while (r == 's') {
                codigoCarrera++;
                printf("Nombre: ");
                scanf("%s", nombre);
                carrera = crearCarrera(codigoCarrera, nombre);
                agregarElemetoPorClave(listaCarreras, nodoCarrera(carrera));
                printf("Continuar agregando s/n: ");
                scanf(" %c", &r);
            }
            menuCarreras(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                         codigoCarrera);
            break;

        case 3:
            printf("C??digo: ");
            scanf("%d", &codigo);
            eliminarElementoPorClave(listaCarreras, codigo);
            menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                          codigoCarrera);
            break;

        case 4:
            mostrarCarreras(listaCarreras);
            menuCarreras(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                         codigoCarrera);
            break;
        case 5:
            mostrarMaterias(listaMaterias);
            menuCarreras(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                         codigoCarrera);
            break;
        case 6:
            menuPrincipal(listaMaterias, listaCarreras, listaAlumnosEdad, listaAlumnosLegajo, legajo, codigoMateria,
                          codigoCarrera);
            break;
        default:
            break;
    }
}
