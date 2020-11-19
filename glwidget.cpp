#include "glwidget.h"
#include <qdebug.h>
#include <QBrush>
#include <QPen>
//#include <thread>

GLWidget::GLWidget(QWidget *parent):QOpenGLWidget(parent)
{
    setMouseTracking(true);
    pix_map=QPixmap(parent->width(), parent->height());
    mouse_pressed=false;
    pen_width=5;
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    mouse_pressed=true;
    prev_point=event->pos();
}

void GLWidget::paintEvent(QPaintEvent *)
{
        painter_f.begin(this);
        painter_f.drawPixmap(0,0,pix_map);
        painter_f.end();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_pressed=false;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_pressed)
    {
        paintr.begin(&pix_map);
        QPen pen=QPen(Qt::red);
        pen.setWidth(pen_width);
        paintr.setPen(pen);
        paintr.drawLine(prev_point,event->pos());
        paintr.end();
        update();
        prev_point=event->pos();
    }
}

void GLWidget::setCurrentText(const QString &text)
{
    pen_width=text.toInt();
}
