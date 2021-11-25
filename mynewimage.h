#ifndef MYNEWIMAGE_H
#define MYNEWIMAGE_H

#include <QLabel>
#include <QWidget>

class MyNewImage : public QLabel
{
    Q_OBJECT
public:
    MyNewImage(QWidget *parent = nullptr);

    int getLine_on_img() const;
    void setLine_on_img(int newLine_on_img);

private:
    int line_on_img;
    void paintEvent(QPaintEvent *event);
};

#endif // MYNEWIMAGE_H
