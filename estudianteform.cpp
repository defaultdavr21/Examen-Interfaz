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
