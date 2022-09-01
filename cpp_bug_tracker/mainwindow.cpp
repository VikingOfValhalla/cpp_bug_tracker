#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->insertRow(0);
}


void MainWindow::on_delete_ticket_clicked()
{
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(row);
}

