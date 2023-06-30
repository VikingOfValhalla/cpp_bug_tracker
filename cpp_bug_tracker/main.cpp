#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <QString>
#include <string>
#include <QDebug>
#include <QStringList>

void MainWindow::load_saved_data()
{
    // TODO: need to fix
    QString filename="data.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "No data exists "<<filename;
    }else{
        qDebug() << filename<<" found...";
    }

    QString line;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            QStringList list;
            line = stream.readLine();
            list = line.split(",");
            QString desc_data = list[0];
            QString assignee_data = list[1];
            QString date_data = list[2];

            // column positions
            int attachments = 4, description = 3, priority = 2, assignee = 1, due_date = 0;

            // setting data to row
            ui->tableWidget->insertRow(0); // inserting first row
            ui->tableWidget->setItem(0, description, new QTableWidgetItem(desc_data));
            ui->tableWidget->setItem(0, assignee, new QTableWidgetItem(assignee_data));
            ui->tableWidget->setItem(0, due_date, new QTableWidgetItem(date_data));
            ui->tableWidget->setItem(0, priority, new QTableWidgetItem("0"));
            ui->tableWidget->setItem(0, attachments, new QTableWidgetItem("0"));

            qDebug() << list;
        }
    }
    file.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.load_saved_data();
    return a.exec();
}
