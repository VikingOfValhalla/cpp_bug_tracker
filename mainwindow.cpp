#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Create button_1, make "this" the parent
    m_button_1 = new QPushButton("Submit Ticket", this);
    m_button_1->setGeometry(QRect(QPoint(20, 20), QSize(200, 50))); // size & loc
    connect(m_button_1, &QPushButton::released, this, &MainWindow::handleButton); // connect to slot

    // Create button_2, make "this" the parent
    m_button_2 = new QPushButton("Delete Ticket", this); // create button
    m_button_2->setGeometry(QRect(QPoint(20, 70), QSize(200, 50))); // size & loc
    connect(m_button_2, &QPushButton::released, this, &MainWindow::handleButton); // connect to slot
    
    // Create button_2, make "this" the parent
    m_button_3 = new QPushButton("Update Ticket", this); // create button
    m_button_3->setGeometry(QRect(QPoint(20, 120), QSize(200, 50))); // size & loc
    connect(m_button_3, &QPushButton::released, this, &MainWindow::handleButton); // connect to slot
    
    // Create button_2, make "this" the parent
    m_button_4 = new QPushButton("Assign Ticket", this); // create button
    m_button_4->setGeometry(QRect(QPoint(20, 170), QSize(200, 50))); // size & loc
    connect(m_button_4, &QPushButton::released, this, &MainWindow::handleButton); // connect to slot


    QTableView *view = new QTableView;
    QStandardItemModel *mod = new QStandardItemModel;
    QStandardItem *it = new QStandardItem(QObject::tr("ID"));
    mod->setHorizontalHeaderItem(0,it);
    QStandardItem *it1 = new QStandardItem(QObject::tr("Name"));
    mod->setHorizontalHeaderItem(1,it1);
    QStandardItem *it2 = new QStandardItem(QObject::tr("City"));
    mod->setHorizontalHeaderItem(2,it2);
    QStandardItem *it3 = new QStandardItem(QObject::tr("Country"));
    mod->setHorizontalHeaderItem(3,it3);
    //and so on

    view->setModel(mod);
    view->show();

}
 
void MainWindow::handleButton()
{
    // change the text
    m_button_1->setText("Example");
    // resize button
    // m_button_1->resize(100,100);
}
