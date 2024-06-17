//main.cpp, Matthew Ferguson, 11/10/2023
//Main routine

#include "mainwindow.h"
#include <string>
#include <fstream>
#include <iostream>
#include <QtDebug>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

//Boilerplate main routine
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);//create a Qapp
    MainWindow w;//create a MainWindow
//    PadKey & padKey = PadKey::getInstance();
    w.show();//show the window
    return a.exec();
}


