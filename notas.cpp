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
