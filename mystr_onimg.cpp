#include "mystr_onimg.h"
#include <QPainter>
#include <QLabel>

MyStr_onImg::MyStr_onImg(QWidget *parent) : QWidget(parent)
{
    image = nullptr;
}

void MyStr_onImg::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter qp(this);
    if (image != nullptr)
        draw(&qp);
}

void MyStr_onImg::draw(QPainter *qp)
{
    qp->setPen(QPen( Qt::black, 1, Qt::SolidLine ) );
    qp->fillRect(0,0,image->width(),height(),Qt::white);

    double remap_i = height() / 255.0;

    for ( int x_onLine = 0; x_onLine < image->width(); ++x_onLine ) {
        qp->drawLine( x_onLine,
                      static_cast<int>( height() - remap_i * static_cast<double>( (image->pixel(x_onLine, line) & 0xFF) ) ),
                      x_onLine,
                      height() );
    }
}

void MyStr_onImg::setLine(int newLine)
{
    line = newLine;
}

void MyStr_onImg::setImage(QImage *newImage)
{
    image = newImage;
}
