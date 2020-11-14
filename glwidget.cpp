#include "glwidget.h"
#include <qdebug.h>

GLWidget::GLWidget(PainterMy *painter, QWidget *parent)
    : QOpenGLWidget(parent), painter_my(painter)
{
    setMouseTracking(true);
    setGeometry(0,20,700,500);
    setAutoFillBackground(false);
}

void GLWidget::mousePressEvent(QMouseEvent *event){
    QPainter *painter=new QPainter(this);
    //painter_my->paint(&painter,event);
    //painter->setBrush(Qt::red);
    QPen pen=QPen (Qt::red);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawEllipse(event->x(), event->y(),30,30);
}
