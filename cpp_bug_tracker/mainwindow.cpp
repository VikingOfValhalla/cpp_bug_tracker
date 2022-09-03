#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->save_button->setEnabled(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // disabling free edit
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::return_row_selected()
{
    QModelIndexList indexList = ui->tableWidget->selectionModel()->selectedIndexes(); // creates list of selection
    int row = 0;
    foreach (QModelIndex index, indexList) {
        // assigns row number
        row = index.row();
    }

    return row;
}

void MainWindow::disable_all_buttons()
{
    // disable all buttons
    ui->update_ticket->setEnabled(false);
    ui->delete_ticket->setEnabled(false);
    ui->extract_report->setEnabled(false);
    ui->add_ticket->setEnabled(false);

    // enable save button
    ui->save_button->setEnabled(true);
}

void MainWindow::enable_all_buttons()
{
    // enable all buttons
    ui->update_ticket->setEnabled(true);
    ui->delete_ticket->setEnabled(true);
    ui->extract_report->setEnabled(true);
    ui->add_ticket->setEnabled(true);

    // attachment buttons
    ui->attach_button_1->setEnabled(true);
    ui->attach_button_2->setEnabled(true);
    ui->attach_button_3->setEnabled(true);
    ui->attach_button_4->setEnabled(true);

    // disable save button
    ui->save_button->setEnabled(false);
}

void MainWindow::disable_table_selection()
{
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection); // disabling selection
    ui->tableWidget->setFocusPolicy(Qt::NoFocus); // disabling clicking
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // disabling free edit
}

void MainWindow::on_add_ticket_clicked()
{
    disable_all_buttons();
    ui->tableWidget->insertRow(0); // inserting first row
    ui->tableWidget->selectRow(0); // selecting first row
    disable_table_selection();
    ui->changes_label->setText("Please update ticket above and save to reflect changes.");
}

void MainWindow::check_checkbox_status(int selected_row, int priority)
{
    if (ui->priority_low->isChecked()) {
        ui->tableWidget->setItem(selected_row, priority, new QTableWidgetItem("Low"));
    } else if (ui->priority_medium->isChecked()) {
        ui->tableWidget->setItem(selected_row, priority, new QTableWidgetItem("Medium"));
    } else if (ui->priority_high->isChecked()) {
        ui->tableWidget->setItem(selected_row, priority, new QTableWidgetItem("High"));
    }
}

void MainWindow::on_delete_ticket_clicked()
{
    int selected_row = return_row_selected();
    ui->tableWidget->removeRow(selected_row);
}

void MainWindow::on_save_button_clicked()
{
    // input field column # to populate
    int attachments = 4, description = 3, priority = 2, assignee = 1, due_date = 0;

    int selected_row = return_row_selected();

    // add text from widget to table
    QString desc_data = ui->description_input->toPlainText(); // description input
    ui->tableWidget->setItem(selected_row, description, new QTableWidgetItem(desc_data));

    QString assignee_data = ui->assignee_box->currentText(); // assignee input
    ui->tableWidget->setItem(selected_row, assignee, new QTableWidgetItem(assignee_data));

    QString date_data = ui->due_date->date().toString("MM/dd/yyyy"); // date input
    ui->tableWidget->setItem(selected_row, due_date, new QTableWidgetItem(date_data));

    check_checkbox_status(selected_row, priority); // priority input

    int attachment_data = attachment_links.size();
    std::cout << "Count of Attachments: " << attachment_data << "\n"; // TODO: NEED TO FIX
    ui->tableWidget->setItem(selected_row, attachments, new QTableWidgetItem(QString::number(attachment_data)));

    // remove text instructions
    ui->changes_label->setText("");
    enable_all_buttons();

    ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection); // enabling selection
}

void MainWindow::on_update_ticket_clicked()
{
    disable_all_buttons();
    int selected_row = return_row_selected();
    disable_table_selection();

    // input field column # to populate
    int attachments = 4, description = 3, priority = 2, assignee = 1, due_date = 0;

    // to populate edit fields with current row data
    ui->description_input->setPlainText(ui->tableWidget->item(selected_row, description)->text());
    // ui->priority->setPlainText(ui->tableWidget->item(selected_row, priority)->text()); // TODO: NEED TO FIX
    ui->assignee_box->setCurrentText(ui->tableWidget->item(selected_row, assignee)->text());
    // ui->due_date->setDate(ui->tableWidget->item(selected_row, due_date)->text()); // TODO: NEED TO FIX


}


// attchment buttons
void MainWindow::on_attach_button_1_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open A File", "");
    qDebug().nospace() << "File Name: " << file_name << '\n';
    attachment_links[0] = file_name.toStdString();
    ui->attach_button_1->setEnabled(false);
}

void MainWindow::on_attach_button_2_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open A File", "");
    attachment_links[1] = file_name.toStdString();
    ui->attach_button_2->setEnabled(false);
}

void MainWindow::on_attach_button_3_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open A File", "");
    attachment_links[2] = file_name.toStdString();
    ui->attach_button_3->setEnabled(false);
}

void MainWindow::on_attach_button_4_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open A File", "");
    attachment_links[3] = file_name.toStdString();
    ui->attach_button_4->setEnabled(false);
}

