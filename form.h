#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "glwidget.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    GLWidget *gl_widget;

    Ui::Form *ui;

private slots:
void ButtonColorClicked();
};


#endif // FORM_H
