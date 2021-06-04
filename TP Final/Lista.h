#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListaEnlazada {
    struct Nodo {
        struct Carrera{
            struct ListaEnlazada *materias;
        };
        struct Materia{
            char *nombre;
            int codigo;
            double nota;
        };
        struct Alumno{
            char *nombre;
            char *apellido;
            int edad;
            int legajo;
            double promedio;
            struct ListaEnlazada *materiasAprobadas;
            struct ListaEnlazada *materiasEnCurso;
        };
        int valor;
        struct Alumno *alumno;
        struct Materia *materia;
        struct Nodo *siguiente;
    };
    int cantidadElementos;
    int menor;
    int mayor;
    struct Nodo *inicial;
};

struct Nodo *crearNodo(int valor) {
    struct Nodo *nodo = malloc(sizeof(struct Nodo));
    nodo->valor = valor;
    nodo->siguiente = malloc(sizeof(struct Nodo));
    nodo->siguiente = NULL;
    return nodo;
}

struct ListaEnlazada *crearLista() {
    struct ListaEnlazada *lista = malloc(sizeof(struct ListaEnlazada));
    lista->cantidadElementos = 0;
    lista->mayor = NULL;
    lista->menor = NULL;
    lista->inicial = malloc(sizeof(struct Nodo));
    lista->inicial = NULL;
    return lista;
}

void agregarElemento(struct ListaEnlazada *miLista, int valor) {
    struct Nodo *nuevo = malloc(sizeof(struct Nodo));
    bool existe = false;
    nuevo = crearNodo(valor);
    if (miLista->inicial == NULL) {
        miLista->inicial = nuevo;
        miLista->cantidadElementos = 1;
        miLista->menor = valor;
        miLista->mayor = valor;
    } else if (valor < miLista->inicial->valor) {
        miLista->menor = valor;
        nuevo->siguiente = miLista->inicial;
        miLista->inicial = nuevo;
        miLista->cantidadElementos++;
        existe = true;
    } else {
        struct Nodo *auxSig;
        struct Nodo *auxAnt;
        auxSig = miLista->inicial;
        auxAnt = miLista->inicial;
        while (!existe && auxSig->siguiente != NULL && valor > auxAnt->valor) {
            auxAnt = auxSig;
            auxSig = auxSig->siguiente;
        }
        if (valor == auxAnt->valor) {
            existe = true;
        }
        if (!existe) {
            if (valor < auxSig->valor) {
                auxAnt->siguiente = nuevo;
                nuevo->siguiente = auxSig;
            } else {
                auxSig->siguiente = nuevo;
                miLista->mayor = valor;
            }
            miLista->cantidadElementos++;
        }
    }
}


void mostrar(struct ListaEnlazada *miLista) {
    struct Nodo *aux = malloc(sizeof(struct Nodo));
    aux = miLista->inicial;
    printf("\nLista:");
    while (aux != NULL) {
        printf(" %d", aux->valor);
        aux = aux->siguiente;
    }
}

bool buscarElemento(struct ListaEnlazada *miLista, int valor) {
    bool resultado = false;
    if (valor == miLista->mayor || valor == miLista->menor) {
        resultado = true;
    }else if (valor < miLista->menor || valor > miLista->mayor) {
        resultado = false;
    }else {
        struct Nodo *aux = malloc(sizeof(struct Nodo));
        aux = miLista->inicial;
        while (resultado == false && aux->siguiente != NULL) {
            if (aux->valor == valor) {
                resultado = true;
            }
            aux = aux->siguiente;
        }

    }
    return resultado;
}

bool eliminarElemento(struct ListaEnlazada *miLista, int valor) {
    bool eliminado = false;
    struct Nodo *auxAnt = malloc(sizeof(struct Nodo));
    struct Nodo *auxSig = malloc(sizeof(struct Nodo));
    auxSig = miLista->inicial;
    if (valor >= miLista->menor && valor <= miLista->mayor) {
        if (miLista->inicial->valor == valor) {
            miLista->inicial = miLista->inicial->siguiente;
            miLista->menor = miLista->inicial->valor;
            eliminado = true;
        } else {

            while (!eliminado && auxSig->siguiente != NULL) {
                auxAnt = auxSig;
                auxSig = auxSig->siguiente;

                if (valor == auxSig->valor) {
                    auxAnt->siguiente = auxSig->siguiente;
                    auxSig->siguiente = auxAnt->siguiente;
                    eliminado = true;
                }
                if (valor == miLista->mayor && auxSig->siguiente == NULL) {
                    auxAnt->siguiente = NULL;
                    eliminado = true;
                }
            }
        }
        if (eliminado) {
            miLista->cantidadElementos--;
            miLista->menor = miLista->inicial->valor;
            if (valor == miLista->mayor) {
                miLista->mayor = auxAnt->valor;
            }
        }

    }
    return eliminado;

}


//Agregar elemento nueva version
bool agregarElemetoPorClave(struct ListaEnlazada *miLista, struct Nodo *nuevo) {
    bool existe = false;
    bool agregado=false;
    if (miLista->inicial == NULL) {
        miLista->inicial = nuevo;
        miLista->cantidadElementos = 1;
        miLista->menor = nuevo->valor;
        miLista->mayor = nuevo->valor;
        agregado=true;
    } else {
        if (nuevo->valor < miLista->inicial->valor) {
            miLista->menor = nuevo->valor;
            nuevo->siguiente = miLista->inicial;
            miLista->inicial = nuevo;
            miLista->cantidadElementos++;
            existe = true;
            agregado=true;
        }
        struct Nodo *auxSig;
        struct Nodo *auxAnt;
        auxSig = miLista->inicial;
        auxAnt = miLista->inicial;
        while (!existe && auxSig->siguiente != NULL && nuevo->valor > auxAnt->valor) {
            auxAnt = auxSig;
            auxSig = auxSig->siguiente;
        }
        if (nuevo->valor == auxAnt->valor || nuevo->valor == auxSig->valor) {
            existe = true;
        }
        if (!existe) {
            if (nuevo->valor < auxSig->valor) {
                auxAnt->siguiente = nuevo;
                nuevo->siguiente = auxSig;
            } else {
                auxSig->siguiente = nuevo;
                miLista->mayor = nuevo->valor;
            }
            miLista->cantidadElementos++;
            agregado=true;
        }
    }
    return agregado;
}

struct Nodo *nodoAlumno(struct Alumno *alumno){
    struct Nodo *nuevoNodo=malloc(sizeof (struct Nodo));
    nuevoNodo->alumno=alumno;
    nuevoNodo->materia=NULL;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->valor=alumno->legajo;
    return  nuevoNodo;
}
struct Nodo *nodoMateria(struct Materia *materia){
    struct Nodo *nuevoNodo=malloc(sizeof (struct Nodo));
    nuevoNodo->alumno=NULL;
    nuevoNodo->materia=materia;
    nuevoNodo->siguiente=NULL;
    nuevoNodo->valor=materia->codigo;
    return  nuevoNodo;
}