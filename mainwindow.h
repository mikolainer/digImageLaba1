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
