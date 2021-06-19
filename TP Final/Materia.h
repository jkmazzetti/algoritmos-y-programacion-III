#include <stdio.h>
#include <string.h>

struct Materia *crearMateria(int codigo, char nombre[]) {
    struct Materia *materia = malloc(sizeof(struct Materia));
    materia->codigo = codigo;
    for(int i=0;i<sizeof (materia->nombre);i++){
        materia->nombre[i] = nombre[i];
    }

    return materia;
}

void mostrarMaterias(struct ListaEnlazada *miLista) {
    struct Nodo *aux;
    aux = miLista->inicial;
    while (aux != NULL) {
        printf(" %d", aux->materia->codigo);
        printf(" %s", aux->materia->nombre);
        if(aux->siguiente!=NULL){
            printf("\n");
        }
        aux = aux->siguiente;
    }
    printf("\n");
}

struct Materia *buscarMateria(struct ListaEnlazada *miLista, int codigo) {
    struct Nodo *aux;
    bool encontrado = false;
    aux = miLista->inicial;
    struct Materia *m = NULL;
    printf("Materia con codigo %d%s", codigo, ": \n");
    while (aux != NULL && encontrado == false) {
        if (aux->materia->codigo == codigo) {
            m = aux->materia;
            printf("%d", aux->valor);
            printf(" %s", aux->materia->nombre);
            encontrado = true;
            printf("\n");
        }
        aux = aux->siguiente;
    }
    if (encontrado == false) {
        printf("La materia solicitada no existe.\n");
    }
    return m;
}

void calificar(struct Alumno *alumno, int codigo, int nota) {
    struct Materia *materia = malloc(sizeof(struct Nodo));
    char *nombre;
    bool exite = buscarElemento(alumno->materiasEnCurso, codigo);
    if (exite == true) {
        materia->codigo = codigo;
        nombre=buscarMateria(alumno->materiasEnCurso, codigo)->nombre;
        for(int i=0;i<sizeof (materia->nombre);i++) {
            materia->nombre[i] =nombre[i];
        }
        materia->nota = nota;
        if (eliminarElementoPorClave(alumno->materiasEnCurso, codigo) == true && nota >= 4) {
            agregarElemetoPorClave(alumno->materiasAprobadas, nodoMateria(materia));
            if (alumno->materiasAprobadas->cantidadElementos==1) {
                alumno->promedio = nota;
            } else {
                alumno->promedio += nota;
                alumno->promedio /= 2;
            }
        }

    }
}