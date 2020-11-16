#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <qgridlayout.h>
#include "glwidget.h"
#include <QComboBox>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QGridLayout *layout=new QGridLayout ();
    QComboBox *cmbx=new QComboBox(this);
    QStringList lst={"5","10","30","50","70"};
    cmbx->addItems(lst);
    layout->addWidget(cmbx);

    GLWidget *gl=new GLWidget(this);
    layout->addWidget(gl);
    setLayout(layout);
}

Form::~Form()
{
    delete ui;
    delete painer_my;
}
