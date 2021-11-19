#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    src_image = QFileDialog::getOpenFileName(this, "Открыть изображение", "/Images", "Image Files (*.png *.jpg *.bmp)");
}

MainWindow::~MainWindow()
{
    delete ui;
}

const QString &MainWindow::getSrc_image() const { return src_image; }

