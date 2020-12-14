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
void resizeEvent(QResizeEvent*e);

private slots:
void on_toolButton_Lines_toggled(bool checked);
void on_Button_PenColor_clicked();
void on_Button_BrushColor_clicked();
void on_comboBox_currentTextChanged(const QString &arg1);
void on_toolButton_rectangle_toggled(bool checked);
void on_toolButton_Circles_toggled(bool checked);
void on_pushButton_clicked();
};

#endif // FORM_H
