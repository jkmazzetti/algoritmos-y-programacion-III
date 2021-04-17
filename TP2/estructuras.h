struct Persona{
    char nombre[25];
    char apellido[25];
    int edad;

};

struct Padre {
    struct Persona datosPropios;
    struct Persona datosHijos[2];
};