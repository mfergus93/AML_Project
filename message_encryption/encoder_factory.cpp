#include "encoder_factory.h"

Encoder* EncoderFactory::createEncoder(const std::string& type) {
    if (type == "OTP") {
        return new OTPEncoder();
    } else if (type == "Base64") {
        return new Base64Encoder();
    } else if (type == "Invert") {
        return new InvertEncoder();
    } else if (type == "Flip") {
        return new FlipEncoder();
    } else {
        return nullptr; // Handle unknown types
    }
}
