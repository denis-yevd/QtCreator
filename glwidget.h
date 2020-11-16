#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "paintermy.h"
#include <QMouseEvent>
class GLWidget : public QWidget
{
    Q_OBJECT
public:
    QPoint mouse_pos;
    QPainter paintr;
    QPixmap pix_map;
    bool mouse_pressed;
    GLWidget(QWidget *parent);
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paint(QPoint point);
};

#endif // GLWIDGET_H
