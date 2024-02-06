#include "notas.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Notas w;
    w.show();
    return a.exec();
}
