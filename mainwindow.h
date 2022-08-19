#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);
    private slots:
        void handleButton();
    private:
        QPushButton *m_button_1;
        QPushButton *m_button_2;
        QPushButton *m_button_3;
        QPushButton *m_button_4;
};
#endif // MAINWINDOW_H
