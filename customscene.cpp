#include "customscene.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <mainwindow.h>
#include <string>
#include <QDebug>
#include <thread>
#include <future>
using namespace std;

CustomScene::CustomScene(MainWindow *wind) :
    QGraphicsScene()
{
    this->mw=wind;
}

CustomScene::~CustomScene()
{
}

void CustomScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(mw->ui->toolButton_Pipette->isChecked())
    {
        x=event->scenePos().rx();
        y=event->scenePos().ry();

        if(x>0&&y>0&&x<this->width()&&y<this->height())
        {
            QColor color = this->mw->image.pixelColor(x,y);
            QString style=QString("background-color:rgb(%1,%2,%3);").
                    arg(color.red()).
                    arg(color.green()).
                    arg(color.blue());
            this->mw->ui->selectedColor->setStyleSheet(style);
        }
    }
}

void CustomScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->pressed = true;
    QColor col=this->mw->image.pixelColor(event->scenePos().x(),
                                          event->scenePos().y());
    QString style=QString("background-color:rgb(%1,%2,%3);").
            arg(col.red()).
            arg(col.green()).
            arg(col.blue());
    this->mw->ui->selectedColor->setStyleSheet(style);
    this->mw->selectedColor=col;
}

void CustomScene::mouseReleaseEvent ( QGraphicsSceneMouseEvent *event)
{
    this->pressed = false;
    if(mw->ui->toolButton_Pipette->isChecked())
    mw->ui->toolButton_Pipette->setChecked(false);
}
