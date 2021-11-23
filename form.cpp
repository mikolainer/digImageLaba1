#include "form.h"
#include "ui_form.h"

Form::Form(double &constanta_i, int &radius_apert_i, double &sigma_pow2_i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    constanta       = &constanta_i;
    radius_apert    = &radius_apert_i;
    sigma_pow2      = &sigma_pow2_i;
    ui->setupUi(this);
    ui->consta->setValue(*constanta);
    ui->radius->setValue(*radius_apert);
    ui->srkva->setValue(*sigma_pow2);
}

Form::~Form()
{
    delete ui;
}

QPushButton *Form::getPushButton_ptr()
{
    return ui->pushButton;
}

void Form::on_pushButton_clicked()
{
    *constanta       = ui->consta->value();
    *radius_apert    = ui->radius->value();
    *sigma_pow2      = ui->srkva->value();
}

