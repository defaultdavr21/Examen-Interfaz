#ifndef NOTAS_H
#define NOTAS_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QMdiArea>
#include <QVector>

#include "estudianteform.h"
#include "estudiante.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Notas; }
QT_END_NAMESPACE

class Notas : public QMainWindow
{
    Q_OBJECT

public:
    Notas(QWidget *parent = nullptr);
    ~Notas();
    void cargarTabla();

private slots:
    void on_actionNuevo_estudiante_triggered();
    void agregarEstudiante(const Estudiante& estudiante);

private:
    Ui::Notas *ui;
    void cargarSubVentana(QWidget *ventana);
    EstudianteForm *estudiante;
    QVector<Estudiante> estudiantes;

};
#endif // NOTAS_H
