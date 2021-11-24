#include "mystr_onimg.h"
#include <QPainter>

MyStr_onImg::MyStr_onImg(QWidget *parent) : QWidget(parent)
{

}

void MyStr_onImg::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter qp(this);
    draw(&qp);
}

void MyStr_onImg::draw(QPainter *qp)
{
    qp->setPen(QPen( Qt::black, 1, Qt::SolidLine ) );
    qp->fillRect(0,0,width(),height(),Qt::white);
}
