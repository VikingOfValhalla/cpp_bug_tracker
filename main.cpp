#include "mainwindow.h"
#include <QApplication>
 
int main(int argc, char *argv[]) 
{
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.resize(480,250);
    mainWindow.show();
    return app.exec();
}
