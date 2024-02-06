#include "notas.h"
#include "ui_notas.h"

Notas::Notas(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notas)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);  // Configurar el número de columnas
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Nombre" << "Nota1" << "Nota2");
}

Notas::~Notas()
{
    delete ui;
}

void Notas::on_actionNuevo_estudiante_triggered()
{
    EstudianteForm *estudianteForm = new EstudianteForm(this);
    QDialog dialog;
    dialog.setWindowTitle("Registro");
    dialog.setLayout(new QVBoxLayout);
    dialog.layout()->addWidget(estudianteForm);
    connect(estudianteForm, &EstudianteForm::datosIngresados, this, &Notas::agregarEstudiante);

    if (dialog.exec() == QDialog::Accepted) {

    }
}

void Notas::agregarEstudiante(const QString &nombre, int nota1, int nota2)
{

    nombres.append(nombre);
    notas1.append(nota1);
    notas2.append(nota2);
    qDebug() << "Estudiante agregado:"
             << "Nombre:" << nombre
             << "Nota1:" << nota1
             << "Nota2:" << nota2;

    cargarTabla();

}

void Notas::cargarTabla()
{
    ui->tableWidget->setRowCount(nombres.size());

    for (int i = 0; i < nombres.size(); ++i) {
        QTableWidgetItem *itemNombre = new QTableWidgetItem(nombres[i]);
        QTableWidgetItem *itemNota1 = new QTableWidgetItem(QString::number(notas1[i]));
        QTableWidgetItem *itemNota2 = new QTableWidgetItem(QString::number(notas2[i]));
        ui->tableWidget->setItem(i, 0, itemNombre);
        ui->tableWidget->setItem(i, 1, itemNota1);
        ui->tableWidget->setItem(i, 2, itemNota2);
    }

    qDebug() << tr("Tabla cargada correctamente.");
}




void Notas::on_actionGuardar_triggered(){
    QString filePath = QFileDialog::getSaveFileName(this, tr("Guardar archivo CSV"), "", tr("Archivos CSV (*.csv);;Todos los archivos (*.*)"));

    if (!filePath.isEmpty()) {
        QFile file(filePath);

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);

            for (int i = 0; i < nombres.size(); ++i) {
                stream << nombres[i] << "," << notas1[i] << "," << notas2[i] << "\n";
            }
            file.close();
        } else {
            qDebug() << tr("Error al abrir el archivo para escribir");
        }
    }
}


void Notas::on_actionLink_del_repositorio_triggered(){

    // Crear un cuadro de diálogo
    QMessageBox::information(this, "Repositorio de Notas", "Visita el repositorio en GitHub:");

    // Abrir el enlace en el navegador web
    QDesktopServices::openUrl(QUrl("https://github.com/defaultdavr21/Examen-Interfaz"));

}

