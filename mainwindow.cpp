//mainwindow.cpp, Matthew Ferguson 11/10/2023
//MainWindow implementation

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "flip.h"
#include "otp.h"
#include "invert.h"
#include "pad_key.h"
#include "composite_encoder.h"
#include "base.h"

MainWindow::MainWindow(QWidget *parent)//Boilerplate
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect the flip button and set its initial text, connect the otp button
    connect(ui->flip_button, &QPushButton::clicked, this, &MainWindow::onEncodeButtonClicked);
    ui->textEdit->setText("THESE are the times that try mens souls.");
    connect(ui->otp_button, &QPushButton::clicked, this, &MainWindow::onPadButtonClicked);

    //Get the key manager object instance key
    PadKey & padKey = PadKey::getInstance();
    padKey.setNewPadKey();
    QString initial_key = padKey.getDisplayPadKey();
    initial_key.chop(2);
    ui->lineEdit->setText(initial_key);

}

std::vector <QString> encoding_routine(const QString &inputText)
{
    // Create individual encoders
    std::shared_ptr<Encoder> compFlipEncoder = std::make_shared<FlipCoder>();
    std::shared_ptr<Encoder> compInvertEncoder = std::make_shared<InvertCaseCoder>();
    std::shared_ptr<Encoder> compOtpEncoder = std::make_shared<OTPCoder>();
    std::shared_ptr<Encoder> compBase64Encoder = std::make_shared<Base64Coder>();

    // Create a composite encoder
    CompositeEncoder compositeEncoder;
//    compositeEncoder.addEncoder(compFlipEncoder, "Flip");
    compositeEncoder.addEncoder(compInvertEncoder, "Invert");
    compositeEncoder.addEncoder(compOtpEncoder, "OTP");
    compositeEncoder.addEncoder(compBase64Encoder, "Based");

    std::vector<std::shared_ptr<Encoder>> encodeVector;

    // Add smart pointers to the vector
    encodeVector.push_back(std::make_shared<FlipCoder>());
    encodeVector.push_back(std::make_shared<InvertCaseCoder>());
    encodeVector.push_back(std::make_shared<OTPCoder>());
    encodeVector.push_back(std::make_shared<Base64Coder>());
    encodeVector.push_back(std::make_shared<CompositeEncoder>(compositeEncoder));

    std::vector<QString> results;

    for (const auto& encoder : encodeVector) {
        QString className;
        QString encodedResult;
        QString decodedResult;

        if (typeid(*encoder) == typeid(CompositeEncoder)) {
            className = "Composite Encoder (";
            CompositeEncoder* compositeEncoder = dynamic_cast<CompositeEncoder*>(encoder.get());

            for (const auto& component : compositeEncoder->getComponents()) {
                className += component.second + ", ";
            }

            // Remove the trailing comma and space
            className.chop(2);
//            className.chop(6);//Remove 'coder'
            className += "):";
        } else {
            // For regular encoders
            QString fullClassName = typeid(*encoder).name();
//            className.chop(6);//Remove 'coder'
            className = fullClassName.mid(fullClassName.lastIndexOf(' ') + 1) + ":";
        }


        encodedResult = encoder->encode(inputText);
        decodedResult = encoder->decode(encodedResult);

        results.push_back(className + " &lt;" + QString::number(encodedResult.length()) + "&gt;[" + encodedResult + "]" + "<br>");
        results.push_back("Decoded: &lt;" + QString::number(decodedResult.length()) + "&gt;[" + decodedResult + "]" + "<br><br>");
    }

    return results;
};

void MainWindow::onPadButtonClicked(){//function for the generate pad key
    PadKey & padKey = PadKey::getInstance();
    padKey.setNewPadKey();//create a new key
    QString new_key = padKey.getDisplayPadKey();//get the key
    new_key.chop(2);
    ui->lineEdit->setText(new_key);//display the key
}

void MainWindow::onEncodeButtonClicked() {
    QString inputText = ui->textEdit->toPlainText();
    std::vector<QString> encodedResults = encoding_routine(inputText);

    QString output_string; // Declare empty output

    int str_len = inputText.length(); // Obtain length as QString
    QString lengthString = QString::number(str_len);
    output_string.append("<b>Input: &lt;" + lengthString + "&gt;[" + inputText + "]</b>" + "<br><br>"); // Build bold 'input' output

    // Iterate through encodedResults vector
    for (const auto &result : encodedResults) {
        //output_string.append("&lt;" + QString::number(result.length()) + "&gt;[" + result + "]<br>"); // Build output for each result
        output_string.append(result);
    }

    ui->textBrowser->setHtml(output_string); // Display built output string
}

MainWindow::~MainWindow()
{
    delete ui;
}
