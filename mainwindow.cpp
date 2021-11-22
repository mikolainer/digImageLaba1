#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    src_img_path = QFileDialog::getOpenFileName(this, "Открыть изображение", "/Images", "Image Files (*.png *.jpg *.bmp)");
    image = QImage(src_img_path);
    new_image = image;
    image_pix.convertFromImage(new_image);
    ui->label->setPixmap(image_pix);

    constanta = 1;
    radius_apert = 3;
    gaussian = new QVector<QVector<double>>;


}

MainWindow::~MainWindow()
{
    delete ui;
    delete gaussian;
}

const QString &MainWindow::getSrc_image() const { return src_img_path; }

QVector<QVector<double> > *MainWindow::getGaussian() const
{
    return gaussian;
}

void MainWindow::setGaussian(QVector<QVector<double> > *newGaussian)
{
    gaussian = newGaussian;
}

