//flip.h, Matthew Ferguson, 11/10/2023
//Flip class implementation

#ifndef FLIP_H
#define FLIP_H
#include <QString>
#include "encoder.h"

//Class to flip encode/decode strings
class FlipCoder : public Encoder {

public:
    // Function to encode a string using flip encoding
    QString encode(const QString & input_qstring) override;

    // Function to decode a string encoded with flip encoding
    QString decode(const QString & encoded_qstring) override;

private:
    //Private function that will flip a single char of an std::string
    char flip_char(char c);
};

#endif // FLIP_H
