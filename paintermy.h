#ifndef PAINTERMY_H
#define PAINTERMY_H

#include <QWidget>
#include <QPen>
#include <QPainter>

class PainterMy
{
public:
    PainterMy();
    void paint(QPainter *painter, QMouseEvent *event);
private:
    QBrush circleBrush;
    QPen circlePen;
};

#endif // PAINTERMY_H
