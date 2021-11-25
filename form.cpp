#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"

Form::Form(MainWindow* main_w, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    main_window = main_w;

    ui->setupUi(this);
    ui->consta->setValue    ( main_w->getConstanta()    );
    ui->radius->setValue    ( main_w->getRadius_apert() );
    ui->srkva->setValue     ( main_w->getSigma_pow2()   );

    ui->src_img->setMinimumWidth(main_window->getImage().width());
    ui->tar_img->setMinimumWidth(main_window->getNew_image().width());
}

Form::~Form()
{
    delete ui;
    main_window = nullptr;
}

QPushButton *Form::getPushButton_ptr()
{
    return ui->pushButton;
}

void Form::on_pushButton_clicked()
{
    main_window->setConstanta   ( ui->consta->value()   );
    main_window->setRadius_apert( ui->radius->value()   );
    main_window->setSigma_pow2  ( ui->srkva->value()    );
    main_window->setImgLine     ( ui->line->value()     );
}

