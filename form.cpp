#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <qgridlayout.h>
#include "glwidget.h"
#include <QComboBox>
#include <QLabel>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QVBoxLayout *layout_v=new QVBoxLayout(this);
    QHBoxLayout *layout_h=new QHBoxLayout(this);
    layout_h->setAlignment(Qt::AlignLeft);
    QLabel *label=new QLabel(this);
    label->setText("thickness");
    QComboBox *cmbx=new QComboBox(this);
    QStringList lst={"5","10","30","50","70"};
    cmbx->addItems(lst);

    GLWidget *gl=new GLWidget(this);
    layout_h->addWidget(label);
    layout_h->addWidget(cmbx);
    layout_v->addLayout(layout_h);
    layout_v->addWidget(gl);
    connect(cmbx, SIGNAL(currentTextChanged(const QString)), gl, SLOT(setCurrentText(const QString)));
    setLayout(layout_v);
}

Form::~Form()
{
    delete ui;
    delete painer_my;
}

void Form::setCurrentText(QString text)
{

}
