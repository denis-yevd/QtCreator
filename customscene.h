#ifndef CUSTOMSCENE_H
#define CUSTOMSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <mainwindow.h>

class CustomScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MainWindow *mw;
    explicit CustomScene(MainWindow *mw);
    ~CustomScene();
    bool pressed=false;
    void DrawCircle(int x, int y);

signals:
    // The signal of transmit the coordinates of the mouse position
    void signalTargetCoordinate(QPointF point);

private:
    // The function, which made tracking the mouse
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);
};

#endif // CUSTOMSCENE_H
