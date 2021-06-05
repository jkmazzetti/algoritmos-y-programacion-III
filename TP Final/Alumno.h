
struct Alumno *crearAlumno(int legajo, int edad, char nombre[], char apellido[]) {
    struct Alumno *alumno = malloc(sizeof(struct Alumno));
    alumno->legajo = legajo;
    alumno->edad = edad;
    alumno->apellido = apellido;
    alumno->nombre = nombre;
    alumno->materiasAprobadas = malloc(sizeof(struct ListaEnlazada));
    alumno->materiasEnCurso = malloc(sizeof(struct ListaEnlazada));
    return alumno;
}

bool inscribirAMateria(struct Alumno *alumno, struct Nodo *materia) {
    bool inscripto=false;
    int limite=5;
    if(alumno->materiasEnCurso->cantidadElementos<limite && !buscarElemento(alumno->materiasAprobadas,materia->valor)){
        agregarElemetoPorClave(alumno->materiasEnCurso, materia);
        inscripto=true;
    }else{
        printf("Alconzó el limite de materias que puede cursar.");
    }
    return inscripto;
}

void mostrarAlumnos(struct ListaEnlazada *miLista) {
    struct Nodo *aux;
    aux = miLista->inicial;
    printf("\nAlumnos ordenados por legajo:");
    while (aux != NULL) {

        printf("\n%d", aux->valor);
        printf(" %s", aux->alumno->apellido);
        printf(" %s", aux->alumno->nombre);
        printf(" %d", aux->alumno->edad);
        aux = aux->siguiente;
    }

}
void buscarPorRangoEtario(struct ListaEnlazada *miLista, int min, int max) {
    struct Nodo *aux;
    aux = miLista->inicial;
    bool encontrado=false;
    if(max!=min) {
        printf("\nAlumnos de entre %d %s %d %s: \n", min, "y", max, "años");
    }else{
        printf("\nAlumnos de %d %s: \n", min, "años");
    }
    while (aux != NULL) {
        if(aux->alumno->edad>=min && aux->alumno->edad<=max ) {
            printf(" %d", aux->valor);
            printf(" %s", aux->alumno->apellido);
            printf(" %s", aux->alumno->nombre);
            printf(" %d", aux->alumno->edad);
            printf("\n");
            encontrado=true;
        }
        aux = aux->siguiente;
    }
    if(encontrado==false){
        printf("No hubo coincidencias.\n");
    }
}
bool buscarPorLegajo(struct ListaEnlazada *miLista, int legajo) {
    struct Nodo *aux;
    bool encontrado=false;
    aux = miLista->inicial;
    printf("Alumno con legajo %d%s",legajo,": \n");
    while (aux != NULL && encontrado==false) {
        if(aux->alumno->legajo==legajo ) {
            printf("%d", aux->valor);
            printf(" %s", aux->alumno->apellido);
            printf(" %s", aux->alumno->nombre);
            printf(" %d", aux->alumno->edad);
            encontrado=true;
            printf("\n");
        }
        aux = aux->siguiente;
    }
    if(encontrado==false){
        printf("El legajo solicitado no existe.\n");
    }
    return encontrado;
}

void buscarPorNombre(struct ListaEnlazada *miLista, char nombre[]) {
    struct Nodo *aux;
    bool encontrado=false;
    aux = miLista->inicial;
    printf("Alumnos con nombre %s%s",nombre,":\n");
    while (aux != NULL) {
        if(aux->alumno->nombre==nombre ) {
            encontrado=true,
            printf("%d", aux->valor);
            printf(" %s", aux->alumno->apellido);
            printf(" %s", aux->alumno->nombre);
            printf(" %d", aux->alumno->edad);
            printf("\n");
        }
        aux = aux->siguiente;
    }
    if(encontrado==false){
        printf("No hubo coincidencias.\n");
    }
}

bool listarPorEdad(struct ListaEnlazada *miLista, struct Nodo *nuevo) {
    bool agregado = false;
    if (miLista->inicial == NULL) {
        miLista->inicial = nuevo;
        miLista->cantidadElementos = 1;
        miLista->menor = nuevo->alumno->edad;
        miLista->mayor = nuevo->alumno->edad;
        agregado = true;
    } else {
        if (nuevo->alumno->edad < miLista->inicial->alumno->edad) {
            miLista->menor = nuevo->alumno->edad;
            nuevo->siguiente = miLista->inicial;
            miLista->inicial = nuevo;
            miLista->cantidadElementos++;
            agregado = true;
        }
        struct Nodo *auxSig;
        struct Nodo *auxAnt;
        auxSig = miLista->inicial;
        auxAnt = miLista->inicial;
        while (!agregado && auxSig->siguiente != NULL && nuevo->alumno->edad > auxAnt->alumno->edad) {
            auxAnt = auxSig;
            auxSig = auxSig->siguiente;
            if (nuevo->alumno->edad == auxAnt->alumno->edad) {
                nuevo->siguiente=auxAnt->siguiente;
                auxAnt->siguiente=nuevo;
                agregado = true;
            }
        }
        if (!agregado) {
                if (nuevo->alumno->edad < auxSig->alumno->edad) {
                    auxAnt->siguiente = nuevo;
                    nuevo->siguiente = auxSig;
                } else {
                    auxSig->siguiente = nuevo;
                    miLista->mayor = nuevo->alumno->edad;
                }
                miLista->cantidadElementos++;
        }
    }
    return agregado;
}
