#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include "paintermy.h"
#include <QMouseEvent>
class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    GLWidget(PainterMy *painter, QWidget *parent);
    PainterMy *painter_my;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // GLWIDGET_H
