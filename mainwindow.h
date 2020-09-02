#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsView>
#include<QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;
    int zoom=10;
    int shadesRande=0;
    int dark_light=100;
    QImage image;
    QImage previousImage;
    QColor selectedColor;
    QColor replaceableColor;
    void setImage(QImage image);

private slots:
    void on_pushButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_pushButton_2_clicked();
    void on_ApplyButton_clicked();
    void on_Slider_Shades_valueChanged(int value);
    void on_Button_undo_clicked();
    void on_Slider_darker_valueChanged(int value);
};
#endif // MAINWINDOW_H


