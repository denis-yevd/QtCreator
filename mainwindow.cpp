#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<customscene.h>
#include<math.h>
#include<QFile>
#include<QFileDialog>
#include<QColorDialog>
#include <QGraphicsPixmapItem>
#include<iostream>
#include<QDebug>
#include <QMessageBox>
#include "form.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui->graphicsView->scene();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QUrl url=QFileDialog::getOpenFileUrl(); // open image
    QString path = url.path();
    QImage image(path);
    this->image=image;
    FitImage();
    ui->statusbar->showMessage("The image has opened.");
}

void MainWindow::setImage(QImage image){
    this->image = image;
    CustomScene * scene = new CustomScene(this);
    QPixmap pixmap=QPixmap::fromImage(image);
    scene->addPixmap(pixmap);
    QGraphicsScene* scn = ui->graphicsView->scene();
    ui->graphicsView->setScene(scene);
    delete scn;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(this->zoom>value)
    {
        ui->graphicsView->scale(0.8,0.8);
        scale*=0.2;
    }
    else
    {
        ui->graphicsView->scale(1.2,1.2);
        scale*=1.2;
    }
    this->zoom=value;
}

void MainWindow::on_pushButton_2_clicked() //color to replace changing
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Choose color");
    QString style = QString("background-color: rgb(%1, %2, %3);").
            arg(color.red()).
            arg(color.green()).
            arg(color.blue());
    ui->frame_ForReplace->setStyleSheet(style);
    this->replaceableColor=color;
}

void MainWindow::on_ApplyButton_clicked() //replace color
{
    if(this->image.isNull())
    {
        QMessageBox msgBox;
        msgBox.setText("Image is not open!");
        msgBox.exec();
        return;
    }
    if(this->selectedColor==nullptr)
    {
        QMessageBox msgBox;
        msgBox.setText("Choose a selected color");
        msgBox.exec();
        return;
    }
    if(this->replaceableColor==nullptr)
    {
        QMessageBox msgBox;
        msgBox.setText("Choose a color for replace");
        msgBox.exec();
        return;
    }
    this->previousImage=this->image;
    int r,g,b, r_diff, g_diff, b_diff;
    int height=this->image.height();
    ui->progressBar->setMaximum(height);

    int R=selectedColor.red();
    int G=selectedColor.green();
    int B=selectedColor.blue();

    int r_new = replaceableColor.red();
    int g_new = replaceableColor.green();
    int b_new = replaceableColor.blue();

    for(int y=1;y<height;y++) // Y
    {
        for(int x=1;x<this->image.width()-2;x++) // X
        {
            QColor col =this->image.pixelColor(x,y);
            r=col.red();
            g=col.green();
            b=col.blue();
            r_diff=std::abs(R-r);
            g_diff=std::abs(G-g);
            b_diff=std::abs(B-b);
            if(r_diff < shadesRande && g_diff < shadesRande && b_diff < shadesRande){
                image.setPixel(x,y,qRgb(r_new,g_new,b_new));
            }
        }
        ui->progressBar->setValue(y);
    }

    setImage(image);
    ui->statusbar->showMessage("Done");
}

void MainWindow::on_Slider_Shades_valueChanged(int value)
{
    ui->label_shadesRange->setNum(value);
    this->shadesRande=value;
}

void MainWindow::on_Button_undo_clicked()
{
    if(previousImage.isNull()==false){
        setImage(previousImage);
    }
    else {
        ui->statusbar->showMessage("Previous state is not exist");
    }
}

void MainWindow::on_Slider_darker_valueChanged(int value)
{
    int c; // 1 - darker; 0 - lighter
    if(value > dark_light) c=1;
    else c=0;
    dark_light=value;

    for(int y=1;y<image.height();y++) // Y
    {
        for(int x=1;x<this->image.width()-2;x++) // X
        {
            QColor col =this->image.pixelColor(x,y);
            if(c==1)
            {
                QColor newColor = col.darker(110);
                image.setPixelColor(x,y,newColor);
            }
            else {
                QColor newColor = col.lighter(110);
                image.setPixelColor(x,y,newColor);
            }
            dark_light=value;
        }
    }
    setImage(image);
}

void MainWindow::FitImage()
{
    int h = this->image.height();
    int w = this->image.width();
    QImage newImage;
    if(h>w) newImage = image.scaledToHeight(ui->graphicsView->height());
    else newImage = image.scaledToWidth(ui->graphicsView->width());
    setImage(newImage);
}

void MainWindow::on_Button_Save_clicked()
{
    if(!image.isNull())
    {
        QString fileName= QFileDialog::getSaveFileName(this,
                                                       QCoreApplication::applicationDirPath(),
                                                       "Save_image.jpg",
                                                       "Image Files (*.png *.jpg *.bmp)");
        if (!fileName.isNull())
        {
            image.save(fileName);
        }
    }
}

void MainWindow::on_actionDraw_image_triggered() //Open new window
{
    Form *f=new Form();
    f->show();
}
