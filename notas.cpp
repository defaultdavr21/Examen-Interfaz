#include "notas.h"
#include "ui_notas.h"

Notas::Notas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notas)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << tr("Nombre") << tr("Nota 1") << tr("Nota 2")<< tr("Nota Final")<< tr("Estado")<< tr("Nota remedial"));
}

Notas::~Notas(){
    delete ui;
}

void Notas::on_actionNuevo_estudiante_triggered(){

    EstudianteForm *estudianteForm = new EstudianteForm(this);
    QDialog dialog;
    dialog.setWindowTitle("Registro");
    dialog.setLayout(new QVBoxLayout);
    dialog.layout()->addWidget(estudianteForm);
    connect(estudianteForm, &EstudianteForm::datosIngresados, this, &Notas::agregarEstudiante);
    if (dialog.exec() == QDialog::Accepted){



    }
}

void Notas::agregarEstudiante(const QString &nombre, int nota1, int nota2){

    nombres.append(nombre);
    notas1.append(nota1);
    notas2.append(nota2);
    qDebug() << "Estudiante agregado:"
             << "Nombre:" << nombre
             << "Nota1:" << nota1
             << "Nota2:" << nota2;   
    cargarTabla();

}

void Notas::cargarTabla(){

    ui->tableWidget->setRowCount(nombres.size());

    for (int i = 0; i < nombres.size(); ++i) {
        QTableWidgetItem *itemNombre = new QTableWidgetItem(nombres[i]);
        QTableWidgetItem *itemNota1 = new QTableWidgetItem(QString::number(notas1[i]));
        QTableWidgetItem *itemNota2 = new QTableWidgetItem(QString::number(notas2[i]));

        float promedio = (notas1[i] + notas2[i]);

        QTableWidgetItem *itemNotaFinal = new QTableWidgetItem(QString::number(promedio));
        QString estado;
        if (promedio >= 70.0) {
            estado = tr("Aprobado");
        } else if (promedio >= 25.0 && promedio < 70.0) {
            estado = tr("Remedial");
            float notaRemedial = (70.0 - 0.4 * promedio) / 0.6;
            QTableWidgetItem *itemNotaRemedial = new QTableWidgetItem(QString::number(notaRemedial));
            ui->tableWidget->setItem(i, 5, itemNotaRemedial);
        } else {
            estado = tr("Reprobado");
        }

        QTableWidgetItem *itemEstado = new QTableWidgetItem(estado);

        ui->tableWidget->setItem(i, 0, itemNombre);
        ui->tableWidget->setItem(i, 1, itemNota1);
        ui->tableWidget->setItem(i, 2, itemNota2);
        ui->tableWidget->setItem(i, 3, itemNotaFinal);
        ui->tableWidget->setItem(i, 4, itemEstado);
    }

    qDebug() << tr("Tabla cargada correctamente.");

}

void Notas::on_actionGuardar_triggered() {
    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar archivo CSV"), QDir::homePath(), tr("Archivos CSV (*.csv)"));

    if (!filePath.isEmpty()) {
        QFile file(filePath);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);

            // Escribir encabezados
            stream << tr("Nombre,Nota 1,Nota 2,Nota Final,Estado,Nota remedial\n");

            for (int i = 0; i < nombres.size(); ++i) {
                float promedio = (notas1[i] + notas2[i]);
                QString estado;
                float notaRemedial = 0.0f;

                if (promedio >= 70.0) {
                    estado = tr("Aprobado");
                } else if (promedio >= 25.0 && promedio < 70.0) {
                    estado = tr("Remedial");
                    notaRemedial = (70.0 - 0.4 * promedio) / 0.6;
                } else {
                    estado = tr("Reprobado");
                }

                // Unir los datos con comas
                QString data = nombres[i] + "," +
                               QString::number(notas1[i]) + "," +
                               QString::number(notas2[i]) + "," +
                               QString::number(promedio) + "," +
                               estado;

                // Si el estado es Remedial, agregar nota remedial al final
                if (estado == tr("Remedial")) {
                    data += "," + QString::number(notaRemedial);
                } else {
                    data += ","; // De lo contrario, dejar el campo vacío
                }

                // Escribir la línea en el archivo
                stream << data << "\n";
            }
            file.close();
        } else {
            QMessageBox::warning(this, tr("Guardar"), tr("No se pudo guardar los datos"));
        }
    }
}


void Notas::on_actionLink_del_repositorio_triggered(){

    QMessageBox::information(this, tr("Repositorio de Notas"), tr("Visita el repositorio en GitHub:"));

    QDesktopServices::openUrl(QUrl("https://github.com/defaultdavr21/Examen-Interfaz"));
}

