#ifndef MYIMAGE_H
#define MYIMAGE_H

#include <QWidget>

namespace Ui {
class MyImage;
}

class MyImage : public QWidget
{
    Q_OBJECT

public:
    explicit MyImage(QPixmap src_image, QWidget *parent = nullptr);
    ~MyImage();

private:
    Ui::MyImage *ui;
};

#endif // MYIMAGE_H
