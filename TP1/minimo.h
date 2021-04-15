int minimo(int lista[]){
    int min=lista[0];
    for(int i=1;i<sizeof (lista);i++){
        if(min>lista[i]) {
            min = lista[i];
        }
    }
    return min;
}
