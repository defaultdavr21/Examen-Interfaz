#include "notas.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[]){

        QApplication a(argc, argv);
        QTranslator traducion;
        QStringList idiomas;
        idiomas << "Inglés" << "Español";
        QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                                                           "Idioma",
                                                           "Seleccione un idioma",
                                                           idiomas);
        if (idiomaSeleccionado == "Inglés"){
            traducion.load(":/Calculadora_fr_FR.qm");
        }
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }
    Notas w;
    w.show();
    return a.exec();
}
