#include "paintermy.h"
#include <QMouseEvent>

PainterMy::PainterMy()
{
    circlePen=QPen(Qt::red);
    circlePen.setWidth(3);
}

void PainterMy::paint(QPainter *painter, QMouseEvent *event)
{
    painter->setPen(circlePen);
    painter->setBrush(Qt::blue);
    painter->drawEllipse(event->x(),event->y(),20,20);
}
