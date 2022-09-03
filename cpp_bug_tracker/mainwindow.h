#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <array>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_ticket_clicked();
    void on_delete_ticket_clicked();
    void on_save_button_clicked();
    void on_update_ticket_clicked();

    // attachment buttons
    void on_attach_button_1_clicked();
    void on_attach_button_2_clicked();
    void on_attach_button_3_clicked();
    void on_attach_button_4_clicked();
private:
    Ui::MainWindow *ui;
    void disable_all_buttons();
    void enable_all_buttons();
    int return_row_selected();
    void disable_table_selection();
    void check_checkbox_status(int selected_row, int priority);
    std::array<std::string, 4> attachment_links;

};


#endif // MAINWINDOW_H
