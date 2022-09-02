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


void MainWindow::on_add_ticket_clicked()
{
    QPushButton* button_1 = ui->update_ticket;
    button_1->setEnabled(false);
    QPushButton* button_2 = ui->delete_ticket;
    button_2->setEnabled(false);
    QPushButton* button_3 = ui->extract_report;
    button_3->setEnabled(false);
    QPushButton* button_4 = ui->add_ticket;
    button_4->setEnabled(false);

    ui->tableWidget->insertRow(0); // inserting first row
    ui->tableWidget->selectRow(0); // selecting first row
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection); // disabling selection
    ui->changes_label->setText("Please update ticket above and save to reflect changes.");
}


void MainWindow::on_delete_ticket_clicked()
{
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(row);
}

void MainWindow::on_save_button_clicked()
{


    // input field column # to populate
    int description = 3;
    int priority = 2;
    int assignee = 1;
    int due_date = 0;

    int row = 0;

    // description input
    QString desc_data = ui->description_input->toPlainText();
    ui->tableWidget->setItem(row, description, new QTableWidgetItem(desc_data));

    QString assignee_data = ui->assignee_box->currentText();
    ui->tableWidget->setItem(row, assignee, new QTableWidgetItem(assignee_data));

    // date input
    QString date_data = ui->due_date->date().toString("MM/dd/yyyy");
    ui->tableWidget->setItem(row, due_date, new QTableWidgetItem(date_data));

    // repeat for more columns


    // remove text instructions
    ui->changes_label->setText("");
    QPushButton* button_1 = ui->update_ticket;
    button_1->setEnabled(true);
    QPushButton* button_2 = ui->delete_ticket;
    button_2->setEnabled(true);
    QPushButton* button_3 = ui->extract_report;
    button_3->setEnabled(true);
    QPushButton* button_4 = ui->add_ticket;
    button_4->setEnabled(true);

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); // disabling selection
}
