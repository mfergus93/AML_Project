//encoder.cpp, Matthew Ferguson, 11/10/2023
//Abstract encoder implementation

#include "encoder.h"
#include "flip.h"
#include "otp.h"
#include "invert.h"
#include "base.h"

//encoder Factory implementation
Encoder* EncoderFactory::createEncoder(const std::string& type) {
    if (type == "otp") {
        return new OTPCoder();
    } else if (type == "invert") {
        return new InvertCaseCoder();
    } else if (type == "flip") {
        return new FlipCoder();
    } else if (type == "base64") {
        return new Base64Coder();
    } else {
        return nullptr; // handle unknowns
    }
}
