#include "notas.h"
#include "ui_notas.h"

Notas::Notas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notas)
{
    ui->setupUi(this);

}

Notas::~Notas()
{
    delete ui;
}

void Notas::cargarSubVentana(QWidget *ventana)
{
    QMdiArea *mdiArea = new QMdiArea(this);
      setCentralWidget(mdiArea);

      QMdiSubWindow *sub = mdiArea->addSubWindow(ventana);
      sub->show();
}

void Notas::on_actionNuevo_estudiante_triggered(){

    EstudianteForm *w = new EstudianteForm(this);
    cargarSubVentana(w);

}
void Notas::agregarEstudiante(const Estudiante& estudiante){



    estudiantes.append(estudiante);
    cargarTabla();
}

void Notas::cargarTabla(){

    ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(estudiantes.size());

        for (int i = 0; i < estudiantes.size(); ++i) {
            QTableWidgetItem *itemNombre = new QTableWidgetItem(estudiantes[i].getNombre());
            QTableWidgetItem *itemNota = new QTableWidgetItem(QString::number(estudiantes[i].getNota1()));

            ui->tableWidget->setItem(i, 0, itemNombre);
            ui->tableWidget->setItem(i, 1, itemNota);

        }

}


