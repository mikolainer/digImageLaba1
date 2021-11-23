#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(double &constanta_i, int &radius_apert_i, double &sigma_pow2_i, QWidget *parent = nullptr);
    ~Form();
    QPushButton* getPushButton_ptr();

public slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
    int*     radius_apert;
    double*  constanta;
    double*  sigma_pow2;
};

#endif // FORM_H
