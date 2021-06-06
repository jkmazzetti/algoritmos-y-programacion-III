struct Carrera *buscarCarrera(struct ListaEnlazada *miLista, int codigo) {
    struct Nodo *aux;
    bool encontrado=false;
    aux = miLista->inicial;
    struct Carrera *c=NULL;
    printf("Carrera con codigo %d%s",codigo,": \n");
    while (aux != NULL && encontrado==false) {
        if(aux->carrera->codigo==codigo ) {
            c=aux->carrera;
            printf("%d", aux->valor);
            printf(" %s", aux->carrera->nombre);
            printf(" Materias:\n");
            mostrar(c->materias);
            encontrado=true;
            printf("\n");
        }
        aux = aux->siguiente;
    }
    if(encontrado==false){
        printf("La carrera solicitada no existe.\n");
    }
    return c;
}
