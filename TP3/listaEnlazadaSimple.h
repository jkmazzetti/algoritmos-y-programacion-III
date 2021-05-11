#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListaEnlazada {
    struct Nodo {
        int valor;
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
    } else {
        struct Nodo *aux = malloc(sizeof(struct Nodo));
        aux = miLista->inicial;
        if (nuevo->valor < miLista->inicial->valor) {
            miLista->menor = valor;
            nuevo->siguiente = miLista->inicial;
            miLista->inicial = nuevo;
            existe = true;
        } else {
            while (!existe && aux->siguiente != NULL) {
                if (valor == aux->valor) {
                    existe = true;
                }
                aux = aux->siguiente;
            }
            if (!existe) {
                aux->siguiente = nuevo;
                if (valor < miLista->menor) {
                    miLista->menor = valor;
                }
                if (valor > miLista->mayor) {
                    miLista->mayor = valor;
                }
                miLista->cantidadElementos++;
            }
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
    if (valor < miLista->menor || valor > miLista->mayor) {
        resultado = -false;
    } else {
        struct Nodo *aux = malloc(sizeof(struct Nodo));
        aux = miLista->inicial;
        while (resultado == false && aux->siguiente != NULL) {
            if (aux->valor == valor) {
                resultado = true;
            } else {
                aux = aux->siguiente;
            }
        }

    }
    return resultado;
}

bool eliminarElemento(struct ListaEnlazada *miLista, int valor) {
    bool eliminado = false;
    if (valor >= miLista->menor && valor <= miLista->mayor) {
        if (miLista->inicial->valor == valor) {
            miLista->inicial = miLista->inicial->siguiente;
            eliminado = true;
        } else {
            struct Nodo *auxAnt = malloc(sizeof(struct Nodo));
            struct Nodo *auxSig = malloc(sizeof(struct Nodo));
            auxSig = miLista->inicial;
            while (!eliminado && auxSig->siguiente != NULL) {
                auxAnt = auxSig;
                auxSig = auxSig->siguiente;
                if (valor == auxSig->valor) {
                    auxAnt->siguiente = auxSig->siguiente;
                    auxSig->siguiente = auxAnt->siguiente;
                    eliminado = true;
                }
            }
        }
        miLista->menor = miLista->inicial->valor;
    }
    return eliminado;

}

void interfazUsuario(struct ListaEnlazada *miLista) {
    int opcion;
    printf("Lista enlazada simple.\n1.Agregar elemento.\n0.Terminar.\n");
    scanf("%d", opcion);
    if (opcion != 0) {
        int valor;
        printf("Elemento a agregar: ");
        scanf("%d", valor);
        agregarElemento(miLista, valor);
    }
}
