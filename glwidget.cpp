#include "glwidget.h"
#include <qdebug.h>
#include <QBrush>
#include <QPen>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <thread>

GLWidget::GLWidget(QWidget *parent):QOpenGLWidget(parent)
{
    setMouseTracking(true);
    pix_map=QPixmap(parent->width(), parent->height());
    mouse_pressed=false;
    pen_width=3;
    color_pen=Qt::red;
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
        QPen pen=QPen(color_pen);
        pen.setWidth(pen_width);
        pen.setStyle(Qt::PenStyle::SolidLine);
        pen.setCapStyle(Qt::PenCapStyle::RoundCap);
        paintr.setPen(pen);
        paintr.drawLine(prev_point,event->pos());
        paintr.end();
        update();
        prev_point=event->pos();
    }
}

void GLWidget::setCurrentText(const QString &text) //comboBox
{
    pen_width=text.toInt();
}
