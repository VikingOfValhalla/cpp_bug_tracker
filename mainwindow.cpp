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
}
 
void MainWindow::handleButton()
{
    // change the text
    m_button_1->setText("Example");
    // resize button
    // m_button_1->resize(100,100);
}
