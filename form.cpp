#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"

Form::Form(MainWindow* main_w, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    main_window = main_w;

    ui->setupUi(this);
    ui->consta->setValue    ( main_window->getConstanta()    );
    ui->radius->setValue    ( main_window->getRadius_apert() );
    ui->srkva->setValue     ( main_window->getSigma_pow2()   );
    ui->line->setValue      ( main_window->getImgLine()      );
    ui->porog->setValue     ( main_window->getPorog() );

    ui->src_img->setMinimumWidth(main_window->getImage().width());
    ui->tar_img->setMinimumWidth(main_window->getNew_image().width());

    ui->src_img->setImage( main_window->getImage_ptr() );
    ui->tar_img->setImage( main_window->getNew_image_ptr() );
    ui->src_img->setLine( ui->line->value() );
    ui->tar_img->setLine( ui->line->value() );
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
    main_window->setPorog       ( ui->porog->value()    );
    ui->src_img->setLine        ( ui->line->value()     );
    ui->tar_img->setLine        ( ui->line->value()     );
}


void Form::on_line_valueChanged(int arg1)
{
    main_window->setImgLine ( arg1 );
    main_window->repaint();
}

