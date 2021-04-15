int maximo(int lista[]){
    int max=lista[0];
    for(int i=1;i<sizeof (lista);i++){
        if(lista[i]>max){
            max=lista[i];
        }
    }
    return max;
}