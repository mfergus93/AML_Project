//otp.h, Matthew Ferguson, 11/10/2023
//OTP class implementation

#ifndef OTP_H
#define OTP_H

#include <QObject>
#include <QString>
#include "encoder.h"

//Class to one time pad encode a string
class OTPCoder : public Encoder {

public:
    //Used for key creation

    //One time pad encoding function
    QString encode(const QString & input_qstring) override;

    //One time pad decoding function
    QString decode(const QString & encoded_qstring) override;
};

#endif // OTP_H
