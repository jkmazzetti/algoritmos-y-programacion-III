struct Carrera *crearCarrera(int codigo, char nombre[]) {
    struct Carrera *carrera = malloc(sizeof(struct Materia));
    carrera->codigo = codigo;
    for(int i=0;i<sizeof (carrera->nombre);i++){
        carrera->nombre[i]=nombre[i];
    }
    carrera->materias = crearLista();
    return carrera;
}

struct Carrera *buscarCarrera(struct ListaEnlazada *miLista, int codigo) {
    struct Nodo *aux;
    bool encontrado = false;
    aux = miLista->inicial;
    struct Carrera *c = NULL;
    struct Nodo *auxMateria;
    while (aux != NULL && encontrado == false) {
        if (aux->carrera->codigo == codigo) {
            c = aux->carrera;
            printf("%d", aux->valor);
            printf(" %s", aux->carrera->nombre);
            if (c->materias != NULL) {
                printf(" \nMaterias:\n");
                mostrarMaterias(c->materias);
            }
            encontrado = true;
        }
        aux = aux->siguiente;
    }
    if (encontrado == false) {
        printf("La carrera solicitada no existe.\n");
    }
    return c;
}

void mostrarCarreras(struct ListaEnlazada *miLista) {
    struct Nodo *aux;
    aux = miLista->inicial;
    while (aux != NULL) {
        printf("    %d", aux->carrera->codigo);
        printf(" %s\n", aux->carrera->nombre);
        aux = aux->siguiente;
    }
}