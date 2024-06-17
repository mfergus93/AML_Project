//invert.cpp, Matthew Ferguson, 11/10/2023
//Invert encoder implementation

#include "invert.h"
#include <QString>

//InvertCase encoding function, will accept QString and return QString
QString InvertCaseCoder::encode(const QString & input_qstring) {
    //Convert QString to std::string
    std:: string input_string= input_qstring.toStdString();
    std::string encoded_string; //Empty string
    for (char c : input_string) {// For each character in the input string
        if (std::isalpha(c)) {
            if (std::isupper(c)) {//Convert the character to upper/lower
                encoded_string += std::tolower(c);
            } else {
                encoded_string += std::toupper(c);
            }
        } else {
            encoded_string += c; // Build the encoded string character by character
        }
    }
    //Convert std::string to Qstring and return
    QString encoded_qstring = QString::fromStdString(encoded_string);
    return encoded_qstring;
}

//InvertCase decoding function, will accept QString and return QString
QString InvertCaseCoder::decode(const QString & encoded_qstring) {
    return encode(encoded_qstring); // Decoding is the same as encoding
}
