#include "myimage.h"
#include "ui_myimage.h"

MyImage::MyImage(QPixmap src_image, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyImage)
{
    ui->setupUi(this);
    ui->srcImage->setPixmap(src_image);
}

MyImage::~MyImage()
{
    delete ui;
}
