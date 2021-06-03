struct Materia {
    int legajo;
    char[35] nombreCompleto;
    Carrera carrera;
    ListaEnlazada materiasAprobadas;
    ListaEnlazada materiasEnCurso;
    ListaEnlazada materiasDesaprobadas;
    double promedio;

};