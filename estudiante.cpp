#include "estudiante.h"

Estudiante::Estudiante(const QString& nombre, int nota1, int nota2)
    : nombre(nombre), nota1(nota1), nota2(nota2) {}

QString Estudiante::getNombre() const {
    return nombre;
}

int Estudiante::getNota1() const {
    return nota1;
}

int Estudiante::getNota2() const {
    return nota2;
}
