int mostrarMenu(){
    int opcion;
    printf("1- Opcion 1.\n");
    printf("2- Opcion 2.\n");
    printf("3- Opcion 3.\n");
    printf("4- Salir.\n");
    printf("Su respuesta: ");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            printf("Bien.\n");
            break;

        case 2:
            printf("Podría ser mejor.\n");
            break;

        case 3:
            printf("Excelente.\n");
            break;

        default:
            break;
    }
    if(opcion>=1 && opcion<4){
        mostrarMenu();
    }
}