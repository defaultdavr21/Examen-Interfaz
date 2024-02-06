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
    const QString &nombre() const;
    int nota1() const;
    int nota2() const;

signals:
    void datosIngresados(const QString& nombre, int nota1, int nota2);

private slots:
    void on_BotonCancelar_released();

    void on_BtonAceptar_released();

private:
    Ui::EstudianteForm *ui;
    QString m_nombre;
    int m_nota1;
    int m_nota2;
};

#endif // ESTUDIANTEFORM_H
