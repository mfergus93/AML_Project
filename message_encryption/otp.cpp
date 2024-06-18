//otp.cpp, Matthew Ferguson, 11/10/2023
//OTP encoder implementation

#include "otp.h"
#include "pad_key.h"

#include <QString>
#include <sstream>
#include <QDebug>

//One time pad encoding function, accepts and returns QString
QString OTPCoder::encode(const QString & input_qstring) {
    //convert QString to std::string
    std:: string input_string = input_qstring.toStdString();
    //create empty string to store output
    std::string encoded_string;
    const std::string pad_key = PadKey::getInstance().getUsePadKey();
//    pad_key = getUsePadKey();

    //index for traversing pad string
    int i = -1;
    for (char c: input_string){
        i+=1;//increment the index for every character in the input string
        if (c >= 0x20 && c <= 0x7E){//if input is printable

            int pad_value = pad_key[i % pad_key.length()];//obtain the pad offset number using the index and modulus
            int padded_char= pad_value+c;//pad the character

            while (padded_char > 0x7E) {//while the padded_char is greater than the printable range
                padded_char -= 0x5E;//return it to the printable range
            }
            encoded_string += static_cast<char>(padded_char);//return the padded character to the encoded string

        }
        else{
            encoded_string += c;//if the input character was unprintable return it unmodified
        }
    }
    QString encoded_qstring= QString::fromStdString(encoded_string);
    return encoded_qstring;
}

QString OTPCoder::decode(const QString & encoded_qstring) {//The form of this function largely follows the form of the encode function
    std:: string encoded_string = encoded_qstring.toStdString();
    std::string decoded_string;
    const std::string pad_key = PadKey::getInstance().getUsePadKey();
    int j = -1;
    for (char c : encoded_string) {
        j+=1;
        if (c >= 0x20 && c <= 0x7E){

            char pad_value = pad_key[j % pad_key.length()];
            char unpadded_char=c-pad_value;//the only difference is we subtract the char by the pad value to unencode the padded value

            if (unpadded_char < 0x20) {
                unpadded_char += 0x5E;//and we deal with chars overflowing by adding rather than subtracting
            }
            decoded_string += static_cast<char>(unpadded_char);
        }
        else {
            decoded_string +=c;
        }
    }
    QString decoded_qstring = QString::fromStdString(decoded_string);
    return decoded_qstring;
}
