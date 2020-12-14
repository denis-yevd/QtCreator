#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMouseEvent>
#include <qpainter.h>
class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    QPoint prev_point;
    QPoint start_point;
    QPainter paintr;
    QPainter painter_f;
    QPen pen_my;
    QBrush brush_my;
    QPixmap  pix_map;
    QRect prev_rect;
    QPainterPath path_my;
    bool mouse_pressed;
    bool rect_pressed;
    bool circl_pressed;
    bool curv_pressed;

    GLWidget(QWidget *parent);
    void setRect(QRect r);
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // GLWIDGET_H
