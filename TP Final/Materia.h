
struct Materia *crearMateria(int codigo, char *nombre) {
    struct Materia *materia = malloc(sizeof(struct Materia));
    materia->codigo = codigo;
    materia->nombre = nombre;
    return materia;
}

void mostrarMaterias(int paginado, struct ListaEnlazada *miLista) {
    struct Nodo *aux = malloc(sizeof(struct Nodo));
    aux = miLista->inicial;
    printf("\nLista:");
    int c = 0;
    while (aux != NULL) {

        printf(" %s", aux->materia->nombre);
        printf(" %d", aux->materia->codigo);
        c++;
        char s = 'n';
        while (c == paginado) {
            printf("\n Presione 'c' para continuar...\n");
            scanf("%d", s);
            if (s = 'c') {
                c = 0;
                s = 'v';
                aux = aux->siguiente;
            }
        }
    }
}