
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