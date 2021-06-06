#include <stdio.h>
#include <string.h>
struct Materia *crearMateria(int codigo, char *nombre) {
    struct Materia *materia = malloc(sizeof(struct Materia));
    materia->codigo = codigo;
    materia->nombre = nombre;
    return materia;
}

void mostrarMaterias(struct ListaEnlazada *miLista) {
    struct Nodo *aux = malloc(sizeof(struct Nodo));
    aux = miLista->inicial;
    printf("\nLista:");
    int c = 0;
    while (aux != NULL) {
        printf(" %s", aux->materia->nombre);
        printf(" %d\n", aux->materia->codigo);
        aux = aux->siguiente;
    }
}
void calificarMateria(struct Alumno *alumno,struct Nodo *materia,double nota){
    eliminarElemento(alumno->materiasEnCurso,materia->valor);
    if(nota>=4){
    agregarElemetoPorClave(alumno->materiasAprobadas,materia);
    }
}

struct Materia *buscarMateria(struct ListaEnlazada *miLista, int codigo) {
    struct Nodo *aux;
    bool encontrado=false;
    aux = miLista->inicial;
    struct Materia *m=NULL;
    printf("Materia con codigo %d%s",codigo,": \n");
    while (aux != NULL && encontrado==false) {
        if(aux->materia->codigo==codigo ) {
            m=aux->materia;
            printf("%d", aux->valor);
            printf(" %s", aux->materia->nombre);
            encontrado=true;
            printf("\n");
        }
        aux = aux->siguiente;
    }
    if(encontrado==false){
        printf("La materia solicitada no existe.\n");
    }
    return m;
}
