#ifndef MYSTR_ONIMG_H
#define MYSTR_ONIMG_H

#include <QWidget>

class MyStr_onImg : public QWidget
{
    Q_OBJECT
public:
    explicit MyStr_onImg(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void draw(QPainter *qp);
};

#endif // MYSTR_ONIMG_H
