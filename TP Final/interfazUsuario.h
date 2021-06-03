int mostrarMenu(ListaEnlazada listaAlumnos, ListaEnlazada listaMaterias) {
    int opcionPrincipal;
    printf("1- Buscar estudiante.\n");
    printf("2- Agregar estudiante.\n");
    printf("3- Eliminar estudiante.\n");
    printf("4- Salir.\n");
    printf("Su respuesta: ");
    scanf("%d", &opcionPrincipal);
    switch (opcionPrincipal) {
        case 1:
            int opcionBusqueda
            printf("1- Buscar nombre y apellido.\n");
            printf("2- Rango de edad.\n");
            printf("Su respuesta: ");
            scanf("%d", &opcionBusqueda);
            switch (opcionBusqueda) {
                case 1:
                    printf("Por nombre y apellido.\n");
                    break;

                case 2:
                    printf("Por rango de edad.\n");
                    break;

                default:
                    break;
            }
            break;

        case 2:
            printf("Nuevo estudiante.\n");
            break;

        case 3:
            printf("Se eliminará estudiante.\n");
            break;

        default:
            break;
    }
    if (opcion >= 1 && opcion < 4) {
        mostrarMenu();
    }
}