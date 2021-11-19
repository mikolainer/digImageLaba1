#include "mainwindow.h"
#include "myimage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    MyImage src(QPixmap(w.getSrc_image()));
    src.setWindowTitle("исходное изображение");
    src.show();
    return a.exec();
}
