struct Persona{
    char nombre[25];
    char apellido[25];
    int edad;

};

struct Padre {
    struct Persona datosPropios;
    struct Persona datosHijos[2];
};

struct Persona crearPersona(char nombre[],char apellido[],int edad){
    struct Persona nuevaPersona={nombre,apellido,edad};
    return nuevaPersona;
}