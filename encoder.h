//encoder.h, Matthew Ferguson, 11/10/2023
//Abstract Encoder and Encoder Factory class implementation

#ifndef ENCODER_H
#define ENCODER_H
#include <QString>

class Encoder {//Virtual Encoder Class
public:
    virtual QString encode(const QString & input_qstring) = 0;
    virtual QString decode(const QString & encoded_qstring) = 0;
};

class EncoderFactory {//Encoder Factory Class
public:
    static Encoder* createEncoder(const std::string & type);
};

#endif // ENCODER_HPP
