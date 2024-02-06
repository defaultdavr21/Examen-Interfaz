#include "estudianteform.h"
#include "ui_estudianteform.h"

EstudianteForm::EstudianteForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EstudianteForm)
{
    ui->setupUi(this);
}

EstudianteForm::~EstudianteForm()
{
    delete ui;
}
const QString &EstudianteForm::nombre() const
{
    return m_nombre;
}

int EstudianteForm::nota1() const
{
    return m_nota1;
}

int EstudianteForm::nota2() const
{
    return m_nota2;
}

void EstudianteForm::on_BotonCancelar_released(){
    this->parentWidget()->close();
}



void EstudianteForm::on_BtonAceptar_released() {


    if (ui->txtNombre->text().isEmpty() || ui->txtnota1->text().isEmpty() || ui->txtnota2->text().isEmpty()) {
        QMessageBox::warning(this, tr("Error"), tr("Por favor complete todos los campos."));
        return;
    }

    int nota1 = ui->txtnota1->text().toInt();
    int nota2 = ui->txtnota2->text().toInt();
    if (nota1 < 0 || nota1 > 50 || nota2 < 0 || nota2 > 50){
        QMessageBox::warning(this, tr("Error"), tr("Las notas deben estar entre 0 y 50."));
        return;
    }

    emit datosIngresados(ui->txtNombre->text(), nota1, nota2);

    this->parentWidget()->close();
}

