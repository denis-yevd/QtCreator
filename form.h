#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include "paintermy.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
private:
    PainterMy *painer_my;

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

    Ui::Form *ui;

};


#endif // FORM_H
