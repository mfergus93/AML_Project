//mainwindow.h, Team K, Virginia Tech, December 7th, 2023
//Main window header file
//Written by Matthew Ferguson

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    int onOpenFileButtonClicked();
};
#endif // MAINWINDOW_H

//Written by Matthew Ferguson
