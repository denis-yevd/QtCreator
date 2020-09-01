#include "mainwindow.h"
#include <QApplication>
#include<customscene.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w= new MainWindow();
    w->show();
    return a.exec();
}
