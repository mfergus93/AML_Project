//pad_key.h, Matthew Ferguson, 11/10/2023
//Pad Key Manager singleton impelementation

#include "pad_key.h"
#include <QDebug>

//Singleton
PadKey PadKey::instance;

PadKey::PadKey() {
    //Default key of empty on class creation
    QString pad_display="";
    std::string pad_key="";
}

PadKey& PadKey::getInstance() {//get singleton
    return instance;
}

void PadKey::setNewPadKey() {

    pad_key.clear();
    pad_display.clear();
    int len = (std::rand()%16+16); //A random number between 16 and 32
    while (pad_key.length()<len){ //create random pads until len is reached
        int rand_pad=(std::rand()%93); //an offset will vary between 0 and 94, the amount of printable chars.
        //        pad_display.append(QString::fromStdString(std::to_string(rand_pad)));

        pad_display.append(QString::number(rand_pad)+", ");
        pad_key += static_cast<char>(rand_pad);


    }
    qDebug() << "Pad_Display Make: " << pad_display;
}

QString PadKey::getDisplayPadKey() const{//get Display Key
    qDebug() << "Pad_Display Get: " << pad_display;
    qDebug() << "Pad Key Get: " << QString::fromStdString(pad_key);
    return pad_display;
}

std::string PadKey::getUsePadKey() const{//get key for OTPCoder objects
    return pad_key;
}
