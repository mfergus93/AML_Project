//invert.h, Matthew Ferguson, 11/10/2023
//Invert class implementation

#ifndef INVERT_H
#define INVERT_H

#include "encoder.h"
#include <QObject>
#include <QString>

//Class to InvertCase encode strings (upper case chars to lower case and vice versa)
class InvertCaseCoder : public Encoder{

public:

    // Function to encode a string using InvertCase encoding
    QString encode(const QString & input_qstring) override;

    // Function to decode a string encoded with InvertCase encoding
    QString decode(const QString & encoded_qstring) override;

};

#endif // INVERT_H
