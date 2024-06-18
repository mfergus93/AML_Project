//base.h, Matthew Ferguson, 11/10/2023
//Base64 class implementation

#ifndef BASE_H
#define BASE_H

#include <QString>
#include "encoder.h"

//Class to flip encode/decode strings
class Base64Coder : public Encoder {

public:
    // Function to encode a string using flip encoding
    QString encode(const QString & input_qstring) override;

    // Function to decode a string encoded with flip encoding
    QString decode(const QString & encoded_qstring) override;
};
#endif // FLIP_H
