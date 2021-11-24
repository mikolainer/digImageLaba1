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
    new_image = QImage(src_img_path).convertToFormat(QImage::Format_Grayscale8);

    constanta = 1;
    radius_apert = 1;
    sigma_pow2 = 1;
    gaussian = new QVector<double>;
    setGaussian();

    form = new Form(constanta, radius_apert, sigma_pow2);
    connect(form->getPushButton_ptr(), SIGNAL(clicked()), this, SLOT(renew()));
//    connect(form->getPushButton_ptr(), &QPushButton::clicked, this, &MainWindow::main_proc);
    form->show();

    main_proc(image, new_image);

    image_pix.convertFromImage(new_image);
    ui->label->setPixmap(image_pix);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gaussian;
    delete form;
    if (gaussian)
        delete gaussian;
}

const QString &MainWindow::getSrc_image() const { return src_img_path; }

void MainWindow::setGaussian()
{
    if (gaussian){
        delete gaussian;
        gaussian = new QVector<double>;
    }

    for (int i=0; i < 2*radius_apert+1; ++i){
        for (int j=0; j < 2*radius_apert+1; ++j){
            double h = ( 1 / qSqrt(2*M_PI*sigma_pow2) )
                    * qExp( 0
                            - (
                                (qSqrt(qPow(j-radius_apert, 2) + qPow(i-radius_apert, 2)))
                                / (2 * sigma_pow2)
                              )
                            );
            gaussian->append( h );
        }
    }
}

void MainWindow::main_proc(const QImage &src, QImage &tar)
{
    for (int src_pixel_x = 0; src_pixel_x < src.width(); ++src_pixel_x){
        for (int src_pixel_y = 0; src_pixel_y < src.height(); ++src_pixel_y){
            uint8_t src_z = src.pixel(src_pixel_x,src_pixel_y) & 0xFF;
            uint8_t tar_z = get_tar_z(src_z, QPoint(src_pixel_x, src_pixel_y), src);
            tar.setPixel(src_pixel_x, src_pixel_y, QRgb(0xFF000000 + (tar_z << 16) + (tar_z << 8) + tar_z));
        }
    }
}

void MainWindow::renew()
{
    main_proc(image, new_image);
    image_pix.convertFromImage(new_image);
    ui->label->setPixmap(image_pix);
}

uint8_t MainWindow::get_tar_z(uint8_t src_z, QPoint pos, const QImage &src)
{
    uint8_t tar_z = src_z;
    if ( pos.x() > radius_apert                &&
         pos.y() > radius_apert                &&
         pos.x() < src.width() - radius_apert  &&
         pos.y() < src.height() - radius_apert
        )
    {
        double k = koeff(pos, src);
        uint8_t gaus_z = gauss_svertka(pos, src);
        tar_z = gaus_z - (k * (src_z - gaus_z));
    }
    return tar_z;
}

double MainWindow::koeff(QPoint pos, const QImage &src)
{
    int num_ofPixels_in_apert = qPow(radius_apert*2+1, 2);

    double sr = 0;
    for (int i=0; i < 2*radius_apert+1; ++i){
        for (int j=0; j < 2*radius_apert+1; ++j){
            sr += src.pixel( pos.x() + (i-radius_apert) , pos.y() + (j-radius_apert) ) & 0xFF;
        }
    }
    sr /= static_cast<double>(num_ofPixels_in_apert);

    double sum_pow = 0;
    for (int i=0; i < 2*radius_apert+1; ++i){
        for (int j=0; j < 2*radius_apert+1; ++j){
            sum_pow += qPow((src.pixel( pos.x() + (i-radius_apert) , pos.y() + (j-radius_apert) ) & 0xFF) - sr , 2);
        }
    }

    double z_srednekvadr = qSqrt( sum_pow / num_ofPixels_in_apert );

    double k;
    if ( z_srednekvadr < 1 ){
        k = 1;
    }else{
        k = constanta / z_srednekvadr;
    }

    return k;
}

uint8_t MainWindow::gauss_svertka(QPoint pos, const QImage &src)
{
    uint8_t svertka = 0;
    uint8_t src_z = src.pixel(pos.x(), pos.y()) & 0xFF;
    for (double h : *gaussian){
        svertka += src_z * h;
    }
    return svertka;
}

