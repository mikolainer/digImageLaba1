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
}

MainWindow::~MainWindow()
{
    delete ui;
}

const QString &MainWindow::getSrc_image() const { return src_img_path; }

