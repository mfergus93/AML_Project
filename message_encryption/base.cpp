//base.cpp, Matthew Ferguson, 11/10/2023
//Base encoder implementation

#include "base.h"
#include "network_helper.h"
#include "QObject"

//Base encoding function, will accept QString and return QString
QString Base64Coder::encode(const QString & input_qstring) {

    network_helper network_obj;//create network obj
    network_obj.tryHTTPS(QString("https://api.thebase64.com/encode?secret=S3s8ehsNigNr"), input_qstring);//query base encode api
    QEventLoop loop;//await encode reply
    QObject::connect(&network_obj, SIGNAL(responseReceived()), &loop, SLOT(quit()));
    loop.exec();
    QString based=network_obj.getResponse();//store encode response

    return based;
}

QString Base64Coder::decode(const QString & encoded_qstring) {
    network_helper network_obj;//create network obj
    network_obj.tryHTTPS(QString("https://api.thebase64.com/decode?secret=S3s8ehsNigNr"), encoded_qstring);//query base encode api
    QEventLoop loop;//await encode reply
    QObject::connect(&network_obj, SIGNAL(responseReceived()), &loop, SLOT(quit()));
    loop.exec();
    QString based=network_obj.getResponse();//store encode response
    return based;
}
