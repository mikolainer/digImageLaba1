#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPushButton>

class MainWindow;

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(MainWindow* main_w = nullptr, QWidget *parent = nullptr);
    ~Form();
    QPushButton* getPushButton_ptr();

public slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    MainWindow* main_window;
};

#endif // FORM_H
