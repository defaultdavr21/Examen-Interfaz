#ifndef NOTAS_H
#define NOTAS_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>
#include <QWidget>

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
    void agregarEstudiante(const QString& nombre, int nota1, int nota2);
    void on_actionGuardar_triggered();

    void on_actionLink_del_repositorio_triggered();

private:
    Ui::Notas *ui;
    void cargarSubVentana(QWidget *ventana);
    EstudianteForm *estudiante;
    QVector<Estudiante> estudiantes;
    QVector<QString> nombres;
        QVector<int> notas1;
        QVector<int> notas2;

};
#endif // NOTAS_H
