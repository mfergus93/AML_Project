//mainwindow.cpp, Team K Virginia Tech, December 7th, 2023
//Accomplishes main window ui, buttons, file IO, CFITSIO parsing, and image display
//Written by Matthew Ferguson

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

#include <QApplication>
#include <fitsio.h>
#include <opencv2/opencv.hpp>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->openFileButton, SIGNAL(clicked()), this, SLOT(onOpenFileButtonClicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::onOpenFileButtonClicked()
{

    //Written by Helmuth Gonzalez
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::homePath(), tr("All Files (*);;Text Files (*.txt);;Images (*.png *.jpg)"));

    //    if (!filePath.isEmpty()) {
    //        // Do something with the selected file path, e.g., display it in a QLabel
    ui->filePathLabel->setText("Selected File: " + filePath);
    //    }

    fitsfile *fptr; // FITS file pointer
    int status = 0; // Status variable

    // Open the FITS file for reading
//    if (fits_open_file(&fptr, "C:/Users/Matt/Desktop/Sample_Fits/M51_Lum.fit", READONLY, &status)) {
//        fits_report_error(stderr, status);
//        return 1;
//    }

    std::string inputString =filePath.toStdString();
    //Written by Helmuth Gonzalez


    //Written by Matthew Ferguson
    if (fits_open_file(&fptr, inputString.c_str(), READONLY, &status)) {
        fits_report_error(stderr, status);
        return 1;
    }

    // Move to the primary HDU
    if (fits_movabs_hdu(fptr, 1, NULL, &status)) {
        fits_report_error(stderr, status);
        fits_close_file(fptr, &status);
        return 1;
    }

    // Read the image data
    long naxes[2];
    if (fits_get_img_size(fptr, 2, naxes, &status)) {
        fits_report_error(stderr, status);
        fits_close_file(fptr, &status);
        return 1;
    }

    std::vector<float> image_data(naxes[0] * naxes[1]);
    if (fits_read_img(fptr, TFLOAT, 1, naxes[0] * naxes[1], NULL, &image_data[0], NULL, &status)) { //TUSHORT TFLOAT
        fits_report_error(stderr, status);
        fits_close_file(fptr, &status);
        return 1;
    }

    //    qDebug()<<image_data;
    qDebug()<<naxes[0];
    qDebug()<<naxes[1];
    // Convert data to a grayscale OpenCV Mat
    cv::Mat grayscale_image(naxes[1], naxes[0], CV_32FC1, image_data.data());
    //Written by Matthew Ferguson

    //Written by Helmuth Gonzalez
    //Normalization Begin
    //Normalization a scrapped bonus feature, not captured in initial requirements

//    cv::normalize(grayscale_image, grayscale_image, 0, 255, cv::NORM_MINMAX);

//    double minVal, maxVal;
//    cv::minMaxLoc(grayscale_image, &minVal, &maxVal);
//    // Scale the pixel values to the range [0, 255]
//    grayscale_image = (grayscale_image - minVal) * (255.0 / (maxVal - minVal));

//    // Convert the data type to CV_8U for display
//    grayscale_image.convertTo(grayscale_image, CV_8U);
    //Written by Helmuth Gonzalez


    ///Normalization End

    //Written by Matthew Ferguson

    // Display the grayscale image using OpenCV
    cv::namedWindow("Grayscale Image", cv::WINDOW_NORMAL);
    cv::imshow("Grayscale Image", grayscale_image);
    cv::waitKey(0);

    // Close the FITS file
    if (fits_close_file(fptr, &status)) {
        fits_report_error(stderr, status);
        return 1;
    }

    return 0;
}

//Written by Matthew Ferguson
