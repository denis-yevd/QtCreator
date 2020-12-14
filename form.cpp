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
    this->gl_widget=new GLWidget(this);
    ui->verticalLayout->addWidget(gl_widget);
}

Form::~Form()
{
    delete ui;
}

void Form::on_toolButton_Lines_toggled(bool checked)
{
    if(checked)
    {
        ui->toolButton_rectangle->setChecked(false);
        ui->toolButton_Circles->setChecked(false);
    }
    gl_widget->curv_pressed=checked;
}

void Form::on_Button_PenColor_clicked()
{
    QColor col = QColorDialog::getColor(Qt::white,this,"choose color");
    gl_widget->pen_my.setColor(col);
}

void Form::on_Button_BrushColor_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"choose color");
    gl_widget->brush_my.setColor(color);
}

void Form::on_comboBox_currentTextChanged(const QString &arg1)
{
    gl_widget->pen_my.setWidth(arg1.toInt());
}

void Form::on_toolButton_rectangle_toggled(bool checked)
{
    if(checked)
    {
        ui->toolButton_Lines->setChecked(false);
        ui->toolButton_Circles->setChecked(false);
    }
    gl_widget->rect_pressed=checked;
}

void Form::on_toolButton_Circles_toggled(bool checked)
{
    if(checked)
    {
        gl_widget->circl_pressed=true;
        ui->toolButton_Lines->setChecked(false);
        ui->toolButton_rectangle->setChecked(false);
    }
    gl_widget->circl_pressed=checked;
}

void Form::resizeEvent(QResizeEvent*e)
{
    gl_widget->pix_map=gl_widget->pix_map.scaled(e->size());
}

void Form::on_pushButton_clicked()
{
    gl_widget->pix_map.fill(Qt::black);
    gl_widget->update();
}
