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
    curv_pressed=false;
    rect_pressed=false;
    circl_pressed=false;
    pen_my.setColor(Qt::red);
    pen_my.setWidth(3);
    pen_my.setStyle(Qt::PenStyle::SolidLine);
    pen_my.setCapStyle(Qt::PenCapStyle::RoundCap);
    brush_my.setColor(Qt::blue);
    brush_my.setStyle(Qt::SolidPattern);
    pix_map.fill(Qt::white);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    mouse_pressed=true;
    prev_point=event->pos();
    start_point=event->pos();
    if(curv_pressed)
    path_my=QPainterPath(event->pos());
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
        if(rect_pressed)
        {
            paintr.begin(&pix_map);
            paintr.setPen(pen_my);
            paintr.setBrush(brush_my);
            if(!prev_rect.isEmpty())
            {
                paintr.eraseRect(prev_rect);
            }
            QRect rect=QRect(start_point, event->pos());
            rect=rect.normalized();
            prev_rect=rect;
            paintr.drawRect(rect);
            paintr.end();
            update();
        }

        if(curv_pressed)
        {
            paintr.begin(&pix_map);
            paintr.setPen(pen_my);
            path_my.lineTo(event->pos());
            paintr.drawPath(path_my);
            paintr.end();
            update();
        }

        if(circl_pressed)
        {
            paintr.begin(&pix_map);
            paintr.setPen(pen_my);
            paintr.setBrush(brush_my);
            if(!prev_rect.isEmpty())
            {
                paintr.eraseRect(prev_rect);
            }
            QRect rect=QRect(start_point, event->pos());
            rect=rect.normalized();
            prev_rect=rect;
            paintr.drawEllipse(rect);
            paintr.end();
            update();
        }
    }
}
