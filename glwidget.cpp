#include "glwidget.h"
#include <qdebug.h>
#include <QBrush>
#include <QPen>

GLWidget::GLWidget(QWidget *parent):QWidget(parent)
{
    setMouseTracking(true);
    setGeometry(0,20,700,500);
    pix_map=QPixmap(700, 500);
    mouse_pressed=false;
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    mouse_pressed=true;
    paint(event->pos());
}

void GLWidget::paintEvent(QPaintEvent *)
{
    paintr.begin(this);
        paintr.drawPixmap(0,0,pix_map);
        paintr.end();
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_pressed=false;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_pressed)
    {
        paint(event->pos());
    }
}

void GLWidget::paint(QPoint point)
{
    paintr.begin(&pix_map);
    paintr.setPen(QPen{Qt::blue, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin});
    paintr.setBrush(Qt::blue);
    paintr.drawEllipse(point.x(), point.y(), 10, 10);
    paintr.end();
    repaint(point.x(),point.y(),10,10);
    //update();
}
