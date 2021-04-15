float promediar(){
    int cantidadNumeros, ingresado;
    float promedio=0;
    printf("\nCantidad de numeros a promediar: ");
    scanf("%d",&cantidadNumeros);
    for (int i=0;i<cantidadNumeros;i++){
        printf("Ingrese numero: ");
        scanf("%d",&ingresado);
        promedio=promedio+ingresado;
    }
    return promedio/cantidadNumeros;

}
