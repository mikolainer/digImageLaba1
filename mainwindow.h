#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const QString &getSrc_image() const;

    QVector<double> *getGaussian() const;
    void setGaussian();

    void main_proc( const QImage& src, QImage& tar );
    uint8_t get_tar_z( uint8_t src_z, QPoint pos, const QImage& src );
    uint8_t gauss_svertka(QPoint pos, const QImage& src);
    double koeff(QPoint pos, const QImage& src);

private:
    Ui::MainWindow *ui;
    QString src_img_path;
    QImage image;
    QImage new_image;
    QPixmap image_pix;

    int     radius_apert,
            scale;

    double  constanta,
            sigma_pow2;

    QVector<double> *gaussian;
};
#endif // MAINWINDOW_H
