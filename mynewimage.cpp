#include "mynewimage.h"
#include <QPainter>

MyNewImage::MyNewImage(QWidget *parent) : QLabel(parent)
{

}

int MyNewImage::getLine_on_img() const
{
    return line_on_img;
}

void MyNewImage::setLine_on_img(int newLine_on_img)
{
    line_on_img = newLine_on_img;
}

void MyNewImage::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter qp(this);
    qp.drawPixmap(QPoint(0, 0), this->pixmap());

    qp.setPen(QPen(Qt::red, 3, Qt::SolidLine));
    qp.drawLine( 0,
                  line_on_img,
                  width(),
                  line_on_img);
}
