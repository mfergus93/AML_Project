//flip.cpp, Matthew Ferguson, 11/10/2023
//Flip encoder implementation

#include "flip.h"
#include <QString>

//Flip encoding function, will accept QString and return QString
QString FlipCoder::encode(const QString & input_qstring) {
    //Convert QString to std::string
    std:: string input_string= input_qstring.toStdString();
    //Declare empty string for adding encoded chars
    std::string encoded_string;

    //Iterate through each char and call flip char encoding
    for (char c : input_string) {
        encoded_string += flip_char(c);
    }

    //Return the encoded string as a QString
    QString encoded_qstring = QString::fromStdString(encoded_string);
    return encoded_qstring;
}

QString FlipCoder::decode(const QString & encoded_qstring) {
    return encode(encoded_qstring); // We can decode the string via encode
}

//Helper function to encode a single char
char FlipCoder::flip_char(char c) {
    if (c >= 0x20 && c <= 0x7E) { //Only printable characters are modified
        return static_cast<char>(0x7E - (c - 0x20));//Flip the character
    }
    return c;//Return flipped character
}
