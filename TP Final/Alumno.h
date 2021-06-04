
struct Alumno *crearAlumno(int legajo, int edad, char *nombre, char *apellido) {
    struct Alumno *alumno = malloc(sizeof(struct Alumno));
    alumno->legajo = legajo;
    alumno->edad = edad;
    alumno->apellido = apellido;
    alumno->nombre = nombre;
    alumno->materiasAprobadas = malloc(sizeof(struct ListaEnlazada));
    alumno->materiasEnCurso = malloc(sizeof(struct ListaEnlazada));
    return alumno;
}

void mostrarAlumnos(int paginado, struct ListaEnlazada *miLista) {
    struct Nodo *aux = malloc(sizeof(struct Nodo));
    aux = miLista->inicial;
    printf("\nLista:");
    int c = 0;
    while (aux != NULL) {

        printf("%s %d", "\n", aux->valor);
        printf(" %s", aux->alumno->apellido);
        printf(" %s", aux->alumno->nombre);
        printf(" %d", aux->alumno->edad);
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

bool listaPorEdad(struct ListaEnlazada *miLista, struct Nodo *nuevo) {
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
}