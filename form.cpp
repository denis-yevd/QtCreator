#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <qgridlayout.h>
#include "glwidget.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QGridLayout *layout=new QGridLayout ();
    GLWidget *gl=new GLWidget (&painer_my, this);
    layout->addWidget(gl);
}

Form::~Form()
{
    delete ui;
}
