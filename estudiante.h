// estudiante.h
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QString>

class Estudiante {
public:
    Estudiante();
    QString getNombre() const;
    int getNota1() const;
    int getNota2() const;

private:
    QString nombre;
    int nota1;
    int nota2;
};

#endif // ESTUDIANTE_H
