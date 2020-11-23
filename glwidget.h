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
    QPainter paintr;
    QPainter painter_f;
    QPixmap  pix_map;
    QColor color_pen;
    bool mouse_pressed;
    int pen_width;

    GLWidget(QWidget *parent);
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

public slots:
    void setCurrentText(const QString &text);
};

#endif // GLWIDGET_H
