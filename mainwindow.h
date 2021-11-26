#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setGaussian();

    int     getRadius_apert() const;
    void    setRadius_apert(int newRadius_apert);
    double  getConstanta() const;
    void    setConstanta(double newConstanta);
    double  getSigma_pow2() const;
    void    setSigma_pow2(double newSigma_pow2);
    int     getImgLine() const;
    void    setImgLine(int newImgLine);
    QImage *getImage_ptr();
    QImage *getNew_image_ptr();
    double  getPorog() const;
    void    setPorog(double newPorog);

    const QImage &  getImage() const;
    const QImage &  getNew_image() const;
    const QString &getSrc_image() const;

private:
    Ui::MainWindow *ui;
    Form *form;

    QString src_img_path;
    QImage image;
    QImage new_image;
    QPixmap image_pix;

    int     radius_apert;

    double  constanta,
            sigma_pow2,
            porog;

    QVector<double> *gaussian;

    uint8_t get_tar_z( uint8_t src_z, QPoint pos, const QImage& src );
    double gauss_svertka(QPoint pos, const QImage& src);
    double koeff(QPoint pos, const QImage& src);
    void main_proc( const QImage& src, QImage& tar );

private slots:
    void renew();
    void on_action_2_triggered(bool checked);
    void on_action_triggered();
};
#endif // MAINWINDOW_H
