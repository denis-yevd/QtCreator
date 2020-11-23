#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <qgridlayout.h>
#include <QComboBox>
#include <QLabel>
#include <qpushbutton.h>
#include <QColorDialog>

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
    QStringList lst={"3","3","10","30","50"};
    cmbx->addItems(lst);

    GLWidget *gl=new GLWidget(this);

    QPushButton *button_color=new QPushButton(this);
    button_color->setStyleSheet("background-image: url(:/res/Icons/ColorPicker.png);"
                                "background-repeat:norepeat;"
                                "background-position:center;");
    button_color->setFixedSize(QSize(50,50));

    layout_h->addWidget(label);
    layout_h->addWidget(cmbx);
    layout_h->addWidget(button_color);
    layout_v->addLayout(layout_h);
    layout_v->addWidget(gl);
    this->gl_widget=gl;
    connect(cmbx, SIGNAL(currentTextChanged(const QString)), gl, SLOT(setCurrentText(const QString)));
    connect(button_color, SIGNAL(clicked()), SLOT(ButtonColorClicked()));
    setLayout(layout_v);
}

Form::~Form()
{
    delete ui;
}

void Form::ButtonColorClicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"choose color");
    gl_widget->color_pen=color;
}
