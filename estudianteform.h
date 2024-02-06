#ifndef ESTUDIANTEFORM_H
#define ESTUDIANTEFORM_H

#include <QWidget>

namespace Ui {
class EstudianteForm;
}

class EstudianteForm : public QWidget
{
    Q_OBJECT

public:
    explicit EstudianteForm(QWidget *parent = nullptr);
    ~EstudianteForm();

private:
    Ui::EstudianteForm *ui;
};

#endif // ESTUDIANTEFORM_H
