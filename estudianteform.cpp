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

void EstudianteForm::on_pushButton_released(){

    emit datosIngresados(m_nombre, m_nota1, m_nota2);
    this->parentWidget()->close();
}

