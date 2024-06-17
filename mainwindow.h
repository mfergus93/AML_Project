//mainwindow.h, Matthew Ferguson, 11/10/2023
//MainWindow class implementation

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE//boilerplate block
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();//boilerplate endblock

private slots:
    void onEncodeButtonClicked();//the encode button
    void onPadButtonClicked();//the generate pad key button

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
