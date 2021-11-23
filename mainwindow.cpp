#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
//#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    src_img_path = QFileDialog::getOpenFileName(this, "Открыть изображение", "/Images", "Image Files (*.png *.jpg *.bmp)");
    image = QImage(src_img_path).convertToFormat(QImage::Format_Grayscale8);

    constanta = 1;
    radius_apert = 1;
    sigma_pow2 = 1;
    scale = 10;
    setGaussian();

    image_pix.convertFromImage(new_image);
    ui->label->setPixmap(image_pix);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gaussian;
}

const QString &MainWindow::getSrc_image() const { return src_img_path; }

QVector<double>* MainWindow::getGaussian() const{ return gaussian; }

void MainWindow::setGaussian()
{
    if (gaussian){
        delete gaussian;
        gaussian = new QVector<double>;
    }

    for (int i=0; i < 2*radius_apert+1; ++i){
        for (int j=0; j < 2*radius_apert+1; ++j){
            double h = ( scale / qSqrt(2*M_PI*sigma_pow2) )
                    * qExp( 0
                            - (
                                (qPow(j-radius_apert, 2) + qPow(i-radius_apert, 2))
                                / (2 * sigma_pow2)
                              )
                            );
            gaussian->append( h );
        }
    }
}

