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
    m_nombre = ui->txtNombre->text();
    m_nota1 = ui->txtnota1->text().toInt();
    m_nota2 = ui->txtnota2->text().toInt();

    emit datosIngresados(m_nombre, m_nota1, m_nota2);

    this->parentWidget()->close();
}

