//main.cpp, Team K, Virginia Tech, December 7th, 2023
//Main Routine
//Written by Matthew Ferguson

#include "mainwindow.h"
#include <QApplication>
#include <fitsio.h>
#include <opencv2/opencv.hpp>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create an instance of main window class
    MainWindow mainWindow;

    // Show the main window
    mainWindow.show();

    // Enter the application event loop
    return app.exec();
}

//Written by Matthew Ferguson
