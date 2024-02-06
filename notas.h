#ifndef NOTAS_H
#define NOTAS_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QMessageBox>
#include <QMdiArea>
#include "estudianteform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Notas; }
QT_END_NAMESPACE

class Notas : public QMainWindow
{
    Q_OBJECT

public:
    Notas(QWidget *parent = nullptr);
    ~Notas();

private slots:
    void on_actionNuevo_estudiante_triggered();

private:
    Ui::Notas *ui;
    void cargarSubVentana(QWidget *ventana);
    EstudianteForm *estudiante;
};
#endif // NOTAS_H